//
//  AbstractContent.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 9/6/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Message;

@interface AbstractContent : NSObject

@property (strong, nonatomic) Message *message;

- (instancetype)initWithContent:(NSDictionary *)content;

- (void)contentFromDictionary:(NSDictionary *)content;
- (NSDictionary *)dictionaryFromContent;
- (NSString *)representation;
- (NSArray<NSString *> *)types;
+ (NSArray<NSString *> *)types;

@end
