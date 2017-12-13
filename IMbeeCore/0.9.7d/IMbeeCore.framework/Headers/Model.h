//
//  Model.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 7/4/17.
//  Copyright © 2017 IMbee. All rights reserved.
//

#ifndef Model_h
#define Model_h

typedef enum {
    ModelSaved         = 0b001,
    ModelModified      = 0b010,
    ModelNeverSaved    = 0b100
} ModelState;

#endif /* Model_h */
