#ifndef GOBLIN_H
#define GOBLIN_H

#include "player.h"

class goblin : public player{
public:
    goblin();
    ~goblin();
    void change_hp (const int &value) override;
    void change_atk(const int &value) override;
    void change_def(const int &value) override;
    void change_gold(const int &value) override;
    void steal_gold() override;
};

#endif // GOBLIN_H
