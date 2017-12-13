//
//  Message.h
//  IMbee
//
//  Created by jordib on 11/07/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import "MessageEnums.h"
#import "AbstractContent.h"

@class GroupStatus;
@class MessagesList;
@class Conversation;
@class PreprocessedMessage;

@interface Message : NSObject {
    pthread_mutex_t generalLock;
    dispatch_semaphore_t msg_state_lock;
    
    NSString *_internalSenderId;
}

@property (nonatomic) CGFloat                   cachedHeight;
@property (nonatomic) bool                      neverSaveToDatabase;

@property (nonatomic) MessageFlag               flags;
@property (nonatomic) MessageInternalFlag       internalFlags;
@property (nonatomic) MessageAction             action;
@property (nonatomic, readonly) MessageState    state;
@property (nonatomic, readonly) MessageState    commonStateForMembers;

@property (nonatomic, strong) NSDate        *date;
@property (nonatomic, strong) NSDictionary  *extras;

@property (nonatomic, strong, readonly) IMContact               *sender;
@property (nonatomic, strong, readonly) NSString                *messageId;
@property (nonatomic, strong, readonly) Conversation            *conversation;
@property (nonatomic, strong)           AbstractContent         *content; // TODO: readonly
@property (nonatomic, strong, readonly) NSArray<GroupStatus *>  *groupStatus;

@property (nonatomic, weak) Message             *previous;
@property (nonatomic, weak) Message             *next;

+ (NSString *)uniqueId:(NSString *)messageId;
+ (MessageCategory)category:(id)m;
+ (MessageCategory)categoryForAction:(MessageAction)action;

- (instancetype)init __unavailable;
- (instancetype)initWithConversation:(Conversation *)conversation
                           messageId:(NSString *)messageId
                           andSender:(IMContact *)contact;

- (void)setDataFromQuery:(EQuery *)qry;
- (bool)isSentByMe;
- (bool)ackState:(MessageState)ms;
- (NSComparisonResult)compare:(Message *)other;

- (bool)isGroupStatusInMemory;

/* Other's message */
- (bool)notifyDelivered;
- (bool)notifyRead;

/* Message that is sent by me */
- (bool)setState:(MessageState)state forGroupMember:(NSString *)memberUUID;
- (bool)sendRemoteDelete;

@end
