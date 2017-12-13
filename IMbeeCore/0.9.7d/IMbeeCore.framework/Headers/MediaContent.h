//
//  MediaContent.h
//  IMbeeCore
//
//  Created by Jordi Masip i Riera on 27/7/17.
//  Copyright © 2017 Jordi Masip i Riera. All rights reserved.
//

@interface MediaContent : AbstractContent

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) NSString *media_type;
@property (nonatomic)         double aspect;

- (void)contentFromDictionary:(NSDictionary *)content;
- (NSDictionary *)dictionaryFromContent;

- (void)uploadMediaData:(NSData *)data delegate:(id<SyncHandlerDelegate>)delegate;
- (void)downloadMediaDataWithPriority:(TaskPriority)priority;

@end
