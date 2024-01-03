#ifndef __ASSASSIN1_H__
#define __ASSASSIN1_H__

#include "cocos2d.h"
#include "Chess.h"
#include "Utilities/AnimationUtils.h"
USING_NS_CC;

class GameScene;
class Assassin1 : public Chess
{
public:
	static Assassin1* create(int categoryBitmask, int contactBitmask, int collisionBitmask);
	virtual bool init(int categoryBitmask, int contactBitmask, int collisionBitmask);
	virtual std::string getState();
	virtual void setState(std::string state);
	int getHealth();
	void setHealth();
	void update(float);
	void setParentScene(GameScene* parentScene);

private:
	GameScene* _parentScene;
};

#endif // !__ASSASSIN1_H__
