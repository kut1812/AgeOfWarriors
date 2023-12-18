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
    _healthChess = 2;
    auto visibleSize = Director::getInstance()->getVisibleSize();
    AnimationUtils::loadSpriteFrameCache("Animation/", "Assassin1_walk");
    auto ani = AnimationUtils::createAnimation("Assassin1_walk",21, 0.1f);
    Animate* animate = Animate::create(ani);
    this->runAction(RepeatForever::create(animate));
    this->setScaleX(-1);

    chess_Assassin1_Physics = PhysicsBody::createBox(this->getContentSize());
    chess_Assassin1_Physics->setDynamic(false);
    chess_Assassin1_Physics->setCategoryBitmask(categoryBitmask);
    chess_Assassin1_Physics->setContactTestBitmask(contactBitmask);
    chess_Assassin1_Physics->setCollisionBitmask(collisionBitmask);
    this->addComponent(chess_Assassin1_Physics);
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
    log("%lf", _position.x);
    auto visibleSize = Director::getInstance()->getVisibleSize();

    if (this->getPositionX() >visibleSize.width*0.9 || getHealth() == 0)
    {
        this->removeFromParentAndCleanup(true);
    }
}
void Assassin1::setParentScene(GameScene* parentScene) {
    _parentScene = parentScene;
}
