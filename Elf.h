#ifndef ELF_H
#define ELF_H

#include "enemy.h"

class Elf : public enemy
{
    bool hostile;
public:
    /** Default constructor */
    Elf();
    /** Default destructor */
    ~Elf();
    void attack (Character *defender);
    void attackby (Character * attacker);
    bool is_hostile () const;
};

#endif // ELF_H
