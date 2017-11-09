#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include "CellObject.h"
#include <string>

class Character: public CellObject{
public:
    Character();
    virtual ~Character();
    virtual void move(const std::string &direction) = 0;
    virtual std::string getRace() const = 0;
    virtual std::string getType() const = 0;
    
    virtual void change_hp (const int &value) = 0;
    virtual void change_atk(const int &value) = 0;
    virtual void change_def(const int &value) = 0;
    virtual void change_gold(const int &value) = 0;
    virtual void steal_gold() = 0;
    
    virtual void attack (Character* defender) = 0;
    virtual void attackby(Character* attacker) = 0;
    virtual int get_hp() const = 0;
    virtual int get_atk() const = 0;
    virtual int get_def() const = 0;
    virtual int get_gold() const = 0;
    virtual int get_row() const = 0;
    virtual int get_col() const = 0;
    };

#endif // CHARACTER_H_INCLUDED
