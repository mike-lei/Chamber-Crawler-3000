//
//  MakeFloor.cpp
//  test
//
//  Created by Wang Annan on 2016-11-20.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "MakeFloor.h"

using namespace std;

Floortiles* MakeFloor:: CreateTiles(const string &type) {
    Floortiles *tile = nullptr;
    if (type == "|") {
        tile = new verticalWall ();
    }
    else if (type == "-") {
        tile = new horizonWall ();
    }
    else if (type == "+") {
        tile = new door ();
    }
    else if (type == "#") {
        tile = new passage ();
    }
    else if (type == "/") {
        tile = new stair ();
    }
    else if (type == ".") {
        tile = new dotground ();
    }
    else if (type == " ") {
        tile = new empty ();
    }
    return tile;
}
