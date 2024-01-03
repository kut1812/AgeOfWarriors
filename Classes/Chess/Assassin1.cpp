#include "Assassin1.h"
#include "Scenes/GameScene.h"

USING_NS_CC;

Assassin1* Assassin1::create(int categoryBitmask, int contactBitmask, int collisionBitmask) {
    auto newObject = new Assassin1();
    if (newObject != nullptr && newObject->init(categoryBitmask, contactBitmask, collisionBitmask)) {

        newObject->autorelease();
        return newObject;
    }
    CC_SAFE_DELETE(newObject);
    return nullptr;
}


bool Assassin1::init(int categoryBitmask, int contactBitmask, int collisionBitmask)
{
    if (!Sprite::initWithFile("Demo_character/Assassin1.png"))
    {
        return false;
    }
    _speedChess = 130.0f;
    _healthChess = 2;
    _currentState = "walk";
    _state = "walk";
    auto visibleSize = Director::getInstance()->getVisibleSize();
    AnimationUtils::loadSpriteFrameCache("Animation/", "Assassin1_walk");
    auto aniWalk = AnimationUtils::createAnimation("Assassin1_walk", 99, 0.1f);
    Animate* animate_Walk = Animate::create(aniWalk);
    animateWalk = RepeatForever::create(animate_Walk);

    AnimationUtils::loadSpriteFrameCache("Animation/", "Assassin1_attack");
    auto aniAttack = AnimationUtils::createAnimation("Assassin1_attack", 99, 0.1f);
    Animate* animate_Attack = Animate::create(aniAttack);
    animateAttack = RepeatForever::create(animate_Attack);

    AnimationUtils::loadSpriteFrameCache("Animation/", "Assassin1_die");
    auto aniDie = AnimationUtils::createAnimation("Assassin1_die", 99, 0.1f);
    Animate* animateDie = Animate::create(aniDie);

    animateWalk->retain();
    animateAttack->retain();
    animateDie->retain();

    this->runAction(animateWalk);
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

int Assassin1::getHealth()
{
    return this->_healthChess;
}

void Assassin1::setHealth()
{
    _healthChess -= 1;
    if (_healthChess <= 0 && _parentScene != nullptr) {
        this->removeFromParentAndCleanup(true);
    }
}

void Assassin1::update(float)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();

    if (this->getPositionX() >visibleSize.width*0.9 || getHealth() == 0)
    {
        this->removeFromParentAndCleanup(true);
    }
}
void Assassin1::setParentScene(GameScene* parentScene) {
    _parentScene = parentScene;
}

std::string Assassin1::getState()
{
    return _state;
}

void Assassin1::setState(std::string state)
{
    _state = state;
}
