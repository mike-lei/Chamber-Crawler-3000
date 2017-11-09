#include "Orc.h"
#include <math.h>
using namespace std;

const int Orc_default_hp = 180;
const int Orc_atk = 30;
const int Orc_def = 25;

Orc::Orc(): enemy("Orc", "O", Orc_default_hp, Orc_atk, Orc_def, 0, 0), hostile{true} {}

Orc::~Orc(){}

bool Orc::is_hostile() const {
    return hostile;
}

void Orc::attack(Character *defender) {
    defender->attackby(this);
}

void Orc::attackby(Character* attacker) {
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
