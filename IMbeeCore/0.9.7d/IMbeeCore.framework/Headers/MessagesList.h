//
//  MessagesList.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 18/8/15.
//  Copyright (c) 2015 IMbee. All rights reserved.
//

#import "AbstractList.h"
#import "Message.h"

#define for_each_message_all(ml) \
    for_each_generic(Message, ml)

#define for_each_message(ml) \
    for (Message *each = nil; each == nil; each = (id) self) \
        for (NSUInteger _i = 0; (each = _i < [ml count] ? [ml objectAtIndex:_i] : nil); ++_i) \
            if (each.action != MessageActionDate)

void init_message_list_queue(void);

typedef enum {
    MoreMessagesUnknown,
    MoreMessagesRequesting,
    MoreMessagesMaybeYes,
    MoreMessagesNo,
} MessagesAvaiavilityState;

typedef enum {
    LoadMoreFromDB         = 0b01,
    LoadMoreFromWs         = 0b10,
    LoadMoreFromEverywhere = 0b11,
} LoadMoreFrom;

typedef enum {
    MessageListLoadStateStopped,
    MessageListLoadStateLoadingFromDisk
} MessageListLoadState;

@interface MessagesList<__covariant ObjectType:Message *> : AbstractList <AbstractListProtocol> {
    NSRange currentRange;
    
    NSMutableDictionary *randomMessages;
    
    int remaining_messages_db; // número de missatges de la DB que NO estan en memòria
    
    dispatch_semaphore_t pool, pool_load_more;
    
    MessagesAvaiavilityState messagesAvaiavility;
    MessageListLoadState messageListLoadState;
}

@property (nonatomic, strong, readonly) Conversation *conversation;
@property (nonatomic, strong, readonly) Message *newestMessage;
@property (nonatomic, strong, readonly) Message *oldestMessage;

- (instancetype)init __unavailable;
- (instancetype)initWithConversation:(Conversation *)conversation;

- (NSUInteger)totalCount;
- (MessageListLoadState)messageListLoadState;
- (MessagesAvaiavilityState)messageAvaiability;
- (ObjectType)newMessage;
- (ObjectType)newMessage:(NSString *)messageId fromSender:(IMContact *)sender;
- (ObjectType)messageWithMessageId:(NSString *)messageId;
- (bool)loadMore:(int)more from:(LoadMoreFrom)from withPriority:(TaskPriority)priority async:(bool)async;
- (NSUInteger)addMultipleFromQuery:(EQuery *)qry;

@end
