#include "EnemySpawn.h"
#include "Scenes/GameScene.h"
#include "DefineBitmask.h"
#include "Scenes/GameScene.h"
bool EnemySpawn::init(GameScene* scene) {
    _scene = scene;
    _spawnedCount = 0;
    _isSpawning = false;
    return true;
}

void EnemySpawn::startSpawn(float delayBetweenSpawns, int totalSpawns) {
    if (!_isSpawning) {
        _isSpawning = true;
        _delayBetweenSpawns = delayBetweenSpawns;
        _totalSpawns = totalSpawns;
    }
}

void EnemySpawn::stopSpawn() {
    _isSpawning = false;
}

void EnemySpawn::spawnSoldier1()
{
    if (_scene && _spawnedCount < _totalSpawns) {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Soldier1* chess = Soldier1::create(DefineBitmask::Character, DefineBitmask::Enemy, DefineBitmask::Enemy);
        chess->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.45));
        chess->setParentScene(_scene);
        auto move = MoveBy::create(20.f, Vec2(-visibleSize.width, 0));

        chess->runAction(move);
        chess->setScaleX(1);
        _scene->addChild(chess);
        _spawnedCount++;
        enemies.push_back(chess);
    }
    else
    {
        return;
    }
}

void EnemySpawn::spawnArcher1() {
    if (_scene && _spawnedCount < _totalSpawns) {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Archer1* chess = Archer1::create(DefineBitmask::Character, DefineBitmask::Enemy, DefineBitmask::Enemy);
        chess->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.45));
        chess->setParentScene(_scene);
        auto move = MoveBy::create(20.f, Vec2(-visibleSize.width, 0));
      
        chess->runAction(move);
        chess->setScaleX(1);
        _scene->addChild(chess);
        _spawnedCount++;
        enemies.push_back(chess);
    }
    else
    {
        return;
    }
}

void EnemySpawn::spawnAssassin1()
{
    if (_scene && _spawnedCount < _totalSpawns) {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Assassin1* chess = Assassin1::create(DefineBitmask::Character, DefineBitmask::Enemy, DefineBitmask::Enemy);
        chess->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.45));
        chess->setParentScene(_scene);
        auto move = MoveBy::create(20.f, Vec2(-visibleSize.width, 0));

        chess->runAction(move);
        chess->setScaleX(1);
        _scene->addChild(chess);
        _spawnedCount++;
        enemies.push_back(chess);
    }
    else
    {
        return;
    }
}

void EnemySpawn::spawnCombatant1()
{
    if (_scene && _spawnedCount < _totalSpawns) {
        auto visibleSize = Director::getInstance()->getVisibleSize();
        Combatant1* chess = Combatant1::create(DefineBitmask::Character, DefineBitmask::Enemy, DefineBitmask::Enemy);
        chess->setPosition(Vec2(visibleSize.width * 0.9, visibleSize.height * 0.45));
        chess->setParentScene(_scene);
        auto move = MoveBy::create(20.f, Vec2(-visibleSize.width, 0));

        chess->runAction(move);
        chess->setScaleX(1);
        _scene->addChild(chess);
        _spawnedCount++;
        enemies.push_back(chess);
    }
    else
    {
        return;
    }
}


