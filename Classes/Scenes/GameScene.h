#ifndef  __GAME_SCENE_H__
#define  __GAME_SCENE_H__

#include "ui/CocosGUI.h"
#include "cocos2d.h"
#include "Map/GameMap.h"

class ChessSpawn;
class EnemySpawn;
class GameScene :public cocos2d::Scene
{
public:
	bool init() override;
	bool OnTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	bool OnContactBegan(cocos2d::PhysicsContact& contact);
	CREATE_FUNC(GameScene);
protected:
	ChessSpawn* characterSpawn;
	EnemySpawn* enemy;
	Layer* layer;
	//Soldier1* chess;
	float _moveSpeed;
	GameMap* _gameMap;
protected:
	void update(float dt) override;
	void updateSpawn(float dt);
};
#endif // __GAME_SCENE_H__

