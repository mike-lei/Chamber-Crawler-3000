//
//  PH.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef PH_hpp
#define PH_hpp

#include "Potion.h"

// lose up to 10 HP ( cannot fall below 0 HP )
class PH : public Potion {
    char type;
    std::string name;
    static bool found;
    
public:
    PH();
    ~PH();
    bool getFound() const;
    void Take_Potion (player *player);
};
#endif /* PH_hpp */
