//
//  Contact.h
//  IMbee
//
//  Created by jordib on 11/07/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import "SyncHandler.h"
#import "Model.h"
#import "CorporationData.h"

typedef enum {
    ContactTypeUndefined    = 0, // No utilizar
    ContactTypeIndividual   = 1,
    ContactTypeGroupMember  = 3,
    ContactTypeCorpMember   = 5, // Corporation member
    ContactTypeCorpVirtual  = 6,
    
    ContactTypeProfile      = 17141  // Conté informació del perfil
} ContactType;

@class Conversation;

@interface IMContact : NSObject <SyncHandlerDelegate> {
    NSString *dbConversationId;
    
    bool saveLastUpdate;
    bool mustRegenCache;
    
    struct {
        NSString __unsafe_unretained *fullName;
        bool valid;
    } cachedFullName;
    
    pthread_mutex_t generalLock;
}

@property (nonatomic)         int         identifier;
@property (nonatomic)         int         addressBookId;
@property (nonatomic)         ModelState  modelState;
@property (nonatomic, strong) NSString*   imageURL;
@property (nonatomic, strong) NSString*   name;
@property (nonatomic, strong) NSString*   nickname;
@property (nonatomic, strong) NSString*   status;
@property (nonatomic, strong) NSString*   registerValue;
@property (nonatomic, strong) NSString*   woowosUUID;
@property (nonatomic, strong) NSDate*     updated;
@property (nonatomic, strong) NSDate*     avatarUpdated;
@property (nonatomic, strong) NSDate*     lastUpdate;
@property (nonatomic, strong) NSDate*     lastAvatarUpdate;
@property (nonatomic, strong) NSDate*     lastChecked;
@property (nonatomic)         ContactType type;

@property (nonatomic, strong) UIColor*    color;
@property (nonatomic, strong) NSString*   domainName;

@property (nonatomic, strong) id<SyncHandlerDelegate> delegate;

@property (nonatomic, strong) NSString              *fullName;
@property (nonatomic, strong) CorporationData       *corpData;
@property (nonatomic, strong) Conversation          *conversation;
@property (nonatomic, strong, readonly) NSMutableDictionary *metadata;

- (instancetype)initWithQuery:(EQuery *)qry;
- (void)setDataFromQuery:(EQuery *)qry;
- (void)setDataFromJSON:(NSDictionary *)d;

// Contact Methods
- (NSString *)fullNameOrDefaultText:(NSString *)defText;
- (NSString *)fullNameOrRegisterValueOrDefaultText:(NSString *)defText;

- (NSURL *)avatarImageUrl;
- (UIImage *)placeholder;

- (BOOL)isRegisterValueAnEmail;
- (BOOL)isRegisterValueAPhoneNumber;
- (void)setSaveLastUpdate:(BOOL)b;
- (void)setFullNameCacheExpired;

- (void)requestContactInfoWithPriority:(TaskPriority)priority andDelegate:(id<SyncHandlerDelegate>)delegate;

- (NSComparisonResult)compare:(IMContact *)other;

@end
