//
//  ListFilter.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 27/3/17.
//  Copyright © 2017 IMbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ListFilter : NSObject {
    bool(^filter)(id obj);
}

+ (instancetype)initWithFilter:(bool(^)(id obj))filter;

- (bool)passObject:(id)obj;

@end
