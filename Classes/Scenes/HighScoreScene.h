#ifndef  __HIGH_SCORE_SCENE_H__
#define  __HIGH_SCORE_SCENE_H__

#include "cocos2d.h"

class HighScoreScene :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(HighScoreScene);
};
#endif // __HIGH_SCORE_SCENE_H__

