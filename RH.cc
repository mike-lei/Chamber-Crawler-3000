//
//  RH.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "RH.h"
#include "player.h"
using namespace std;

bool RH::found = false;

RH::RH(): Potion("Restore Health") {}

RH::~RH() {}

bool RH::getFound() const {
    return found;
}

void RH::Take_Potion(player *pc) {
    pc->change_hp(+10);
    found = true;
}
