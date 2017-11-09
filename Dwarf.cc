#include "Dwarf.h"
#include <math.h>

using namespace std;

const int Dwarf_default_hp = 100;
const int Dwarf_atk = 20;
const int Dwarf_def = 30;

Dwarf::Dwarf(): enemy("Dwarf", "W", Dwarf_default_hp, Dwarf_atk, Dwarf_def, 0, 0), hostile{true} {}

Dwarf::~Dwarf(){}

bool Dwarf::is_hostile() const{
    return hostile;
}

void Dwarf::attack(Character *defender) {
    defender->attackby(this);
}

void Dwarf::attackby(Character* attacker) {
    if (attacker->getRace() == "Vampire" ) {
        const int hploss = 5;
        attacker->change_hp(-hploss);
        ostringstream num_to_str;
        num_to_str << hploss;
        td->updateAct("PC losses " + num_to_str.str() + " HP. ");
        
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
