//
//  TextContent.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 27/7/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

@interface TextContent : AbstractContent

@property (strong, nonatomic) NSString *plainText;

- (void)contentFromDictionary:(NSDictionary *)content;
- (NSDictionary *)dictionaryFromContent;

@end
