//
//  Potion.hpp
//  test
//
//  Created by Wang Annan on 2016-11-27.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef Potion_hpp
#define Potion_hpp


#include "Item.h"
#include <string>

class player;

class Potion:public Item {
    std::string type, name;
public:
    Potion (const std::string &name);
    ~Potion();
    std::string getType() const override;
    std::string getRace() const override;
    std::string getName() const;
    virtual void Take_Potion(player *pc) = 0;
    virtual bool getFound() const = 0;
};
#endif /* Potion_hpp */
