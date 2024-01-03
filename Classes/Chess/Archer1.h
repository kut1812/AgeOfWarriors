#ifndef __ARCHER1_H__
#define __ARCHER1_H__

#include "cocos2d.h"
#include "Chess.h"
#include "Utilities/AnimationUtils.h"

USING_NS_CC;

class GameScene;
class Archer1 : public Chess
{
public:
	static Archer1* create(int categoryBitmask, int contactBitmask, int collisionBitmask);
	virtual bool init(int categoryBitmask, int contactBitmask, int collisionBitmask);
	int getHealth();
	void setHealth();
	virtual std::string getState() ;
	virtual void setState(std::string state) ;
	void update(float);
	void setParentScene(GameScene* parentScene);
private:
	GameScene* _parentScene;
};

#endif // !__ARCHER1_H__
