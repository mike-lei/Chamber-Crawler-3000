#ifndef HUMAN_H
#define HUMAN_H

#include "enemy.h"

class Human : public enemy
{
    bool hostile;
public:
    /** Default constructor */
    Human();
    /** Default destructor */
    ~Human();
    void attack (Character *defender);
    void attackby (Character * attacker);
    bool is_hostile () const;
};
#endif // HUMAN_H
