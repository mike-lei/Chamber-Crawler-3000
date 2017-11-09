//
//  MakeFloor.hpp
//  test
//
//  Created by Wang Annan on 2016-11-20.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef MakeFloor_hpp
#define MakeFloor_hpp

#include <string>
#include "Floortiles.h"
#include "verticalWall.h"
#include "horizonWall.h"
#include "door.h"
#include "passage.h"
#include "stair.h"
#include "dotground.h"
#include "empty.h"

class Floortiles;

class MakeFloor {
public:
    virtual Floortiles *CreateTiles(const std::string &type);
    
};

#endif /* MakeFloor_hpp */
