//
//  Conversation.h
//  IMbee
//
//  Created by jordib on 11/07/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import "IMContact.h"
#import "GroupMembersList.h"
#import "MessagesList.h"

typedef enum {
    ConversationStatusNotMember = -20,
    ConversationStatusDeleted   = -1,
    ConversationStatusNormal    = 0
} ConversationStatus;

typedef enum {
    ConversationTypeUndefined   = 0,
    ConversationTypeIndividual  = 1,
    ConversationTypeGroup       = 2,
    ConversationTypeService     = 3
} ConversationType;

@interface Conversation : NSObject {
    pthread_mutex_t generalLock;
}

@property (nonatomic) ConversationStatus  status;
@property (nonatomic) ConversationType    type;
@property (nonatomic) ModelState          modelState;
@property (nonatomic) bool                inChatRoom;
@property (nonatomic) int                 unreadMessagesCount;
@property (nonatomic, strong, readonly) NSString         *conversationId;

@property (nonatomic, strong)           NSString         *name;
@property (nonatomic, strong)           NSString         *imageURL;
@property (nonatomic, strong)           UIColor          *color;

@property (nonatomic, strong, readonly) Message          *newestMessage;
@property (nonatomic, strong, readonly) IMContact        *otherMember;
@property (nonatomic, strong, readonly) MessagesList<Message *>         *messages;
@property (nonatomic, strong, readonly) GroupMembersList<GroupMember *> *groupMembers;
@property (nonatomic, strong, readonly) NSDictionary *extras;

@property (nonatomic, strong) NSDate *typingDate;

- (instancetype)initWithConversationId:(NSString *)convId;

- (void)setDataFromQuery:(EQuery *)qry;
- (GroupMembersList *)groupMembersIfAlreadyInMemory;

- (NSURL *)avatarImageUrl;
- (UIImage *)placeholder;

// WebService /chat/...
+ (void)createWithContacts:(NSArray<IMContact *> *)contacts type:(ConversationType)type name:(NSString *)name photo:(UIImage *)photo andDelegate:(id<SyncHandlerDelegate>)delegate;
- (void)joinContact:(IMContact *)contact delegate:(id<SyncHandlerDelegate>)delegate;
- (void)updateGroupTitle:(NSString *)title delegate:(id<SyncHandlerDelegate>)delegate;
- (void)updateGroupImage:(UIImage *)image delegate:(id<SyncHandlerDelegate>)delegate;
- (void)leaveGroup:(id<SyncHandlerDelegate>)delegate;
- (void)kickMember:(IMContact *)member delegate:(id<SyncHandlerDelegate>)delegate;

- (void)requestHistoryUpToMessageId:(NSString *)messageId withPriority:(TaskPriority)priority andDelegate:(id<SyncHandlerDelegate>)delegate;
- (void)requestConversationInfoWithPriority:(TaskPriority)priority andDelegate:(id<SyncHandlerDelegate>)delegate;

+ (NSArray<GroupMember *> *)groupMemberWhoSentMessage:(Message *)message;
+ (NSArray<GroupMember *> *)groupMembersExceptMeInConversation:(Conversation *)conversation;

+ (NSString *)conversationTypeString:(ConversationType)conversationType;
+ (ConversationType)conversationType:(id)conversationType;

+ (NSMutableDictionary *)generateChatCreateOrJoinExtrasForConversation:(Conversation *)c;
+ (void)sendChatReleatedMessageForConversation:(Conversation *)c
                                    withAction:(MessageAction)action
                                     andExtras:(NSDictionary *)extras;

@end
