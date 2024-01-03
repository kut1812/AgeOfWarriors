#include "Combatant1.h"
#include "Scenes/GameScene.h"

USING_NS_CC;

Combatant1* Combatant1::create(int categoryBitmask, int contactBitmask, int collisionBitmask) {
    auto newObject = new Combatant1();
    if (newObject != nullptr && newObject->init(categoryBitmask, contactBitmask, collisionBitmask)) {

        newObject->autorelease();
        return newObject;
    }
    CC_SAFE_DELETE(newObject);
    return nullptr;
}


bool Combatant1::init(int categoryBitmask, int contactBitmask, int collisionBitmask)
{
    if (!Sprite::initWithFile("Demo_character/Combatant1.png"))
    {
        return false;
    }
    _healthChess = 2;
    _speedChess = 100.0f;
    _currentState = "walk";
    _state = "walk";
    auto visibleSize = Director::getInstance()->getVisibleSize();
    AnimationUtils::loadSpriteFrameCache("Animation/", "Combatant1_walk");
    auto aniWalk = AnimationUtils::createAnimation("Combatant1_walk", 99, 0.1f);
    Animate* animate_Walk = Animate::create(aniWalk);
    animateWalk = RepeatForever::create(animate_Walk);

    AnimationUtils::loadSpriteFrameCache("Animation/", "Combatant1_attack");
    auto aniAttack = AnimationUtils::createAnimation("Combatant1_attack", 99, 0.1f);
    Animate* animate_Attack = Animate::create(aniAttack);
    animateAttack = RepeatForever::create(animate_Attack);

    AnimationUtils::loadSpriteFrameCache("Animation/", "Combatant1_die");
    auto aniDie = AnimationUtils::createAnimation("Combatant1_die", 99, 0.1f);
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

int Combatant1::getHealth()
{
    return this->_healthChess;
}

void Combatant1::setHealth()
{
    _healthChess -= 1;
    if (_healthChess <= 0 && _parentScene != nullptr) {
        this->removeFromParentAndCleanup(true);
    }
}

void Combatant1::update(float)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();

    if (this->getPositionX() > visibleSize.width * 0.9 || getHealth() == 0)
    {
        this->removeFromParentAndCleanup(true);
    }
}
void Combatant1::setParentScene(GameScene* parentScene) {
    _parentScene = parentScene;
}


std::string Combatant1::getState()
{
    return _state;
}

void Combatant1::setState(std::string state)
{
    _state = state;
}
