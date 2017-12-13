//
//  Contact.h
//  IMbee
//
//  Created by jordib on 25/07/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

@interface GroupMember : NSObject {
    NSString *dbConversationId;
    NSString *dbWoowosUUID;
}

@property (nonatomic)           bool              neverSavedToDatabase;
@property (nonatomic, readonly) bool              admin;
@property (nonatomic, strong, readonly) Conversation* conversation;
@property (nonatomic, strong, readonly) IMContact*  contact;

- (instancetype)initFromQuery:(EQuery *)qry;
- (instancetype)initWithConversation:(Conversation *)conversation andContact:(IMContact *)member;
- (void)setAdmin:(bool)admin;
- (NSComparisonResult)compare:(GroupMember *)other;

@end
