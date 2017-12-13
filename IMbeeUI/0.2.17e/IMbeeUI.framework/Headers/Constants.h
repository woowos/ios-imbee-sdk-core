//
//  Constants.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 16/5/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

#ifndef Constants_h
#define Constants_h

#define OBJC_ARC_ENABLED                1

#define CHAT_HOUR_FORMAT                @"HH:mm"

#define IMAGE_CORNER_RADIUS             5.0
#define MESSAGE_CORNER_RADIUS           4.0

#define CHAT_SYSTEM_MSG_TEXT_MORE           @"@more"
#define CHAT_SYSTEM_MSG_TEXT_DATE           @"@date#"
#define CHAT_SYSTEM_MSG_TEXT_LEAVES         @"@leaves#"
#define CHAT_SYSTEM_MSG_TEXT_KICKS          @"@kicks#"
#define CHAT_SYSTEM_MSG_TEXT_WELCOME        @"@welcome"
#define CHAT_SYSTEM_MSG_TEXT_JOINS          @"@joins#"
#define CHAT_SYSTEM_MSG_TEXT_GROUPCHAT_IMG  @"@image#"

#define CHAT_IMAGE_MAX_SIZE_HI              1200
#define CHAT_IMAGE_MAX_SIZE_LO              32
#define CHAT_IMAGE_COMPRESSION_QUALITY_LO   0.4
#define CHAT_IMAGE_COMPRESSION_QUALITY_HI   0.75

// XMPP Notifications
#define NOTIFICATION_IMMP_STATE_CHANGED     @"IMMP_STATE_CHANGED"

// User-Chat-Msg related notifications
#define NOTIFICATION_MSGLIST_MORE_MESSAGES  @"MSGLIST_MORE_MESSAGES"
#define NOTIFICATION_NEW_MESSAGES           @"CONVERSATION_NEW_MESSAGES"
#define NOTIFICATION_MESSAGE_UPDATED        @"CONVERSATION_MESSAGE_UPDATED"
#define NOTIFICATION_CHAT_STATES            @"CONVERSATION_CHAT_STATES"
#define NOTIFICATION_CHAT_INFO_UPDATE       @"CHAT_INFO_UPDATE"
#define NOTIFICATION_CONTACT_UPDATE         @"CONTACT_UPDATE" // Contact info or Contact type
#define NOTIFICATION_CORPORATION_UPDATE     @"CORPORATION_UPDATE"
#define NOTIFICATION_CORPORATION_SUBS_STATE @"CORPORATION_SUBS_STATE"
#define NOTIFICATION_CALL_INCOMING          @"NOTIFICATION_CALL_INCOMING"
#define NOTIFICATION_CALL_SIGNALING         @"NOTIFICATION_CALL_SIGNALING"

// System notifications
#define NOTIFICATION_APP_LIFECYCLE          @"NOTIFICATION_APP_LIFECYCLE"

//----------------Servers-----------------------

#define XMPP_HOSTNAME                   [FakeAppDelegate.imbeeConfig serverXmpp]
#define DOMAIN_WS                       [FakeAppDelegate.imbeeConfig serverAddress]
#define DOMAIN_ADMIN                    [FakeAppDelegate.imbeeConfig serverAdmin]
#define DOMAIN_WOOWOS_NAME              [FakeAppDelegate.imbeeConfig xmppUserDomain]

#define SERVER_ADDRESS                  [NSString stringWithFormat:@"https://%@", DOMAIN_WS]
#define SERVER_ADMIN                    [NSString stringWithFormat:@"https://%@", DOMAIN_ADMIN]


//----------------XMPP Server-----------------------
#define XMPP_DATETIME_FORMAT                @"yyyy/MM/dd HH:mm:ss.SSS"
#define XMPP_DATETIME_FORMAT_UTC            @"yyyy/MM/dd HH:mm:ss.SSSZ"
#define XMPP_MAM_DELAY_DATETIME_FORMAT      @"yyyy-MM-dd'T'HH:mm:ss.SSSZ"

#define XMPP_MESSAGE_CONTENT_IMAGE          @"::IMAGE::"
#define XMPP_MESSAGE_CONTENT_FILE           @"::FILE::"

#endif /* Constants_h */
