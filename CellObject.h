//
//  CellObject.hpp
//  test
//
//  Created by Wang Annan on 2016-11-25.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef CellObject_hpp
#define CellObject_hpp

#include <string>
#include <vector>
#include "TextDisplay.h"
#include "cell.h"

class CellObject {
protected:
    static TextDisplay *td;
    static std::vector <std::vector <cell>> theGrid;
public:
    CellObject();
    virtual ~CellObject();
    virtual std::string getType() const = 0;
    virtual std::string getRace() const = 0;
    static void setTd (TextDisplay *theDisplay);
    static void setGrid (std::vector <std::vector <cell>> &grid);
};

#endif /* CellObject_hpp */
