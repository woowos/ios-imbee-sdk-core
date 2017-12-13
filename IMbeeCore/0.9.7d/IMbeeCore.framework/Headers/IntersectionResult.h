//
//  IntersectionResult.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 26/7/15.
//  Copyright (c) 2015 IMbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AbstractList;

@interface IntersectionResult : NSObject

@property (strong, nonatomic) AbstractList *intersection;
@property (strong, nonatomic) AbstractList *outersection;

@end
