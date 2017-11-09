//
//  BA.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "BA.h"
#include "player.h"

using namespace std;

bool BA::found = false;

BA::BA():Potion("Boost Atk") {}

BA::~BA() {}

bool BA::getFound() const {
    return found;
}

void BA::Take_Potion(player *pc) {
    pc->change_atk(+5);
    found = true;
}
