#include "EnemySpawn.h"
#include "Scenes/GameScene.h"
#include "DefineBitmask.h"
#include "Scenes/GameScene.h"
#include "Chess/Base.h"
EnemySpawn* EnemySpawn::create(GameScene* scene)
{
	auto newObject = new EnemySpawn();
	if (newObject != nullptr && newObject->init(scene)) {

		newObject->autorelease();
		return newObject;
	}
	CC_SAFE_DELETE(newObject);
	return nullptr;
}
bool EnemySpawn::init(GameScene* scene) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	_scene = scene;
	soldierCount = 0;
	archerCount = 0;
	isFirstWave = true;
	auto enemyBase =Base::create(DefineBitmask::Enemy, DefineBitmask::Character, DefineBitmask::Character);
	enemyBase->setFlippedX(-1);
	enemyBase->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.45));
	enemyBase->setScale(visibleSize.height / enemyBase->getContentSize().height * 0.2);
	_scene->addChild(enemyBase, 10);
	enemies.push_back(enemyBase);
	this->scheduleUpdate();
	return true;
}

void EnemySpawn::startSpawn() {
	int spawnInterval = 5;
	soldierCount = 0;
	archerCount = 0;
	assassinCount = 0;
	combatantCount = 0;
	spawnTimer = 0;
	_scene->schedule([=](float dt) {
		if (spawnTimer <= 60) {
			if (spawnTimer % (spawnInterval * 2) < spawnInterval) {
				if (soldierCount < 2) {
					this->spawnSoldier1();
					archerCount = 0;
					soldierCount++;
				}
				else if (archerCount < 1) {
					this->spawnArcher1();
					soldierCount = 0;
					archerCount++;
				}
			}
		}
		else {
			if (spawnTimer % (spawnInterval * 2) < spawnInterval) {
				if (soldierCount < 2) {
					this->spawnSoldier1();
					archerCount = 0;
					soldierCount++;
				}
				else if (archerCount < 1) {
					this->spawnArcher1();
					assassinCount = 0;
					archerCount++;
				}
				else if (assassinCount < 1) {
					this->spawnAssassin1();
					combatantCount = 0;
					assassinCount++;
				}
				else if (combatantCount < 1) {
					this->spawnCombatant1();
					soldierCount = 0;
					combatantCount++;
				}
			}
		}

		spawnTimer += 5;
		}, 2.50f, "spawnEnemy");
}


void EnemySpawn::spawnSoldier1()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Soldier1* chess = Soldier1::create(DefineBitmask::Enemy, DefineBitmask::Character, DefineBitmask::Character);
	chess->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.45));
	chess->setParentScene(_scene);
	Vec2 chessPosition = chess->getPosition();
	Vec2 basePosition = Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45);
	float distance = chessPosition.distance(basePosition);
	auto move = MoveTo::create(distance / chess->_speedChess, basePosition);
	chess->runAction(move);
	chess->setScaleX(1);
	this->addChild(chess);
	enemies.push_back(chess);
}

void EnemySpawn::spawnArcher1() {

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Archer1* chess = Archer1::create(DefineBitmask::Enemy, DefineBitmask::Character, DefineBitmask::Character);
	chess->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.45));
	chess->setParentScene(_scene);
	Vec2 chessPosition = chess->getPosition();
	Vec2 basePosition = Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45);
	float distance = chessPosition.distance(basePosition);
	auto move = MoveTo::create(distance / chess->_speedChess, basePosition);
	chess->runAction(move);
	chess->setScaleX(1);
	_scene->addChild(chess);

	enemies.push_back(chess);

}

void EnemySpawn::spawnAssassin1()
{

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Assassin1* chess = Assassin1::create(DefineBitmask::Enemy, DefineBitmask::Character, DefineBitmask::Character);
	chess->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.45));
	chess->setParentScene(_scene);
	Vec2 chessPosition = chess->getPosition();
	Vec2 basePosition = Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45);
	float distance = chessPosition.distance(basePosition);
	auto move = MoveTo::create(distance / chess->_speedChess, basePosition);
	chess->runAction(move);
	chess->setScaleX(1);
	_scene->addChild(chess);

	enemies.push_back(chess);

}

void EnemySpawn::spawnCombatant1()
{

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Combatant1* chess = Combatant1::create(DefineBitmask::Enemy, DefineBitmask::Character, DefineBitmask::Character);
	chess->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.45));
	chess->setParentScene(_scene);
	Vec2 chessPosition = chess->getPosition();
	Vec2 basePosition = Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45);
	float distance = chessPosition.distance(basePosition);
	auto move = MoveTo::create(distance / chess->_speedChess, basePosition);
	chess->runAction(move);
	chess->setScaleX(1);
	_scene->addChild(chess);

	enemies.push_back(chess);

}

void EnemySpawn::setSprites(std::vector<Chess*>& sprites)
{
	_sprites = sprites;
}

void EnemySpawn::setAction() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	std::vector<Chess*> enemiesToRemove;
	bool firstElement = true;
	for (auto& chess : enemies) {
		if (firstElement) {
			firstElement = false;
			continue; 
		}
		if (chess->_state == "walk") {
			if (chess->_currentState!="walk") {
					chess->stopAllActions();
					chess->runAction(chess->animateWalk->clone());
					Vec2 chessPosition = chess->getPosition();
					Vec2 basePosition = Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45);
					float distance = chessPosition.distance(basePosition);
					auto move = MoveTo::create(distance/chess->_speedChess,basePosition);
					chess->runAction(move);
					chess->_currentState = "walk";
			}
		}
		else if (chess->_state == "attack") {
			if (chess->_currentState != "attack")
			{
				chess->stopAllActions();
				chess->runAction(chess->animateAttack->clone());
				chess->_currentState = "attack";
			}
		}
		else if (chess->_state == "die") {
			chess->stopAllActions();
			chess->runAction(chess->animateDie->clone());
			enemiesToRemove.push_back(chess);
		}
	}

	for (auto& enemyToRemove : enemiesToRemove) {
		auto it = std::find(enemies.begin(), enemies.end(), enemyToRemove);
		if (it != enemies.end()) {
			enemies.erase(it);
		}
	}
}


void EnemySpawn::update(float dt)
{
	this->setAction();
}


