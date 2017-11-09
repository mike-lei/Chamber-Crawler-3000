#ifndef SHADE_H_INCLUDED
#define SHADE_H_INCLUDED

#include "player.h"

class shade : public player{
public:
    shade();
    ~shade();
    void change_hp (const int &value) override;
    void change_atk(const int &value) override;
    void change_def(const int &value) override;
    void change_gold(const int &value) override;
    void steal_gold() override;
};

#endif // SHADE_H_INCLUDED
