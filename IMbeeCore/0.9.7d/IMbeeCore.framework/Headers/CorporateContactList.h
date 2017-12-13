//
//  ParcialContactList.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 31/12/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import "ContactList.h"
#import "Corporation.h"

@interface CorporateContactList<__covariant ObjectType:IMContact *> : ContactList {
    NSMutableDictionary *sections;
    pthread_mutex_t sectionsLock;
}

@property (nonatomic) bool listWithSections;
@property (nonatomic, strong, readonly) Corporation *corporation;

- (instancetype)init __unavailable;
- (instancetype)initWithArray:(NSArray *)arr __unavailable;
- (instancetype)initWithCorporation:(Corporation *)c;
- (instancetype)initWithCorporation:(Corporation *)c andMembers:(NSArray<IMContact *> *)arr;

- (void)removeEmptySections;
- (NSArray *)sections;
- (NSUInteger)countSections;
- (NSUInteger)countInSection:(NSUInteger)section;
- (IMContact *)contactInIndexPath:(NSIndexPath *)indexPath;
- (CorporateContactList *)searchContactsWithName:(NSString *)search;

@end
