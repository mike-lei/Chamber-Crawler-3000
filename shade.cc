#include "shade.h"
#include <math.h>
using namespace std;

const int shade_max_hp = 125;
const int shade_atk = 25;
const int shade_def = 25;

shade::shade():
player("Shade", shade_max_hp, shade_atk, shade_def, 0) {}

shade::~shade(){}

void shade::change_hp(const int &value) {
    int tempHp = ceil (hp + value);
    if (tempHp >= shade_max_hp) {
        hp = shade_max_hp;
        td->updateAct("this reaches Maximum Health. ");
    }
    else if (tempHp <= 0) {
        hp = 0;
    }
    else {
        hp = tempHp;
    }
}

void shade::change_atk(const int &value) {
    tempAtk += value;
    atk = tempAtk + shade_atk;
}

void shade::change_def(const int &value) {
    tempDef += value;
    def = tempDef + shade_def;
}

void shade::change_gold(const int &value) {gold += value;}

void shade::steal_gold() {}
