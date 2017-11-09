//
//  SmallHoard.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef SmallHoard_hpp
#define SmallHoard_hpp

#include "Treasure.h"

class SmallHoard : public Treasure {
    int amt = 1;
public:
    SmallHoard();
    ~SmallHoard();
    void Take_Treasure(player *pc) override;
};

#endif /* SmallHoard_hpp */
