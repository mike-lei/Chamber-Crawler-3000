//
//  BD.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "BD.h"
#include "player.h"
using namespace std;

bool BD::found = false;

BD::BD():Potion("Boost Def") {}

BD::~BD() {}

bool BD::getFound() const {
    return found;
}

void BD::Take_Potion(player *pc) {
    pc->change_def(+5);
    found = true;
}
