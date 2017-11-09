#include "Merchant.h"
#include <math.h>
using namespace std;

const int Merchant_default_hp = 30;
const int Merchant_atk = 70;
const int Merchant_def = 5;

bool Merchant::hostile = false;

Merchant::Merchant(): enemy("Merchant", "M", Merchant_default_hp, Merchant_atk, Merchant_def, 0, 0) {}

Merchant::~Merchant(){}

bool Merchant::is_hostile() const {
    return hostile;
}

void Merchant::attack(Character *defender) {
    defender->attackby(this);
}

void Merchant::attackby(Character* attacker) {
    hostile = true;
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
    }
}
