//
//  IMbeeCore.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 11/4/17.
//  Copyright © 2017 IMbee. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for IMbeeCore.
FOUNDATION_EXPORT double IMbeeCoreVersionNumber;

//! Project version string for IMbeeCore.
FOUNDATION_EXPORT const unsigned char IMbeeCoreVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <IMbeeCore/PublicHeader.h>

@class EDatabase;
@class EQuery;

#import <Foundation/Foundation.h>

#import <IMbeeCore/AbstractList.h>
#import <IMbeeCore/AbstractContent.h>
#import <IMbeeCore/AbstractContentManager.h>

#import <IMbeeCore/SyncHandler.h>
#import <IMbeeCore/Task.h>
#import <IMbeeCore/TaskResponse.h>

#import <IMbeeCore/ExternalContent.h>
#import <IMbeeCore/TextContent.h>
#import <IMbeeCore/MediaContent.h>
#import <IMbeeCore/CardContent.h>
#import <IMbeeCore/QuickReplyContent.h>
#import <IMbeeCore/ButtonMessageContent.h>
#import <IMbeeCore/ButtonContentPart.h>

#import <IMbeeCore/IMContact.h>
#import <IMbeeCore/ContactList.h>
#import <IMbeeCore/ContactManager.h>
#import <IMbeeCore/Conversation.h>
#import <IMbeeCore/ConversationList.h>
#import <IMbeeCore/Corporation.h>
#import <IMbeeCore/CorporateContactList.h>
#import <IMbeeCore/CorporateServiceList.h>
#import <IMbeeCore/CorporationData.h>
#import <IMbeeCore/CorporationList.h>
#import <IMbeeCore/ECommon.h>
#import <IMbeeCore/FormData.h>
#import <IMbeeCore/GroupMember.h>
#import <IMbeeCore/GroupMembersList.h>
#import <IMbeeCore/GroupStatus.h>
#import <IMbeeCore/IMbeeConfig.h>
#import <IMbeeCore/IMbeeTypes.h>
#import <IMbeeCore/InlineSyncDone.h>
#import <IMbeeCore/IntersectionResult.h>
#import <IMbeeCore/ListFilter.h>
#import <IMbeeCore/Message.h>
#import <IMbeeCore/MessageEnums.h>
#import <IMbeeCore/MessagesList.h>
#import <IMbeeCore/Model.h>
#import <IMbeeCore/NSObject+AssociatedObjects.h>
#import <IMbeeCore/NSString+Strip.h>
#import <IMbeeCore/Profile.h>

#ifndef IMBEE_CORE_CLASS
#define IMBEE_CORE_CLASS

// Public Notifications
#define IM_PUBLIC_NOTIFICATION_HISTORY_DONE @"IM_PUBLIC_NOTIFICATION_HISTORY_DONE"
#define IM_PUBLIC_NOTIFICATION_MSG_RECEIVED @"IM_PUBLIC_NOTIFICATION_MSG_RECEIVED"

@interface IMbeeCore : NSObject

+ (void)prepare:(IMbeeConfig *)imbeeConfig;
+ (void)deleteAll;

+ (IMbeeConfig *)imbeeConfig;

+ (Profile *)profile;
+ (ConversationList<Conversation *> *)conversations;
+ (ConversationList<Conversation *> *)visibleConversations;
+ (ContactList<__kindof IMContact *> *)visibleContacts;
+ (ContactManager<__kindof IMContact *> *)contactManager;
+ (CorporationList<Corporation *> *)corporations;

+ (void)setDatabaseAsResynced;
+ (bool)isRequiredFullSynchronization;

+ (bool)connect;
+ (void)disconnect;
+ (IMMPState)connectionState;

+ (void)registerOrSyncUserWithId:(NSString *)userId
                      deviceName:(NSString *)deviceName
                      hardwareId:(NSString *)hardwareId
                        platform:(NSString *)platform
                       osVersion:(NSString *)osVersion
                            done:(void (^)(Profile *profile, bool previously_registered))callback;

+ (bool)sendContentMessage:(AbstractContent *)content
            toConversation:(Conversation *)conversation
                   payload:(id)payload
                 withFlags:(MessageFlag)flags;

@end

#endif
