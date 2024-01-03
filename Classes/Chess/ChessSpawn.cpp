#include "ChessSpawn.h"
#include "Scenes/GameScene.h"
#include "DefineBitmask.h"
#include "Scenes/GameScene.h"
#include "Chess/Base.h"

ChessSpawn* ChessSpawn::create(GameScene* scene)
{
	auto newObject = new ChessSpawn();
	if (newObject != nullptr && newObject->init(scene)) {

		newObject->autorelease();
		return newObject;
	}
	CC_SAFE_DELETE(newObject);
	return nullptr;
}

bool ChessSpawn::init(GameScene* scene) {
	_scene = scene;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	auto yourBase = Base::create(DefineBitmask::Character, DefineBitmask::Enemy, DefineBitmask::Enemy);
	yourBase->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45));
	yourBase->setScale(visibleSize.height / yourBase->getContentSize().height * 0.2);
	_scene->addChild(yourBase, 10);
	characters.push_back(yourBase);
	this->scheduleUpdate();
	return true;
}

void ChessSpawn::spawnSoldier1()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Soldier1* chess = Soldier1::create(DefineBitmask::Character, DefineBitmask::Enemy, DefineBitmask::Enemy);
	chess->setParentScene(_scene);
	chess->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45));
	auto move = MoveBy::create(visibleSize.width/chess->_speedChess, Vec2(visibleSize.width, 0));
	chess->runAction(move);
	_scene->addChild(chess);
	characters.push_back(chess);
}

void ChessSpawn::spawnArcher1() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Archer1* chess = Archer1::create(DefineBitmask::Character, DefineBitmask::Enemy, DefineBitmask::Enemy);
	chess->setParentScene(_scene);
	chess->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45));
	auto move = MoveBy::create(visibleSize.width / chess->_speedChess, Vec2(visibleSize.width, 0));
	chess->runAction(move);
	_scene->addChild(chess);
	characters.push_back(chess);
}

void ChessSpawn::spawnAssassin1()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Assassin1* chess = Assassin1::create(DefineBitmask::Character, DefineBitmask::Enemy, DefineBitmask::Enemy);
	chess->setParentScene(_scene);
	chess->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45));
	auto move = MoveBy::create(visibleSize.width / chess->_speedChess, Vec2(visibleSize.width, 0));
	chess->runAction(move);
	_scene->addChild(chess);
	characters.push_back(chess);
}

void ChessSpawn::spawnCombatant1()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Combatant1* chess = Combatant1::create(DefineBitmask::Character, DefineBitmask::Enemy, DefineBitmask::Enemy);
	chess->setParentScene(_scene);
	chess->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45));
	auto move = MoveBy::create(visibleSize.width / chess->_speedChess, Vec2(visibleSize.width, 0));
	chess->runAction(move);
	_scene->addChild(chess);
	characters.push_back(chess);
}


void ChessSpawn::setSprites(std::vector<Chess*>& sprites)
{
	_sprites = sprites;
}

Sprite* ChessSpawn::findNearestTarget(std::vector<Chess*>& sprites)
{
	Sprite* nearestTarget = nullptr;

	float minDistance = std::numeric_limits<float>::max();
	for (auto& sprite : sprites) {
		float dist = calculateDistance(sprite);
		if (dist < minDistance) {
			minDistance = dist;
			nearestTarget = sprite;
		}
	}

	return nearestTarget;
}

float ChessSpawn::calculateDistance(Sprite* otherSprite) {
	if (otherSprite) {
		auto Position = this->getPosition();
		auto otherSpritePosition = otherSprite->getPosition();
		float distance = Position.distance(otherSpritePosition);
		return distance;
	}
	return std::numeric_limits<float>::max();
}


void ChessSpawn::setAction() {
	bool firstElement = true;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	std::vector<Chess*> enemiesToRemove;
	for (auto& chess : characters) {
		if (firstElement) {
			firstElement = false;
			continue; 
		}
		if (chess->_state == "walk") {
			if (chess->_currentState != "walk") {
				chess->stopAllActions();
				chess->runAction(chess->animateWalk->clone());
				Vec2 chessPosition = chess->getPosition();
				Vec2 basePosition = Vec2(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.45));
				float distance = chessPosition.distance(basePosition);
				auto move = MoveTo::create(distance / chess->_speedChess, basePosition);
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
		auto it = std::find(characters.begin(), characters.end(), enemyToRemove);
		if (it != characters.end()) {
			characters.erase(it);
		}
	}
}


void ChessSpawn::update(float dt)
{
	this->setAction();
}
