//
//  WD.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef WD_hpp
#define WD_hpp

#include "Potion.h"

// Decrease Def by 5
class WD : public Potion {
    char type;
    std::string name;
    static bool found;
    
public:
    WD();
    ~WD();
    bool getFound() const;
    void Take_Potion (player *player);
};

#endif /* WD_hpp */
