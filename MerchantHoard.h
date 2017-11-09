//
//  MerchantHoard.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef MerchantHoard_hpp
#define MerchantHoard_hpp

#include "Treasure.h"

class MerchantHoard : public Treasure {
    int amt = 4;
public:
    MerchantHoard();
    ~MerchantHoard();
    void Take_Treasure(player *pc) override;
};

#endif /* MerchantHoard_hpp */
