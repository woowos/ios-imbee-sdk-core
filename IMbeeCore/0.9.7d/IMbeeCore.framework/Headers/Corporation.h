//
//  Corporation.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 11/11/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import "CorporateContactList.h"
#import "CorporateServiceList.h"

typedef enum {
    WSstopped = 0,
    WSrunning = 1
} WSstatus;

@interface Corporation : NSObject <SyncHandlerDelegate> {
    pthread_mutex_t generalLock;
}

/*
 "idSha": "f95589b2f193adca4ca3832e24e6f34653a3dd60",
 "name": "Imbee",
 "logo": "http://woowosdev.s3.amazonaws.com/corporate/logo/f95589b2f193adca4ca3832e24e6f34653a3dd60.png",
 "logoProfile": "http://woowosdev.s3.amazonaws.com/corporate/profileLogo/f95589b2f193adca4ca3832e24e6f34653a3dd60.jpeg",
 "phone": "931231235",
 "web": "www.imbee.es",
 "address": "Barcelona",
 "tag": "Mensajeria instantanea",
 "email": "info@imbee.es",
 "googleplus": null,
 "facebook": null,
 "linkedin": null,
 "logoUpdated": "2014-10-26 12:29:49",
 "logoProfileUpdated": "2014-10-26 12:29:49",
 "updated": "2014-11-07 16:10:02",
 "subscribed": false
 */

@property (nonatomic) int                    identifier;
@property (nonatomic) bool                   subscribed;
@property (nonatomic) ModelState             modelState;
@property (strong, nonatomic) NSString*      idsha;
@property (strong, nonatomic) NSString*      name;
@property (strong, nonatomic) NSString*      logoUrl;
@property (strong, nonatomic) NSString*      phone;
@property (strong, nonatomic) NSString*      web;
@property (strong, nonatomic) NSString*      address;
@property (strong, nonatomic) NSString*      tag;
@property (strong, nonatomic) NSString*      email;

@property (strong, nonatomic) NSString*      appLogo;

@property (strong, nonatomic) UIColor*       primaryColor;
@property (strong, nonatomic) UIColor*       primaryDarkColor;
@property (strong, nonatomic) UIColor*       accentColor;
@property (strong, nonatomic) UIColor*       messageBackgroundColor;
@property (strong, nonatomic) UIColor*       fileBackgroundColor;

@property (strong, nonatomic) NSDate*        update;

@property (strong, nonatomic, readonly) CorporateServiceList*   services;
@property (strong, nonatomic, readonly) CorporateContactList*   members;

@property (nonatomic, strong) id<SyncHandlerDelegate> delegate;

- (instancetype)initWithQuery:(EQuery *)qry;
- (void)setDataFromQuery:(EQuery *)query;
- (NSDictionary *)extras;

- (void)subscribe;
- (void)unsubscribe;
- (void)syncContacts:(id<SyncHandlerDelegate>)delegate;
- (void)syncServices:(id<SyncHandlerDelegate>)delegate;
- (NSURL *)nsurlCorporationLogo;
- (UIImage *)placeholder;

- (NSComparisonResult)compare:(Corporation *)other;

@end
