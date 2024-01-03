#ifndef __ENEMY_SPAWN_H__
#define __ENEMY_SPAWN_H__

#include "cocos2d.h"
#include "Chess/Chess.h"
#include "Chess/Soldier1.h"
#include "Chess/Archer1.h"
#include "Chess/Assassin1.h"
#include "Chess/Combatant1.h"

USING_NS_CC;

class GameScene;
class EnemySpawn : public Node
{
public:
	static EnemySpawn* create(GameScene* scene);
	virtual bool init(GameScene* scene);
	void startSpawn();
	std::vector<Chess*> enemies;
	void setSprites(std::vector<Chess*>& sprites);
	void setAction();
	void update(float dt);
private:
	void spawnSoldier1();
	void spawnArcher1();
	void spawnAssassin1();
	void spawnCombatant1();
	int soldierCount;
	int archerCount;
	int assassinCount;
	int combatantCount;
	int spawnTimer;
	bool isFirstWave;
	GameScene* _scene;
	std::vector<Chess*> _sprites;
	/*RepeatForever* animateWalk;
	RepeatForever* animateAttack;
	RepeatForever* animateDie;*/
};

#endif // !__ENEMY_SPAWN_H__
