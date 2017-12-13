//
//  GroupMembersList.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 21/7/15.
//  Copyright (c) 2015 IMbee. All rights reserved.
//

#import "AbstractList.h"
#import "GroupMember.h"

@class Conversation;

#define for_each_groupMember(gml) for_each_generic(GroupMember, gml)

@interface GroupMembersList<__covariant ObjectType:GroupMember *> : AbstractList <AbstractListProtocol> {
    bool isListLoadedFromDb;
}

@property (nonatomic, strong) GroupMember *administrator;
@property (nonatomic, strong, readonly) Conversation *conversation;

- (instancetype)init __unavailable;
- (instancetype)initWithArray:(NSArray *)arr __unavailable;
- (instancetype)initWithConversation:(Conversation *)c;

- (ObjectType)groupMemberWithContact:(IMContact *)contact;
- (ObjectType)groupMemberWithContactOrCreate:(IMContact *)contact;
- (ObjectType)groupMemberWithImbeeId:(NSString *)imbeeId;
- (ObjectType)groupMemberWithImbeeIdOrCreate:(NSString *)imbeeId;
- (void)whoInfoMultiple:(id<SyncHandlerDelegate>)delegate withPriority:(TaskPriority)priority;

@end
