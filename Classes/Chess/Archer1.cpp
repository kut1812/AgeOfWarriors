#include "Archer1.h"
#include "Scenes/GameScene.h"

USING_NS_CC;

Archer1* Archer1::create(int categoryBitmask, int contactBitmask, int collisionBitmask) {
    auto newObject = new Archer1();
    if (newObject != nullptr && newObject->init(categoryBitmask, contactBitmask, collisionBitmask)) {

        newObject->autorelease();
        return newObject;
    }
    CC_SAFE_DELETE(newObject);
    return nullptr;
}

bool Archer1::init(int categoryBitmask, int contactBitmask, int collisionBitmask)
{
    if (!Sprite::initWithFile("Demo_character/Archer1.png"))
    {
        return false;
    }
    _healthChess = 2;
    _speedChess = 80.0f;
    _currentState = "walk";
    _state = "walk";
    auto visibleSize = Director::getInstance()->getVisibleSize();
    AnimationUtils::loadSpriteFrameCache("Animation/", "Archer1_walk");
    auto aniWalk = AnimationUtils::createAnimation("Archer1_walk", 99, 0.1f);
    Animate* animate_Walk = Animate::create(aniWalk);
    animateWalk=RepeatForever::create(animate_Walk);
    
    AnimationUtils::loadSpriteFrameCache("Animation/", "Archer1_attack");
    auto aniAttack = AnimationUtils::createAnimation("Archer1_attack", 99, 0.1f);
    Animate* animate_Attack = Animate::create(aniAttack);
    animateAttack=RepeatForever::create(animate_Attack);
    
    AnimationUtils::loadSpriteFrameCache("Animation/", "Archer1_die");
    auto aniDie = AnimationUtils::createAnimation("Archer1_die", 99, 0.1f);
    animateDie = Animate::create(aniDie);
    
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

int Archer1::getHealth()
{
    return this->_healthChess;
}

void Archer1::setHealth()
{
    _healthChess -= 1;
    if (_healthChess <= 0 && _parentScene != nullptr) {
        this->removeFromParentAndCleanup(true);
    }
}

std::string Archer1::getState()
{
    return _state;
}

void Archer1::setState(std::string state)
{
    _state = state;
}


void Archer1::update(float)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();

    if (this->getPositionX() >visibleSize.width*0.9 || getHealth() == 0)
    {
        this->removeFromParentAndCleanup(true);
    }
}
void Archer1::setParentScene(GameScene* parentScene) {
    _parentScene = parentScene;
}
