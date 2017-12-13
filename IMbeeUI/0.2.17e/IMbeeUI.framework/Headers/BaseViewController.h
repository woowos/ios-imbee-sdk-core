//
//  BaseViewController.h
//  rankrunner
//
//  Created by Jordi Masip i Riera  (c) on 10/05/12.
//  Copyright (c) 2012 Jordi Masip i Riera  (c) Software. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol BaseViewControllerDelegate

- (BOOL)shouldShowUINotifications;
- (BOOL)shouldSetInteractivePopGestureRecognizer;

@end

typedef enum {
    ViewWillLoad,
    ViewDidLoad,
    ViewWillAppear,
    ViewDidAppear,
    ViewWillDisappear,
    ViewDidDisappear,
    ViewDidUnload
} ViewLoadState;

@interface BaseViewController : UIViewController <UIGestureRecognizerDelegate, BaseViewControllerDelegate> {
    ViewLoadState viewLoadState;
}

- (UIView *)mainView;
- (UIViewController *)mainViewController;
- (NSString *)customHeaderTitle;

- (void)renderHeader;
- (void)renderHeaderTitle:(NSString *)title;
- (void)renderColors;

@property (strong, nonatomic) IBOutlet UIView*    header;
@property (strong, nonatomic) IBOutlet UILabel*   header_title;

@end
