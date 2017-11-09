#include "vampire.h"
#include <math.h>
using namespace std;

const int vampire_default_hp = 50;
const int vampire_atk = 25;
const int vampire_def = 25;

vampire::vampire():
player("Vampire", vampire_default_hp, vampire_atk, vampire_def, 0) {}

vampire::~vampire()
{
    //dtor
}

void vampire::change_hp(const int &value) {
    int tempHp = ceil (hp + value);
    if (tempHp <= 0) {
        hp = 0;
    }
    else {
        hp = tempHp;
    }
}

void vampire::change_atk(const int &value) {
    tempAtk += value;
    atk = tempAtk + vampire_atk;
}

void vampire::change_def(const int &value) {
    tempDef += value;
    def = tempDef + vampire_def;
}

void vampire::change_gold(const int &value) {gold += value;}

void vampire::steal_gold() {}
