//
//  AbstractContentManager.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 12/6/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AbstractContentManager : NSObject

@property (strong, nonatomic, readonly) NSMutableDictionary<NSString *, Class> *registeredContents;

+ (void)registerContentType:(Class)clss;
+ (AbstractContent *)contentForDictionary:(NSDictionary *)dict;

@end
