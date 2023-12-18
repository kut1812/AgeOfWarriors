#ifndef __CHESS_H__
#define __CHESS_H__

#include "cocos2d.h"
#include "Scenes/GameScene.h"
USING_NS_CC;

class Chess : public Sprite 
{
public:
	virtual int getHealth() = 0;
	virtual void setHealth() = 0;
protected:
	int _healthChess;
};

#endif // !__CHESS_H__
