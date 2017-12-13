//
//  ExternalContent.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 12/9/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ExternalContent : AbstractContent

@property (strong, nonatomic) NSString *externalType;
@property (strong, nonatomic) NSDictionary *externalData;

- (void)contentFromDictionary:(NSDictionary *)content;
- (NSDictionary *)dictionaryFromContent;

@end
