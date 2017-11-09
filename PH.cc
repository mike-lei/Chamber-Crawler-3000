//
//  PH.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "PH.h"
#include "player.h"
using namespace std;

bool PH::found = false;

PH::PH(): Potion("Poisson Health") {}

PH::~PH() {}

bool PH::getFound() const {
    return found;
}

void PH::Take_Potion(player *pc) {
    pc->change_hp(-10);
    found = true;
}
