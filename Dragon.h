#ifndef DRAGON_H
#define DRAGON_H

#include "enemy.h"

class DragonHoard;

class Dragon : public enemy
{
    bool hostile;
    DragonHoard *dh;
public:
    /** Default constructor */
    Dragon();
    /** Default destructor */
    ~Dragon();
    void attack (Character *defender);
    void attackby (Character * attacker);
    void guardTreasure (DragonHoard *dh);
    DragonHoard *getDragonHoard ();
    bool is_hostile () const;
    
};

#endif // DRAGON_H
