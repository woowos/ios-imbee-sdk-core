//
//  CardContent.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 7/6/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AbstractContent.h"
#import "ButtonContentPart.h"

@class Card;

@interface CardContent : AbstractContent

@property (strong, nonatomic) NSArray<Card *> *cards;

@end

@interface Card : NSObject

@property (strong, nonatomic) NSString *imageUrl;
@property (strong, nonatomic) NSString *title;
@property (strong, nonatomic) NSString *webUrl;
@property (strong, nonatomic) NSString *text;

@property (strong, nonatomic) NSArray<ButtonContentPart *> *buttons;

- (void)contentFromDictionary:(NSDictionary *)content;
- (NSDictionary *)dictionaryFromContent;

@end
