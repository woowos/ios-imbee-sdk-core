//
//  ConversationList.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 11/12/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import "AbstractList.h"
#import "Conversation.h"

#define for_each_conversation(cl) for_each_generic(Conversation, cl)

@interface ConversationList<__covariant ObjectType:Conversation *> : AbstractList <AbstractListProtocol>

@property (nonatomic, readonly) unsigned int unreadMessagesCount;

- (int)relativeUpdateUnreadMessagesCount:(unsigned int)update forConversation:(Conversation *_Nonnull)conv;
- (ObjectType)conversationWithWoowosId:(NSString *)woowosId;
- (ObjectType)conversationWithWoowosIdOrCreate:(NSString *)woowosId withType:(ConversationType)conversationType;
- (ConversationList *)searchConversationsContains:(NSString *)search;

- (void)requestChatListAsync:(void (^)(bool success))callback;
- (void)requestCreateConverstionOfType:(ConversationType)convType title:(NSString * _Nullable)title contacts:(NSArray<IMContact *> *_Nonnull)contacts async:(void (^)(bool success, bool previously_created, Conversation *conv))callback;

@end
