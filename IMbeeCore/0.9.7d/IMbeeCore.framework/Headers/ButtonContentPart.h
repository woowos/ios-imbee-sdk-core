//
//  ButtonContentPart.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 12/6/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ButtonContentPart : NSObject

@property (strong, nonatomic) NSString *type;
@property (strong, nonatomic) NSString *label;
@property (strong, nonatomic) NSString *payload;

- (void)contentFromDictionary:(NSDictionary *)content;
- (NSDictionary *)dictionaryFromContent;

@end
