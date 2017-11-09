#include "drow.h"
#include <math.h>
using namespace std;

const int drow_max_hp = 120;
const int drow_atk = 25;
const int drow_def = 15;
const float drow_potion_bonus = 1.5;

drow::drow(): player("Drow", drow_max_hp, drow_atk, drow_def, 0) {}

drow::~drow()
{
    //dtor
}

void drow::change_hp(const int &value) {
    int tempHp = ceil (hp + (value * drow_potion_bonus));
    if (tempHp >= drow_max_hp) {
        hp = drow_max_hp;
        td->updateAct("this reaches Maximum Health. ");
    }
    else if (tempHp <= 0) {
        hp = 0;
    }
    else {
        hp = tempHp;
    }
}

void drow::change_atk(const int &value) {
    tempAtk += ceil (value * drow_potion_bonus);
    atk = drow_atk + tempAtk;
}

void drow::change_def(const int &value) {
    tempDef += ceil (value * drow_potion_bonus);
    def = drow_def + tempDef;
}

void drow::change_gold(const int &value) {
    gold += value;
}

void drow::steal_gold() {}
