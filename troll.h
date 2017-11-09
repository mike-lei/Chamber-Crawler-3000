#ifndef TROLL_H
#define TROLL_H

#include "player.h"

class troll : public player{
public:
    troll();
    ~troll();
    void change_hp (const int &value) override;
    void change_atk(const int &value) override;
    void change_def(const int &value) override;
    void change_gold(const int &value) override;
    void steal_gold() override;
};

#endif // TROLL_H
