//
//  NormalHoard.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "NormalHoard.h"
#include "player.h"

NormalHoard::NormalHoard():Treasure("NormalHoard") {}

NormalHoard::~NormalHoard() {}

void NormalHoard::Take_Treasure(player *pc) {
    pc->change_gold(amt);
}
