//
//  WD.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "WD.h"
#include "player.h"
using namespace std;

bool WD::found = false;

WD::WD(): Potion("Wound Def") {}

WD::~WD() {}

bool WD::getFound() const {
    return found;
}

void WD::Take_Potion(player *pc) {
    pc->change_def(-5);
    found = true;
}
