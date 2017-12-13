//
//  ContactManager.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 13/1/15.
//  Copyright (c) 2015 IMbee. All rights reserved.
//

#import "ContactList.h"
#import "Profile.h"

@interface ContactManager<__covariant ObjectType:IMContact *> : ContactList <AbstractListProtocol>

@property (nonatomic, strong, readonly) Profile *profile;

@end
