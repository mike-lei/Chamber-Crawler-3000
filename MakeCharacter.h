//
//  MakeCharacter.hpp
//  test
//
//  Created by Wang Annan on 2016-11-22.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef MakeCharacter_hpp
#define MakeCharacter_hpp

#include <string>
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"

#include "Dragon.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Halfling.h"
#include "Human.h"
#include "Merchant.h"
#include "Orc.h"

class Character;

class MakeCharacter{
public:
    virtual player * CreatePlayer(const std::string &race);
    virtual enemy * CreateEnemy(const std::string &race);
};

#endif /* MakeCharacter_hpp */
