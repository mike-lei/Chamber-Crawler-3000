//
//  ChamberPos.h
//  test
//
//  Created by Wang Annan on 2016-11-19.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef ChamberPos_h
#define ChamberPos_h

enum class chamberVal {room1, room2, room3, room4, room5, notroom};

chamberVal getRoom(const int &row, const int &col);

#endif /* ChamberPos_h */
