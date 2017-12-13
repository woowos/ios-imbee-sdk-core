//
//  IMChat_Base_Cell.h
//  IMbee
//
//  Created by jordib on 06/08/14.
//  Copyright (c) 2014 Teracat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IMbeeCore/IMbeeCore.h>

@class TTTAttributedLabel;
@class IMMessageListVC;

@interface IMChat_Base_Cell : UITableViewCell {
    UILongPressGestureRecognizer*   m_GR_LongPress;
    UITapGestureRecognizer*         m_GR_DoubleTap;
    UITapGestureRecognizer*         m_GR_SingleTap;
}

//---Params:
@property (weak, nonatomic) Message*                        message;
@property (weak, nonatomic) IMMessageListVC*                chatRoom_VC;

// Default (optional)
@property (strong, nonatomic) IBOutlet UIView               *viewBubble;
@property (strong, nonatomic) IBOutlet UIView               *viewLeftSpace;
@property (strong, nonatomic) IBOutlet UILabel              *lbl_User;
@property (strong, nonatomic) IBOutlet NSLayoutConstraint   *topSpaceLabel;

//---Functions:
- (void)setupCell;
- (void)makeLinksTappables:(TTTAttributedLabel *)label;

@end
