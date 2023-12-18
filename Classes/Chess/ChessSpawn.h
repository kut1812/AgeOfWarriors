#ifndef __CHESS_SPAWN_H__
#define __CHESS_SPAWN_H__

#include "cocos2d.h"
#include "Chess/Soldier1.h"
#include "Chess/Archer1.h"
#include "Chess/Assassin1.h"
#include "Chess/Combatant1.h"
USING_NS_CC;
class GameScene;
class ChessSpawn : Node {
public:
    bool init(GameScene* scene); 
    void spawnSoldier1();
    void spawnArcher1();
    void spawnAssassin1();
    void spawnCombatant1();
private:
    GameScene* _scene;
    std::vector<Sprite*> characters;
};

#endif // !__CHESS_SPAWN_H__
