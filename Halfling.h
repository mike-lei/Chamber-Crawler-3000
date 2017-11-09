#ifndef HALFLING_H
#define HALFLING_H

#include "enemy.h"

class Halfling : public enemy
{
    bool hostile;
public:
    /** Default constructor */
    Halfling();
    /** Default destructor */
    ~Halfling();
    void attack (Character *defender);
    void attackby (Character * attacker);
    bool is_hostile () const;
};

#endif // HALFLING_H
