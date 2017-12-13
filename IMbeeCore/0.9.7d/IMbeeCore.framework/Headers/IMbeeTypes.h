//
//  IMbeeTypes.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 11/4/17.
//  Copyright © 2017 IMbee. All rights reserved.
//

#ifndef IMbeeTypes_h
#define IMbeeTypes_h

typedef enum {
    ExtendedAppStateTerminate,
    ExtendedAppStateBackground,
    ExtendedAppStateInactive,
    ExtendedAppStateForeground,
    ExtendedAppStateActive
} ExtendedApplicationState;

typedef enum {
    IMMPConnectError,
    IMMPDisconnected,
    IMMPConnecting,
    IMMPAuthenticated,
    IMMPSyncing,
    IMMPConnected
} IMMPState;

typedef enum {
    CSUnknown,
    CSActive,
    CSComposing,
    CSInactive,
    CSPause
} ChatState;

#endif /* IMbeeTypes_h */
