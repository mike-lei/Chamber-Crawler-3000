//
//  SmallHoard.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "SmallHoard.h"
#include "player.h"

SmallHoard::SmallHoard(): Treasure("SmallHoard") {}

SmallHoard::~SmallHoard() {}

void SmallHoard::Take_Treasure(player *pc) {
    pc->change_gold(amt);
}
