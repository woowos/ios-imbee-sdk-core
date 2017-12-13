//
//  IMbeeUI.h
//  IMbeeUI
//
//  Created by Jordi Masip i Riera on 11/4/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for IMbeeUI.
FOUNDATION_EXPORT double IMbeeUIVersionNumber;

//! Project version string for IMbeeUI.
FOUNDATION_EXPORT const unsigned char IMbeeUIVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <IMbeeUI/PublicHeader.h>

#import <IMbeeUI/BaseTableViewController.h>
#import <IMbeeUI/IMMessageListVC.h>
#import <IMbeeUI/IMChat_Base_Cell.h>

@interface IMbeeUI : NSObject

+ (NSBundle * _Nonnull)resourcesBundle;
+ (IMMessageListVC * _Nonnull)presentConversation:(Conversation * _Nonnull)conv
                                         intoView:(UIView * _Nonnull)container
                                 onViewController:(UIViewController * _Nonnull)parent
                                      andDelegate:(id<MessageListDelegate> _Nullable)delegate;

+ (void)setPrimaryColor:(UIColor *)color;
+ (void)setRightMessageBackgroundColor:(UIColor *)color;
+ (void)setRightMessageTextColor:(UIColor *)color;
+ (void)setLeftMessageBackgroundColor:(UIColor *)color;
+ (void)setLeftMessageTextColor:(UIColor *)color;
+ (void)setMessageRadius:(float)radius;
+ (void)setMessageFont:(UIFont *)font;

@end
