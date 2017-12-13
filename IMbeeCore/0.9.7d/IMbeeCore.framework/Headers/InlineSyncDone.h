//
//  InlineSyncDone.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 26/6/15.
//  Copyright (c) 2015 IMbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface InlineSyncDone : NSObject <SyncHandlerDelegate>

@property (strong, nonatomic) void (^syncDone)(bool success, id obj, NSString *identifier);
@property (strong, nonatomic) void (^progressChange)(float, ProgressType);

+ (instancetype)initWithSyncDone:(void(^)(bool success, id obj, NSString *identifier))syncDone;

@end
