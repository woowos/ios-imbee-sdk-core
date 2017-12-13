//
//  CorporationList.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 17/12/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import "AbstractList.h"
#import "Corporation.h"

#define for_each_corporation(cl) for_each_generic(Corporation, cl)

typedef enum {
    CorporationPolicySubscribed,
    CorporationPolicyUnsubscribed,
    CorporationPolicyAll
} CorporationPolicy;

@interface CorporationList<__covariant ObjectType:Corporation *> : AbstractList <AbstractListProtocol> {
    CorporationPolicy policy;
}

- (instancetype)initWithPolicy:(CorporationPolicy)_policy;
- (void)setCorporation:(ObjectType)c subscribed:(bool)subscribed;
- (ObjectType)corporationWithWoowosId:(NSString *)woowosId;
- (ObjectType)corporationWithWoowosIdOrCreate:(NSString *)woowosId;
- (ObjectType)corporationWithWoowosIdOrCreate:(NSString *)woowosId fromQuery:(EQuery *)qry;

- (void)requestCorporationListAsync:(void (^)(bool success))callback;

@end
