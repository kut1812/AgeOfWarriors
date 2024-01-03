#include "Soldier1.h"
#include "Scenes/GameScene.h"
#include "DefineBitmask.h"
USING_NS_CC;


Soldier1* Soldier1::create(int categoryBitmask,int contactBitmask, int collisionBitmask) {
    auto newObject = new Soldier1();
    if (newObject != nullptr &&  newObject->init(categoryBitmask, contactBitmask, collisionBitmask)) {

        newObject->autorelease();
        return newObject;
    }
    CC_SAFE_DELETE(newObject);
    return nullptr;
}

bool Soldier1::init(int categoryBitmask, int contactBitmask, int collisionBitmask)
{
    if (!Sprite::initWithFile("Demo_character/Soldier1.png"))
    {
        return false;
    }
    _healthChess = 2;
    _speedChess = 100.0f;
    _state = "walk";
    _currentState = "walk";
    _attackSpeed = 1.5f;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    AnimationUtils::loadSpriteFrameCache("Animation/", "Soldier1_walk");
    auto aniWalk = AnimationUtils::createAnimation("Soldier1_walk", 0.1f);
    aniWalk.first->setDelayPerUnit(1.0f/aniWalk.second);
    Animate* animate_Walk = Animate::create(aniWalk.first);
    animateWalk = RepeatForever::create(animate_Walk);

    AnimationUtils::loadSpriteFrameCache("Animation/", "Soldier1_attack");
    auto aniAttack = AnimationUtils::createAnimation("Soldier1_attack", 99, 0.1f);
    Animate* animate_Attack = Animate::create(aniAttack);
    animateAttack = RepeatForever::create(animate_Attack);

    AnimationUtils::loadSpriteFrameCache("Animation/", "Soldier1_die");
    auto aniDie = AnimationUtils::createAnimation("Soldier1_die", 99, 0.1f);
    Animate* animateDie = Animate::create(aniDie);

    animateWalk->retain();
    animateAttack->retain();
    animateDie->retain();

    animateWalk->setTag(DefineBitmask::Walk);
    animateAttack->setTag(DefineBitmask::Attack);
    animateDie->setTag(DefineBitmask::Die);

    this->runAction(animateWalk->clone());
    this->setScaleX(-1);

    chess_Physics = PhysicsBody::createBox(this->getContentSize());
    chess_Physics->setDynamic(false);
    chess_Physics->setCategoryBitmask(categoryBitmask);
    chess_Physics->setContactTestBitmask(contactBitmask);
    chess_Physics->setCollisionBitmask(collisionBitmask);
    this->addComponent(chess_Physics);
    this->scheduleUpdate();

    return true;
}

int Soldier1::getHealth()
{
    return this->_healthChess;
}

void Soldier1::setHealth(int dame)
{
    _healthChess -= dame;
    if (_healthChess <= 0 && _parentScene != nullptr) {
        this->removeFromParentAndCleanup(true);
    }
}

void Soldier1::update(float)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();

    if (this->getPositionX() > visibleSize.width  || getHealth() == 0)
    {
        this->removeFromParentAndCleanup(true);
    }
}
void Soldier1::setParentScene(GameScene* parentScene) {
    _parentScene = parentScene;
}

std::string Soldier1::getState()
{
    return _state;
}

void Soldier1::setState(std::string state)
{
    _state = state;
}
