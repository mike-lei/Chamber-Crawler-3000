//
//  WA.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "WA.h"
#include "player.h"
using namespace std;

bool WA::found = false;

WA::WA(): Potion("Wound Atk") {}

WA::~WA() {}

bool WA::getFound() const {
    return found;
}

void WA::Take_Potion(player *pc) {
    pc->change_atk(-5);
    found = true;
}
