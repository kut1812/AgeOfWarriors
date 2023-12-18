#include "Soldier1.h"
#include "Scenes/GameScene.h"
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
    auto visibleSize = Director::getInstance()->getVisibleSize();
    AnimationUtils::loadSpriteFrameCache("Animation/", "Soldier1_walk");
    auto ani = AnimationUtils::createAnimation("Soldier1_walk",40, 0.05f);
    Animate* animate = Animate::create(ani);
    this->runAction(RepeatForever::create(animate));
    this->setScaleX(-1);

    chess_Soldider1_Physics = PhysicsBody::createBox(this->getContentSize());
    chess_Soldider1_Physics->setDynamic(false);
    chess_Soldider1_Physics->setCategoryBitmask(categoryBitmask);
    chess_Soldider1_Physics->setContactTestBitmask(contactBitmask);
    chess_Soldider1_Physics->setCollisionBitmask(collisionBitmask);
    this->addComponent(chess_Soldider1_Physics);
    this->scheduleUpdate();

    return true;
}

int Soldier1::getHealth()
{
    return this->_healthChess;
}

void Soldier1::setHealth()
{
    _healthChess -= 1;
    if (_healthChess <= 0 && _parentScene != nullptr) {
        this->removeFromParentAndCleanup(true);
    }
}

void Soldier1::update(float)
{
    log("%lf", _position.x);
    auto visibleSize = Director::getInstance()->getVisibleSize();

    if (this->getPositionX() > visibleSize.width  || getHealth() == 0)
    {
        this->removeFromParentAndCleanup(true);
    }
}
void Soldier1::setParentScene(GameScene* parentScene) {
    _parentScene = parentScene;
}
