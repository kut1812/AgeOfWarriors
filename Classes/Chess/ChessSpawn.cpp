#include "ChessSpawn.h"
#include "Scenes/GameScene.h"
#include "DefineBitmask.h"
#include "Scenes/GameScene.h"

bool ChessSpawn::init(GameScene* scene) {
	_scene = scene;
	return true;
}

void ChessSpawn::spawnSoldier1()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Soldier1* chess = Soldier1::create(DefineBitmask::Character, DefineBitmask::Enemy, DefineBitmask::Enemy);
	chess->setParentScene(_scene);


	chess->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45));
	auto move = MoveBy::create(60.0f, Vec2(visibleSize.width, 0));
	chess->runAction(move);
	_scene->addChild(chess);
	characters.push_back(chess);
}

void ChessSpawn::spawnArcher1() {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Archer1* chess = Archer1::create(DefineBitmask::Character, DefineBitmask::Enemy, DefineBitmask::Enemy);
	chess->setParentScene(_scene);
	chess->setPosition(Vec2(visibleSize.width * 0.1, visibleSize.height * 0.45));
	auto move = MoveBy::create(60.0f, Vec2(visibleSize.width, 0));
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
	auto move = MoveBy::create(60.0f, Vec2(visibleSize.width, 0));
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
	auto move = MoveBy::create(60.0f, Vec2(visibleSize.width, 0));
	chess->runAction(move);
	_scene->addChild(chess);
	characters.push_back(chess);
}


