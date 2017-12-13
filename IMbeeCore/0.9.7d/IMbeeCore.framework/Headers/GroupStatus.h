//
//  GroupStatus.h
//  IMbee
//
//  Created by jordib on 11/07/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import "Conversation.h"

@interface GroupStatus : NSObject

@property (nonatomic) ModelState            modelState;
@property (nonatomic) MessageState          state;
@property (nonatomic, strong) NSString *    messageUUID;
@property (nonatomic, strong) NSString *    memberUUID;
@property (nonatomic, strong) NSString *    conversationId;

- (instancetype)initWithQuery:(EQuery *)qry;
- (void)setDataFromQuery:(EQuery *)qry;

@end
