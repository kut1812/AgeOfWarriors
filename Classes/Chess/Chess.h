#ifndef __CHESS_H__
#define __CHESS_H__

#include "cocos2d.h"
#include "Scenes/GameScene.h"

USING_NS_CC;

class Chess : public Sprite 
{
public:
	virtual bool init();
	std::string getCurrentState(Chess* chess) { return chess->_currentState; }
	void takeDame(Chess* chess);
public:
	int _healthChess;
	int _damageChess;
	std::string _state;
	float _speedChess;
	float _attackSpeed;
	PhysicsBody* chess_Physics;
	RepeatForever* animateWalk;
	RepeatForever* animateAttack;
	Animate* animateDie;
	std::string _currentState;
};

#endif // !__CHESS_H__
