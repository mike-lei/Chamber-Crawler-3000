#include "Elf.h"
#include <math.h>

using namespace std;

const int Elf_default_hp = 140;
const int Elf_atk = 30;
const int Elf_def = 10;

Elf::Elf(): enemy("Elf", "E", Elf_default_hp, Elf_atk, Elf_def, 0, 0), hostile{true} {}

Elf::~Elf(){}

bool Elf::is_hostile() const{
    return hostile;
}

void Elf::attack(Character *defender) {
    if (defender->getRace() == "Drow") {
        defender->attackby(this);
    }
    else {
        defender->attackby(this);
        defender->attackby(this);
    }
}

void Elf::attackby(Character* attacker) {
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
