//
//  DragonHoard.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "DragonHoard.h"
#include "player.h"

DragonHoard::DragonHoard():Treasure("DragonHoard"), r{0}, c{0}, dragon{nullptr}, is_dragon_died{false} {}

DragonHoard::~DragonHoard() {}

bool DragonHoard::dragon_died() const {
    return is_dragon_died;
}

enemy * DragonHoard::getDragon() const {
    return dragon;
}

int DragonHoard::get_row() const {
    return r;
}

int DragonHoard::get_col() const {
    return c;
}

void DragonHoard::setPos (const int &r, const int &c) {
    this->r = r;
    this->c = c;
}

void DragonHoard::change_dragon_died() {
    is_dragon_died = true;
}

void DragonHoard::setDragon(enemy *dragon) {
    this->dragon = dragon;
}

void DragonHoard::Take_Treasure(player *pc) {
    pc->change_gold(amt);
}

