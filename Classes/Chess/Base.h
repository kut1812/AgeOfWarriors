#ifndef __BASE_H__
#define __BASE_H__

#include "cocos2d.h"
#include "Chess.h"
#include "Utilities/AnimationUtils.h"

USING_NS_CC;

class GameScene;
class Base : public Chess
{
public:
	static Base* create(int categoryBitmask, int contactBitmask, int collisionBitmask);
	virtual bool init(int categoryBitmask, int contactBitmask, int collisionBitmask);
};

#endif // !__BASE_H__
