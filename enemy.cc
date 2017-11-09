#include "enemy.h"

using namespace std;
enemy::enemy(const string &race, const string &type, const int &hp,
             const int &atk, const int &def, const int &row, const int &col):
race{race}, type {type}, hp{hp}, atk{atk}, def{def}, row{row}, col{col} {}

enemy::~enemy()
{
    //dtor
}

void enemy::updatepos(const int &row, const int &col) {
    this->row = row;
    this->col = col;
}

std::string enemy::getRace() const {return race;}

std::string enemy::getType() const {return type;}

int enemy::get_hp() const {return hp;}

int enemy::get_atk()  const {return atk;}

int enemy::get_def() const {return def;}

int enemy::get_row() const {return row;}

int enemy::get_col() const {return col;}

int enemy::get_gold() const { return 0;}

void enemy::change_hp (const int &value) {}

void enemy::change_atk(const int &value) {}

void enemy::change_def(const int &value) {}

void enemy::change_gold(const int &value) {}

void enemy::steal_gold() {}

void enemy::move (const string &direction) {}
