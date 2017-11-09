#ifndef ORC_H
#define ORC_H

#include "enemy.h"

class Orc : public enemy
{
    bool hostile;
public:
    /** Default constructor */
    Orc();
    /** Default destructor */
    ~Orc();
    void attack (Character *defender);
    void attackby (Character * attacker);
    bool is_hostile () const;
};
#endif // ORC_H
