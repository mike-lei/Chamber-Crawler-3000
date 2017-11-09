//
//  MakeCharacter.cpp
//  test
//
//  Created by Wang Annan on 2016-11-22.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "MakeCharacter.h"

using namespace std;

player * MakeCharacter::CreatePlayer(const string &race) {
    if (race == "s" || race == "Shade") return new shade();
    else if (race == "d" || race == "Drow") return new drow();
    else if (race == "v" || race == "Vampire") return new vampire();
    else if (race == "t" || race == "Troll") return new troll();
    else if (race == "g" || race == "Goblin") return new goblin();
    else return nullptr;
}

enemy * MakeCharacter::CreateEnemy(const string &race) {
    if (race == "Dragon" || race == "D") {
        return new Dragon();
    }
    else if (race == "Dwarf" || race == "W") {
        return new Dwarf();
    }
    else if (race == "Elf" || race == "E") {
        return new Elf();
    }
    else if (race == "Halfling" || race == "L") {
        return new Halfling();
    }
    else if (race == "Human" || race == "H") {
        return new Human();
    }
    else if (race == "Merchant" || race == "M") {
        return new Merchant();
    }
    else if (race == "Orc" || race == "O") {
        return new Orc();
    }
    return nullptr;
}
