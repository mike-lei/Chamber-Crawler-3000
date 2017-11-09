//
//  NormalHoard.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef NormalHoard_hpp
#define NormalHoard_hpp

#include "Treasure.h"

class NormalHoard : public Treasure {
    int amt = 2;
public:
    NormalHoard();
    ~NormalHoard();
    void Take_Treasure(player *pc) override;
};

#endif /* NormalHoard_hpp */
