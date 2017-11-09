//
//  MerchantHoard.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "MerchantHoard.h"
#include "player.h"

MerchantHoard::MerchantHoard(): Treasure("MerchantHoard") {}

MerchantHoard::~MerchantHoard() {}

void MerchantHoard::Take_Treasure(player *pc) {
    pc->change_gold(amt);
}
