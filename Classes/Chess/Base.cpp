#include "Base.h"
#include "Scenes/GameScene.h"

USING_NS_CC;

Base* Base::create(int categoryBitmask, int contactBitmask, int collisionBitmask) {
    auto newObject = new Base();
    if (newObject != nullptr && newObject->init(categoryBitmask, contactBitmask, collisionBitmask)) {

        newObject->autorelease();
        return newObject;
    }
    CC_SAFE_DELETE(newObject);
    return nullptr;
}

bool Base::init(int categoryBitmask, int contactBitmask, int collisionBitmask)
{
    if (!Sprite::initWithFile("Barrack/Lvl1_ori.png"))
    {
        return false;
    }

    chess_Physics = PhysicsBody::createBox(this->getContentSize());
    chess_Physics->setDynamic(false);
    chess_Physics->setCategoryBitmask(categoryBitmask);
    chess_Physics->setContactTestBitmask(contactBitmask);
    chess_Physics->setCollisionBitmask(collisionBitmask);
    this->addComponent(chess_Physics);
    return true;
}

