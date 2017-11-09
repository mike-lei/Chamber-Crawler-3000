//
//  ChamberPos.cpp
//  test
//
//  Created by Wang Annan on 2016-11-19.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#include "ChamberVal.h"

chamberVal getRoom(const int &row, const int &col) {
    if ((3 <= row && row <= 6) && (3 <= col && col <= 28)) {
        return chamberVal::room1;
    }
    else if (((3 <= row && row <= 4) && (39 <= col && col <= 61)) ||
              ((row == 5) && (39 <= col && col <= 69)) ||
              ((row == 6) && (39 <= col && col <= 72)) ||
              ((7 <= row && row <= 12) && (61 <= col && col <= 75))) {
        return chamberVal::room2;
    }
    else if ((10 <= row && row <= 12) && (38 <= col && col <= 49)) {
        return chamberVal::room3;
    }
    else if ((15 <= row && row <= 21) && (4 <= col && col <= 24)) {
        return  chamberVal::room4;
    }
    else if ((((16 <= row && row <= 18) && (65 <= col && col <= 75)) ||
              ((19 <= row && row <= 21) && (37 <= col && col <= 75)))) {
        return chamberVal::room5;
    }
    return chamberVal::notroom;
}
