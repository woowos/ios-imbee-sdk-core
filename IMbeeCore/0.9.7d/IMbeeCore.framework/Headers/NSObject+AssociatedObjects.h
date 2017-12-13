//
//  NSObject+AssociatedObjects.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 13/7/15.
//  Copyright (c) 2015 IMbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (AssociatedObjects)

- (void)associateValue:(id)value withKey:(void *)key;
- (id)associatedValueForKey:(void *)key;

@end
