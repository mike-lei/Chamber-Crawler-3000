//
//  BA.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef BA_hpp
#define BA_hpp

#include "Potion.h"

// increase Atk by 5
class BA : public Potion {
    char type;
    std::string name;
    static bool found;
    
public:
    BA();
    ~BA();
    bool getFound() const;
    void Take_Potion(player *pc);
};

#endif /* BA_hpp */
