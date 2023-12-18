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
    auto visibleSize = Director::getInstance()->getVisibleSize();
    AnimationUtils::loadSpriteFrameCache("Animation/", "Archer1_walk");
    auto ani = AnimationUtils::createAnimation("Archer1_walk",15, 0.1f);
    Animate* animate = Animate::create(ani);
    this->runAction(RepeatForever::create(animate));
   
    this->setScaleX(-1);

    chess_Archer1_Physics = PhysicsBody::createBox(this->getContentSize());
    chess_Archer1_Physics->setDynamic(false);
    chess_Archer1_Physics->setCategoryBitmask(categoryBitmask);
    chess_Archer1_Physics->setContactTestBitmask(contactBitmask);
    chess_Archer1_Physics->setCollisionBitmask(collisionBitmask);
    this->addComponent(chess_Archer1_Physics);
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

void Archer1::update(float)
{
    log("%lf", _position.x);
    auto visibleSize = Director::getInstance()->getVisibleSize();

    if (this->getPositionX() >visibleSize.width*0.9 || getHealth() == 0)
    {
        this->removeFromParentAndCleanup(true);
    }
}
void Archer1::setParentScene(GameScene* parentScene) {
    _parentScene = parentScene;
}
