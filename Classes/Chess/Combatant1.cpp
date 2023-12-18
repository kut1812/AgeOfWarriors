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
    auto visibleSize = Director::getInstance()->getVisibleSize();
    AnimationUtils::loadSpriteFrameCache("Animation/", "Combatant1_walk");
    auto ani = AnimationUtils::createAnimation("Combatant1_walk",40, 0.05f);
    Animate* animate = Animate::create(ani);
    this->runAction(RepeatForever::create(animate));
   
    this->setScaleX(-1);

    chess_Combatant1_Physics = PhysicsBody::createBox(this->getContentSize());
    chess_Combatant1_Physics->setDynamic(false);
    chess_Combatant1_Physics->setCategoryBitmask(categoryBitmask);
    chess_Combatant1_Physics->setContactTestBitmask(contactBitmask);
    chess_Combatant1_Physics->setCollisionBitmask(collisionBitmask);
    this->addComponent(chess_Combatant1_Physics);
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
    log("%lf", _position.x);
    auto visibleSize = Director::getInstance()->getVisibleSize();

    if (this->getPositionX() > visibleSize.width * 0.9 || getHealth() == 0)
    {
        this->removeFromParentAndCleanup(true);
    }
}
void Combatant1::setParentScene(GameScene* parentScene) {
    _parentScene = parentScene;
}
