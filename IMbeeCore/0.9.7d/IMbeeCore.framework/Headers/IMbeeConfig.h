//
//  IMbeeConfig.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 17/5/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IMbeeConfig : NSObject

@property (strong, nonatomic, readonly) NSString *serverAddress;    // @"dev-ws.imbee.es"
@property (strong, nonatomic, readonly) NSString *serverXmpp;       // @"dev-xmpp.imbee.es"
@property (strong, nonatomic, readonly) NSString *serverAdmin;      // @"dev-admin.imbee.es"
@property (strong, nonatomic, readonly) NSString *xmppUserDomain;   // @"woowos"
@property (strong, nonatomic, readonly) NSString *apiKey;           // @"s3cr3t"

- (instancetype)initWithServerAddress:(NSString *)serverAddress
                           serverXmpp:(NSString *)serverXmpp
                          serverAdmin:(NSString *)serverAdmin
                       xmppUserDomain:(NSString *)xmppUserDomain
                               apiKey:(NSString *)apiKey;

@end
