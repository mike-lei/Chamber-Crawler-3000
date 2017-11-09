#include "Dragon.h"
#include <math.h>
#include "DragonHoard.h"
using namespace std;

const int Dragon_default_hp = 150;
const int Dragon_atk = 20;
const int Dragon_def = 20;

Dragon::Dragon(): enemy("Dragon", "D", Dragon_default_hp, Dragon_atk, Dragon_def, 0, 0), hostile{true}, dh{nullptr} {}

Dragon::~Dragon(){}

bool Dragon::is_hostile() const{
    return hostile;
}
DragonHoard* Dragon::getDragonHoard() {
    return dh;
}

void Dragon::attack(Character *defender) {
    defender->attackby(this);
}

void Dragon::attackby(Character* attacker) {
    if (attacker->getRace() == "Vampire") {
        int restoreHp = 5;
        attacker->change_hp(restoreHp);
        ostringstream num_to_str;
        num_to_str << restoreHp;
        td->updateAct("PC restores " + num_to_str.str() + " HP. ");
    }
    int damage = ceil (float (100.0 / (100.0 + this->def)) * attacker->get_atk());
    hp -= damage;
    if (hp > 0) {
        ostringstream damage_to_str;
        damage_to_str << damage;
        ostringstream hp_to_str;
        hp_to_str << this->hp;
        td->updateAct("PC deals " + damage_to_str.str() + " damage to "
                      + this->race + " (" + hp_to_str.str() + " HP). ");
    }
    else {
        hp = 0;
        dh->change_dragon_died();
    }
}

void Dragon::guardTreasure(DragonHoard *dh) {
    this->dh = dh;
}
