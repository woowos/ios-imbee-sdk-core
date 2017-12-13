//
//  QuickReplyContent.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 12/6/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

#import <IMbeeCore/IMbeeCore.h>

@interface QuickReplyContent : TextContent

@property (strong, nonatomic, readonly) NSArray<ButtonContentPart *> *buttons;

@end
