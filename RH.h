//
//  RH.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef RH_hpp
#define RH_hpp

#include "Potion.h"

// restore up to 10HP (cannot exceed maximum)
class RH : public Potion {
    static bool found;
    
public:
    RH();
    ~RH();
    bool getFound() const;
    void Take_Potion (player *player);
};

#endif /* RH_hpp */
