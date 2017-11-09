#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Character.h"
#include <string>
#include <sstream>

class Potion;

class player: public Character{
protected:
    std::string type, race, oldTile;
    int hp, atk, def, gold, row, col, level;
    int tempAtk, tempDef;
    
public:
    player(const std::string &race, const int &hp, const int &atk, const int &def, const int &gold);
    virtual ~player();
    
    std::string getType() const;
    std::string getRace() const;
    std::string getOldTile() const;
    int get_hp() const;
    int get_atk() const;
    int get_def() const;
    int get_gold() const;
    int get_row() const;
    int get_col() const;
    int get_level() const;
    
    void attack (Character* defender);
    void attackby (Character* attacker);
    void goToNewFloor ();
    void change_level();
    void change_hp (const int &value) = 0;
    void change_atk(const int &value) = 0;
    void change_def(const int &value) = 0;
    void change_gold(const int &value) = 0;
    void steal_gold () = 0;
    void setPos(const int &row, const int &col);
    void change_OldTile(const std::string &newTile);
    void move(const std::string &direction);
    void Take_Potion (Potion *p);
};

#endif // PLAYER_H_INCLUDED
