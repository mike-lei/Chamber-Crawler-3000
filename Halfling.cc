#include "Halfling.h"
#include <math.h>

using namespace std;

const int Halfling_default_hp = 100;
const int Halfling_atk = 15;
const int Halfling_def = 20;

Halfling::Halfling(): enemy("Halfling", "L", Halfling_default_hp, Halfling_atk, Halfling_def, 0, 0), hostile{true} {}

Halfling::~Halfling(){}

bool Halfling::is_hostile() const{
    return hostile;
}

void Halfling::attack(Character *defender) {
    defender->attackby(this);
}

void Halfling::attackby(Character* attacker) {
    int attackby_success = rand() % 2;
    if (attackby_success) {
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
    else {
        td->updateAct("PC attacked " + this->getRace() + " but missed. ");
    }
    
}
