#ifndef __ASSASSIN1_H__
#define __ASSASSIN1_H__

#include "cocos2d.h"
#include "Chess.h"
#include "Utilities/AnimationUtils.h"
USING_NS_CC;

class GameScene;
class Assassin1 : public Sprite
{
public:
	static Assassin1* create(int categoryBitmask, int contactBitmask, int collisionBitmask);
	virtual bool init(int categoryBitmask, int contactBitmask, int collisionBitmask);

	PhysicsBody* chess_Assassin1_Physics;

	int _healthChess;

	int getHealth();
	void setHealth();
	void update(float);
	void setParentScene(GameScene* parentScene);

private:
	GameScene* _parentScene;
};

#endif // !__ASSASSIN1_H__
