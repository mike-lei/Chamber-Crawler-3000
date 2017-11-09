//
//  BD.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef BD_hpp
#define BD_hpp

#include "Potion.h"

// increase Def by 5
class BD : public Potion {
    char type;
    std::string name;
    static bool found;
    
public:
    BD();
    ~BD();
    bool getFound() const;
    void Take_Potion (player *player);
};

#endif /* BD_hpp */
