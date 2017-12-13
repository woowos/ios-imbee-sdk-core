//
//  ChatRoom_VC.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 24/05/14.
//  Copyright (c) 2014 nutec. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Speech/Speech.h>
#import <IMbeeCore/IMbeeCore.h>
#import <IMbeeUI/IMbeeUI.h>
#import <IMbeeUI/IMChat_Base_Cell.h>
#import <TTTAttributedLabel/TTTAttributedLabel.h>

typedef enum {
    IMSendButtonTypeText,
    IMSendButtonTypeSpeechToText,
    IMSendButtonTypeSpeechToTextCancel
} IMSendButtonType;

@protocol MessageListDelegate
@optional

- (void)buttonPressed:(ButtonContentPart * _Nonnull)button
            onMessage:(Message * _Nonnull)message;
- (void)prepareTableView:(UITableView * _Nonnull)tableView;
- (IMChat_Base_Cell * _Nullable)tableView:(UITableView * _Nonnull)tableView
                   cellForExternalContent:(ExternalContent * _Nonnull)content;
- (UIView * _Nullable)messageCellCustomization:(Message * _Nonnull)message;

/*
 - (void)singleTapMessage:(Message * _Nonnull)message;
 - (void)doubleTapMessage:(Message * _Nonnull)message;
 */

@end

@interface IMMessageListVC : BaseTableViewController <  UINavigationControllerDelegate,
                                                        UIImagePickerControllerDelegate,
                                                        UIPickerViewDelegate,
                                                        UIGestureRecognizerDelegate,
                                                        UITableViewDataSource,
                                                        UITableViewDelegate,
                                                        UITextViewDelegate,
                                                        SFSpeechRecognizerDelegate,
                                                        TTTAttributedLabelDelegate,
                                                        SyncHandlerDelegate>
{
    UIImagePickerController*    m_ImgPicker;
    Message*                    m_MessageSelected;
    
    NSMutableArray<Message *> *messageList;
    Conversation *lastConversation;
    
    UIImage *rightButtonTypeText, *rightButtonTypeSpeechToText, *rightButtonTypeSpeechToTextCancel;
    
    // Speech to text
    bool enableSpeechToText;
    bool speechToTextDone;
    SFSpeechAudioBufferRecognitionRequest *recognitionRequest;
    SFSpeechRecognitionTask *recognitionTask;
    AVAudioEngine *audioEngine;
}

//---Params:
@property (strong, nonatomic) Conversation*           conversation;
@property (strong, nonatomic) id<MessageListDelegate> messageDelegate;
@property (strong, nonatomic) SFSpeechRecognizer      *speechRecognizer;
@property (nonatomic)         bool                    deleteMessagesEnabled;
@property (nonatomic)         bool                    manipulateMessagesEnabled;

//---IBOutlets:
@property (strong, nonatomic) IBOutlet UITableView* tableView;

@property (strong, nonatomic) IBOutlet UIView*      view_ChatBlocked;
@property (strong, nonatomic) IBOutlet UILabel*     lbl_ChatBlocked;

@property (strong, nonatomic) IBOutlet UIView*      view_ToolBar;
@property (strong, nonatomic) IBOutlet UIView*      view_ContainerTextView;
@property (strong, nonatomic) IBOutlet UITextView*  m_TextView;
@property (strong, nonatomic) IBOutlet UIButton*    btn_SendMessage;

@property (strong, nonatomic) IBOutlet UIView*      view_DateBubble;
@property (strong, nonatomic) IBOutlet UILabel*     lbl_DateBubble;

@property (strong, nonatomic) IBOutlet UIView*      view_SpeechToText;
@property (strong, nonatomic) IBOutlet UIView*      view_SpeechToText_inner;
@property (strong, nonatomic) IBOutlet UIImageView* imageView_SpeechToText_cancel;

@property (strong, nonatomic) IBOutlet UIView*      view_CustomizableSpace;

@property (strong, nonatomic) IBOutlet NSLayoutConstraint* heightHPGrowingTextView;

@property (strong, nonatomic) Message* messageToForward;

@property (nonatomic) bool textViewDecoration;

- (IBAction)sendMessage_Pressed:(id)sender;
- (IBAction)moreOptions_Pressed:(id)sender;
- (IBAction)hideKeyboard:(id)sender;
- (IBAction)unwindToViewControllerNameHere:(UIStoryboardSegue *)segue;

- (void)showMoreOptions:(Message * _Nonnull)m fromSender:(id)sender;

// UI Customizations
- (void)setSpeechToTextEnabled:(bool)enable;
- (void)setRightButtonImage:(UIImage * _Nonnull)image forType:(IMSendButtonType)type;

@end
