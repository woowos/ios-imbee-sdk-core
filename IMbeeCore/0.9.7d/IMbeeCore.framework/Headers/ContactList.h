//
//  ContactList.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 17/11/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AbstractList.h"

#define for_each_contact(cml) for_each_generic(IMContact, cml)

@interface ContactList<__covariant ObjectType:IMContact *> : AbstractList <AbstractListProtocol>

- (ObjectType)contactWithWoowosId:(NSString *)woowosId;
- (ObjectType)contactWithWoowosIdOrCreate:(NSString *)woowosId withType:(ContactType)type;
- (ObjectType)contactWithWoowosIdOrCreate:(NSString *)woowosId fromQuery:(EQuery *)qry;
- (ContactList *)searchContactsContains:(NSString *)search;

@end
