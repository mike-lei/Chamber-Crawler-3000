//
//  floortiles.hpp
//  test
//
//  Created by Wang Annan on 2016-11-21.
//  Copyright © 2016 Wang Annan. All rights reserved.
//

#ifndef _Floortiles_h_
#define _Floortiles_h_

#include "CellObject.h"
#include <string>

class Floortiles: public CellObject {
    std::string type;
public:
    Floortiles(const std::string &type);
    virtual ~Floortiles();
    std::string getType() const;
    std::string getRace() const;
};

#endif /* floortiles_hpp */
