#ifndef DROW_H
#define DROW_H

#include "player.h"

class drow : public player{
public:
    drow();
    ~drow();
    void change_hp (const int &value) override;
    void change_atk(const int &value) override;
    void change_def(const int &value) override;
    void change_gold(const int &value) override;
    void steal_gold() override;
};

#endif // DROW_H
