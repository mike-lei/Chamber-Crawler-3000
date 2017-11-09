#include "player.h"
#include "Potion.h"
#include <sstream>
#include <math.h>

using namespace std;

player::player(const string &race, const int &hp, const int &atk, const int &def, const int &gold):
type{"@"}, race{race}, oldTile{"."}, hp{hp}, atk{atk}, def{def}, gold{gold},
row{0}, col{0}, level{1}, tempAtk{0}, tempDef{0} {}

player::~player() {}

void player::change_level() {
    ++level;
}

void player::setPos(const int &row, const int &col) {
    this->row = row;
    this->col = col;
}

void player::change_OldTile(const string &newTile) {
    this->oldTile = newTile;
}

void player::goToNewFloor() {
    ++level;
    tempAtk = 0;
    tempDef = 0;
    change_atk(0);
    change_def(0);
}

void player::move(const string &input) {
    if (this->getRace() == "Troll") {
        int restoreHp = 5;
        this->change_hp(restoreHp);
    }
    if(input == "North") {--row;}
    else if(input == "South") {++row;}
    else if(input == "West") {--col;}
    else if(input == "East") {++col;}
    else if(input == "NorthWest") {--row; --col;}
    else if(input == "NorthEast") {--row; ++col;}
    else if(input == "SouthWest") {++row; --col;}
    else if(input == "SouthEast") {++row; ++col;}
}

void player::attack(Character *defender) {
    defender->attackby(this);
}

void player::attackby(Character* attacker) {
    int attackby_success = rand() % 2;
    if (attackby_success) {
        int damage = ceil (float (100.0 / (100.0 + this->def)) * attacker->get_atk());
        if (this->getRace() == "Goblin" && attacker->getRace() == "Orc") {
            float atkBonusPercent = 0.5;
            damage = damage + damage * atkBonusPercent;
        }
        hp -= damage;
        if (hp <= 0) {
            hp = 0;
        }
        ostringstream num_to_str;
        num_to_str << damage;
        td->updateAct(attacker->getRace() + " deals " + num_to_str.str() + " damage to PC. ");
    }
    else {
        td->updateAct(attacker->getRace() + " attacked you but missed. ");
    }
}

void player::Take_Potion(Potion *p) { p->Take_Potion(this);}

string player::getRace() const{ return race;}

string player::getType() const{ return type;}

string player::getOldTile() const { return oldTile;}

int player::get_hp() const {return hp;}

int player::get_atk() const {return atk;}

int player::get_def() const {return def;}

int player::get_gold() const {return gold;}

int player::get_row() const {return row;}

int player::get_col() const {return col;}

int player::get_level() const {return level;}
