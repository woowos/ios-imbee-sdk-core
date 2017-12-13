//
//  MessageEnums.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 10/4/17.
//  Copyright © 2017 IMbee. All rights reserved.
//

#ifndef MessageEnums_h
#define MessageEnums_h

#define MESSAGE_STATE_LEN (5)
#define MESSAGE_STATE_SENTINEL ((MessageState) 2134973)

// Macros per modificar el tipus 'MessageInternalFlag'
#define __MESSAGEFLAG_ADD_MULTIPLE_FLAGS(mflags, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) \
    (mflags |= (_1 | _2 | _3 | _4 | _5 | _6 | _7 | _8 | _9))
#define MESSAGEFLAG_ADD_MULTIPLE_FLAGS(mflags, ...) \
    __MESSAGEFLAG_ADD_MULTIPLE_FLAGS(mflags, __VA_ARGS__, 0, 0, 0, 0, 0, 0, 0, 0, 0)
#define MESSAGEFLAG_ADD_FLAG(mflags, flag) MESSAGEFLAG_ADD_MULTIPLE_FLAGS(mflags, flag)
#define MESSAGEFLAG_CONTAINS_FLAG(mflags, flag) ((mflags & flag) != 0)
#define MESSAGEFLAG_INIT 0

// Macros per modificar el tipus 'MessageInternalFlag' directament del missatge (per compatibilitat)
#define MESSAGE_ADD_MULTIPLE_FLAGS(m, ...) MESSAGEFLAG_ADD_MULTIPLE_FLAGS(m.internalFlags, __VA_ARGS__)
#define MESSAGE_ADD_FLAG(m, flag) MESSAGE_ADD_MULTIPLE_FLAGS(m, flag)
#define MESSAGE_REMOVE_FLAG(m, flag) (m.internalFlags &= ~flag)
#define MESSAGE_CONTAINS_FLAG(m, flag) MESSAGEFLAG_CONTAINS_FLAG(m.internalFlags, flag)

#define msg_action_istypeof_ack(action) \
    (action >= MessageCategoryControl && \
     action <= MessageCategoryControl + 99)

#define msg_action_istypeof_content(action) \
    (action >= MessageCategoryContent && \
     action <= MessageCategoryContent + 99)

#define msg_action_istypeof_chat_releated(action) \
    (action >= MessageCategoryChatReleated && \
     action <= MessageCategoryChatReleated + 99)

#define msg_action_istypeof_call(action) \
    (action >= MessageCategoryCall && \
     action <= MessageCategoryCall + 89)

#define msg_action_istypeof_typing(action) \
    (action >= MessageCategoryTyping && \
     action <= MessageCategoryTyping + 9)

#define msg_action_istypeof_internal(action) \
    (action >= MessageCategoryInternal && \
    action <= MessageCategoryInternal + 99)

typedef enum {
    MessageStateNone                =  0,
    MessageStateSent                =  1,
    MessageStateDelivered           =  2,
    MessageStateRead                =  3,
    MessageStateDeleted             =  11,
    MessageStateStubVal             =  100 // aquest estat s'utilitza per inicialitzar MessageReadState quan es busca el valor mínim en comú de tots els groupStatus
} MessageState;

typedef enum {
    MessageCategoryUnknown          = 0,
    MessageCategoryContent          = 100,
    MessageCategoryControl          = 200,
    MessageCategoryChatReleated     = 300,
    MessageCategoryCall             = 600,
    MessageCategoryTyping           = 690,
    MessageCategoryInternal         = 99900
} MessageCategory;

typedef enum {
    MessageFlagEmpty                        = (0 >> 0),
    MessageFlagVolatile                     = (1 << 0),
    MessageFlagInvisible                    = (1 << 1)
} MessageFlag;

typedef enum {
    MessageInternalFlagFromChatHistory      = (1 << 0),
    MessageInternalFlagFromChatFuture       = (1 << 1),
    MessageInternalFlagFromXMPP             = (1 << 3),
    MessageInternalFlagFromXMPPAsCarbon     = (1 << 4),
    MessageInternalFlagFromLocalDatabase    = (1 << 5)
} MessageInternalFlag;

typedef enum {
    MessageActionUnknown            = 0,
    
    MessageActionGenericContent     = MessageCategoryContent + 0,
    MessageActionText               = MessageCategoryContent + 1,
    MessageActionImage              = MessageCategoryContent + 2,
    MessageActionVideo              = MessageCategoryContent + 3,
    MessageActionFile               = MessageCategoryContent + 4,
    
    MessageActionDelivery           = MessageCategoryControl + 1,
    MessageActionRead               = MessageCategoryControl + 2,
    MessageActionDelete             = MessageCategoryControl + 3,
    
    MessageActionChatCreate         = MessageCategoryChatReleated + 1,
    MessageActionChatJoin           = MessageCategoryChatReleated + 2,
    MessageActionChatLeave          = MessageCategoryChatReleated + 3,
    MessageActionChatKick           = MessageCategoryChatReleated + 4,
    MessageActionChatInfoUpdate     = MessageCategoryChatReleated + 5,
    MessageActionChatChangeAdmin    = MessageCategoryChatReleated + 6,
    
    MessageActionCreateRoomAndCall  = MessageCategoryCall + 1,
    MessageActionEnterRoom          = MessageCategoryCall + 2,
    MessageActionLeaveRoom          = MessageCategoryCall + 3,
    MessageActionUserBusy           = MessageCategoryCall + 4,
    MessageActionWebRTC             = MessageCategoryCall + 5,
    
    MessageActionTypingOn           = MessageCategoryTyping + 1,
    MessageActionTypingOff          = MessageCategoryTyping + 2,
    
    /* Internal Actions */
    MessageActionSpin               = MessageCategoryInternal + 1,
    MessageActionVisualTyping       = MessageCategoryInternal + 2,
    MessageActionDate               = MessageCategoryInternal + 3
    
} MessageAction;

#endif /* MessageEnums_h */
