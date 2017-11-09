#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "player.h"

class vampire : public player{
public:
    vampire();
    ~vampire();
    void change_hp (const int &value) override;
    void change_atk(const int &value) override;
    void change_def(const int &value) override;
    void change_gold(const int &value) override;
    void steal_gold() override;
};

#endif // VAMPIRE_H
