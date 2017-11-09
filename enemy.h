#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <iostream>
#include <sstream>
#include <string>

class Treasure;

class enemy : public Character
{
protected:
    std::string race, type;
    int hp, atk, def, row, col;
public:
    enemy(const std::string &race, const std::string &type, const int &hp, const int &atk,
          const int &def, const int &row, const int &col);
    ~enemy();
    
    int get_hp() const;
    int get_atk() const;
    int get_def() const;
    int get_gold() const;
    int get_row() const;
    int get_col() const;
    std::string getRace() const;
    std::string getType() const;
    virtual bool is_hostile() const = 0;
    
    void attack (Character * defender) = 0;
    void attackby (Character* attacker) = 0;
    void change_hp (const int &value);
    void change_atk (const int &value);
    void change_def (const int &value);
    void change_gold (const int &value);
    void steal_gold();
    
    void updatepos (const int &, const int &);
    void move (const std::string &direction);
};

#endif // ENEMY_H
