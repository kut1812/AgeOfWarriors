#ifndef __CHESS_SPAWN_H__
#define __CHESS_SPAWN_H__

#include "cocos2d.h"
#include "Chess/Chess.h"
#include "Chess/Soldier1.h"
#include "Chess/Archer1.h"
#include "Chess/Assassin1.h"
#include "Chess/Combatant1.h"
USING_NS_CC;
class GameScene;
class ChessSpawn : public Node {
public:
    static ChessSpawn* create(GameScene* scene);
    bool init(GameScene* scene); 
    void spawnSoldier1();
    void spawnArcher1();
    void spawnAssassin1();
    void spawnCombatant1();
    std::vector<Chess*> characters;
    void setSprites(std::vector<Chess*>& sprites);
    void setAction();
    void update(float dt);
private:
    Sprite* findNearestTarget(std::vector<Chess*>& sprites);
    float calculateDistance(Sprite* otherSprite);
    GameScene* _scene;
    std::vector<Chess*> _sprites;
};

#endif // !__CHESS_SPAWN_H__
