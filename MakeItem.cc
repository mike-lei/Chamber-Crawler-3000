//
//  MakeItem.cpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "MakeItem.h"

using namespace std;

Potion * MakeItem:: CreatePotion(const int &num_translate) {
    Potion *p = nullptr;
    if (num_translate == 0) {p = new RH(); }
    else if (num_translate == 1) {p = new BA(); }
    else if (num_translate == 2) {p = new BD(); }
    else if (num_translate == 3) {p = new PH(); }
    else if (num_translate == 4) {p = new WA(); }
    else if (num_translate == 5) {p = new WD(); }
    return p;
}

Treasure * MakeItem::CreateTreasure(const int &num_translate) {
    Treasure *t = nullptr;
    if (num_translate == 6) {t = new NormalHoard(); }
    else if (num_translate == 7) {t = new SmallHoard(); }
    else if (num_translate == 8) {t = new MerchantHoard(); }
    else if (num_translate == 9) {t = new DragonHoard(); }
    return t;
}
