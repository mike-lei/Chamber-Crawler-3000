#include "troll.h"
#include <math.h>
using namespace std;

const int troll_max_hp = 120;
const int troll_atk = 25;
const int troll_def = 15;

troll::troll():
player("Troll", troll_max_hp, troll_atk, troll_def, 0) {}

troll::~troll()
{
    //dtor
}

void troll::change_hp(const int &value) {
    ostringstream num_to_str;
    num_to_str << value;
    td->updateAct("this restores " + num_to_str.str() + " HP. ");
    int tempHp = ceil (hp + value);
    if (tempHp >= troll_max_hp) {
        hp = troll_max_hp;
        td->updateAct("this reaches Maximum Health. ");
    }
    else if (tempHp <= 0) {
        hp = 0;
    }
    else {
        hp = tempHp;
    }
}

void troll::change_atk(const int &value) {
    tempAtk += value;
    atk = tempAtk + troll_atk;
}

void troll::change_def(const int &value) {
    tempDef += value;
    def = tempDef + troll_def;
}

void troll::change_gold(const int &value) {gold += value;}

void troll::steal_gold() {}
