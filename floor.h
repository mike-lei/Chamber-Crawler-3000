#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <map>
#include "MakeFloor.h"
#include "MakeCharacter.h"
#include "MakeItem.h"

class cell;
class Chamber;
class ChamberVal;
class player;
class TextDisplay;

class floor {
    int row, col;
    player *pc;
    TextDisplay *td;
    bool NewFloor;
    bool defaultMap;
    std::string DefaultMapName;
    MakeFloor *FloorFactory;
    MakeCharacter *CharacterFactory;
    MakeItem *ItemFactory;
    std::vector <Chamber*> chamber;
    std::vector <std::vector <cell>> grid;
    
public:
    floor();
    ~floor();
    bool isEmptyMap() const;
    bool Won() const;
    cell *getRandomCell(const std::string &type);
    void init(const std::string &mapName);
    void clear();
    void CreateChamber();
    void DragonGuardDragonHoard ();
    void addToChamber(const int &, const int &);
    void SpawnPlayer(const std::string &);
    void SpawnStair(const std::string &);
    void SpawnPotion(const std::string &);
    void SpawnGold(const std::string &);
    void SpawnEnemy();
    void Enemy_move(bool &);
    void pc_usePotion (const std::string &input);
    void move_pc(const std::string &input);
    void pc_attack(const std::string &input);
    
    std::map <std::string, cell*> get_dir_cell(const int &curRow, const int &curCol);
    TextDisplay* getTd() const;
    player * getPlayer() const;
};

std::ostream &operator<<(std::ostream &out, const floor &floor);
#endif
