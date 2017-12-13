//
//  CorporationData.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 4/1/15.
//  Copyright (c) 2015 IMbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IMContact;
@class Corporation;

@interface CorporationData : NSObject {
    BOOL containsCorpData;
    NSString *corporationId;
}

/*
 "web": "www.imbee.es",
 "phone": "12345678",
 "mobilePhone": "87654321",
 "emailPersonal": "ignasicasanovas@gmail.com",
 "emailWork": "ignasicasanovas@imbee.es",
 "twitter": "@icasanovas",
 "skype": "ignasi.casanovas",
 "linkedin": "http:\/\/www.linkedin.com",
 "facebook": "http:\/\/www.facebook.com",
 "googlePlus": "http:\/\/www.google.com",
 "address": "Casanova 154, entlo 3a 08036 Barcelona",
 "professionalSummary": "porofessional summary askhdas aoshjdoasih saodhasoihd\r\nshdkhs. asdhasidh hasiodhasoi hjjsapd jsl",
 */

// És el contacte al qual pertany aquesta informació corporativa
@property (weak, nonatomic) IMContact*          contact;

@property (strong, nonatomic) Corporation*      corporation;
@property (strong, nonatomic) NSString*         name;
@property (strong, nonatomic) NSString*         surname;
@property (strong, nonatomic) NSString*         position;
@property (strong, nonatomic) NSString*         group;
@property (strong, nonatomic) NSString*         web;
@property (strong, nonatomic) NSString*         phone;
@property (strong, nonatomic) NSString*         mobilePhone;
@property (strong, nonatomic) NSString*         emailPersonal;
@property (strong, nonatomic) NSString*         emailWork;
@property (strong, nonatomic) NSString*         twitter;
@property (strong, nonatomic) NSString*         skype;
@property (strong, nonatomic) NSString*         linkedin;
@property (strong, nonatomic) NSString*         facebook;
@property (strong, nonatomic) NSString*         googlePlus;
@property (strong, nonatomic) NSString*         address;
@property (strong, nonatomic) NSString*         professionalSummary;
@property (strong, nonatomic) NSString*         avatarPath;

- (instancetype)initWithContact:(IMContact *)contact;
- (instancetype)initWithContact:(IMContact *)contact andJSON:(NSDictionary *)dict;
- (void)setDataFromJSON:(NSDictionary *)dict;
- (void)updateDataFromCorporationData:(CorporationData *)cd;
- (BOOL)containsCorpData;
- (NSMutableDictionary *)getCorporationData;
- (NSString *)getCorporationDataAsJSONString;
- (NSString *)getCorporationName;
- (NSString *)getJobTitle;
- (NSString *)getJobTitleAndCorporationName;

@end
