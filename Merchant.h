#ifndef MERCHANT_H
#define MERCHANT_H

#include "enemy.h"


class Merchant : public enemy
{
    static bool hostile;
public:
    /** Default constructor */
    Merchant();
    /** Default destructor */
    ~Merchant();
    void attack (Character *defender);
    void attackby (Character * attacker);
    bool is_hostile()const;

};

#endif // MERCHANT_H
