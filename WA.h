//
//  WA.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef WA_hpp
#define WA_hpp

#include "Potion.h"

// decrease Atk by 5
class WA : public Potion {
    char type;
    std::string name;
    static bool found;
    
public:
    WA();
    ~WA();
    bool getFound() const;
    void Take_Potion (player *player);
};
#endif /* WA_hpp */
