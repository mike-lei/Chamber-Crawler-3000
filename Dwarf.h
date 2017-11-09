#ifndef DWARF_H
#define DWARF_H

#include "enemy.h"

class Dwarf : public enemy
{
    bool hostile;
public:
    /** Default constructor */
    Dwarf();
    /** Default destructor */
    ~Dwarf();
    void attack (Character *defender);
    void attackby (Character * attacker);
    bool is_hostile () const;

};
#endif // DWARF_H
