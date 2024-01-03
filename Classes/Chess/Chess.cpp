#include "Chess.h"
#include "Scenes/GameScene.h"
USING_NS_CC;

bool Chess::init()
{
    if (!Sprite::init())
    {
        return false;
    }
}

void Chess::takeDame(Chess* chess)
{
    this->_healthChess-=chess->_damageChess;
    if (this->_healthChess<=0)
    {
        this->removeAllChildrenWithCleanup(true);
    }
}
