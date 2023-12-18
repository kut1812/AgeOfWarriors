#ifndef __ARCHER1_H__
#define __ARCHER1_H__

#include "cocos2d.h"
#include "Chess.h"
#include "Utilities/AnimationUtils.h"
USING_NS_CC;

class GameScene;
class Archer1 : public Sprite
{
public:
	static Archer1* create(int categoryBitmask, int contactBitmask, int collisionBitmask);
	virtual bool init(int categoryBitmask, int contactBitmask, int collisionBitmask);

	PhysicsBody* chess_Archer1_Physics;

	int _healthChess;

	int getHealth();
	void setHealth();
	void update(float);
	void setParentScene(GameScene* parentScene);

private:
	GameScene* _parentScene;
};

#endif // !__ARCHER1_H__
