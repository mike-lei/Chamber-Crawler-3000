#include "Human.h"
#include <math.h>
using namespace std;

const int Human_default_hp = 140;
const int Human_atk = 20;
const int Human_def = 20;

Human::Human(): enemy("Human", "H", Human_default_hp, Human_atk, Human_def, 0, 0), hostile{true} {}

Human::~Human(){}

bool Human::is_hostile() const {
    return hostile;
}

void Human::attack(Character *defender) {
    defender->attackby(this);
}

void Human::attackby(Character* attacker) {
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
