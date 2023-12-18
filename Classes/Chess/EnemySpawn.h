#ifndef __ENEMY_SPAWN_H__
#define __ENEMY_SPAWN_H__

#include "cocos2d.h"
#include "Chess/Soldier1.h"
#include "Chess/Archer1.h"
#include "Chess/Assassin1.h"
#include "Chess/Combatant1.h"
USING_NS_CC;
class GameScene;
class EnemySpawn : Node {
public:
    bool init(GameScene* scene); 
    void startSpawn(float delayBetweenSpawns, int totalSpawns); 
    void stopSpawn(); 
    void spawnSoldier1();
    void spawnArcher1();
    void spawnAssassin1();
    void spawnCombatant1();
    float _delayBetweenSpawns;
private:
    GameScene* _scene;
    int _spawnedCount;
    int _totalSpawns;
    bool _isSpawning;
    std::vector<Sprite*> enemies;
};

#endif // !__ENEMY_SPAWN_H__
