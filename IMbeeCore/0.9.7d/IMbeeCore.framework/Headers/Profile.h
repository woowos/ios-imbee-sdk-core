//
//  Profile.h
//  IMbee
//
//  Created by jordib on 15/07/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import "IMContact.h"

typedef enum {
    InstallationCompleted = 0,
    InstallationNeedUpdate = ~7889,
    InstallationFailed = 7889
} InstallationStatus;

#define is_user_registered_successfully(prof) ([prof.apiKey length] > 0 && \
                                               [prof.woowosUUID length] > 0 && \
                                                (prof.installationCompleted == InstallationCompleted || prof.installationCompleted == InstallationNeedUpdate))

@interface Profile : IMContact

@property (nonatomic, strong) NSString* hardwareId;
@property (nonatomic, strong) NSString* apiKey;
@property (nonatomic, strong) NSString* password;
@property (nonatomic, strong) Corporation *internalInACorportaion;
@property (nonatomic, strong) Corporation *promotedInACorportaion;
@property (nonatomic) InstallationStatus installationCompleted;

- (void)obtainProfileAndDelegate:(id<SyncHandlerDelegate>)delegate;
- (void)updateProfile:(NSString *)nickname delegate:(id<SyncHandlerDelegate>)delegate;
- (void)updateAvatar:(NSData *)image delegate:(id<SyncHandlerDelegate>)delegate;

- (void)copyDataTo:(Profile *)newProfile;

// Registration
- (void)registerWithPhone:(NSString *)phone andCountryCode:(NSString *)countryCode delegate:(id<SyncHandlerDelegate>)delegate;
- (void)registerWithEmail:(NSString *)email delegate:(id<SyncHandlerDelegate>)delegate;
- (void)validateWithApiKey:(NSString *)apiKey andIdsha:(NSString *)idsha andSMSCode:(NSString *)sms delegate:(id<SyncHandlerDelegate>)delegate;

@end
