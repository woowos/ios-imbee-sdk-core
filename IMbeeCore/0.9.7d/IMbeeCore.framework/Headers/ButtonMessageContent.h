//
//  ButtonMessageContent.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 21/8/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

#import <IMbeeCore/IMbeeCore.h>

@interface ButtonMessageContent : TextContent

@property (strong, nonatomic, readonly) NSArray<ButtonContentPart *> *buttons;

@end
