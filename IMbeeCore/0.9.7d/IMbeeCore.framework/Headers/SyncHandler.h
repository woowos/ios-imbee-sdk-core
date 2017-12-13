//
//  SyncHandler.h
//  IMbee
//
//  Created by Jordi Masip i Riera  (c) on 07/05/12.
//  Copyright (c) 2012 Jordi Masip i Riera  (c) Software. All rights reserved.
//

#import "Task.h"
#import "TaskResponse.h"

#define RESP_CODE_EXCEPTION         10010
#define RESP_CODE_CONNECTION_FAIL   10020
#define RESP_CODE_CANCELED          10030

#define invoke_progressChange_delegate(delegate, value, type) \
    if ([delegate respondsToSelector:@selector(progressChange:type:)]) { \
        [delegate progressChange:value type:type]; } \
    else { \
        /*[NSException raise:NSStringFromClass([self class]) format:@"progressChange delegate not found!"];*/ }

typedef enum {
    MULTIPART_CONNECTION = 0,
    FORM_CONNECTION,
    JSON_CONNECTION,
    SIMPLE_CONNECTION,
    DATA_CONNECTION
} SyncHandlerContentType;

typedef enum {
    ProgressTypeUploading,
    ProgressTypeDownloading
} ProgressType;

@protocol SyncHandlerDelegate <NSObject>

- (void)syncDone:(BOOL)success object:(id)obj handlerIdentifier:(NSString *)identifier;

@optional

- (void)progressChange:(float)value type:(ProgressType)type;

@end

@interface SyncHandler : Task <NSURLConnectionDataDelegate, SyncHandlerDelegate, TaskProtocol> {
    NSMutableData *_responseData;
    NSURLConnection *conn;
    NSURLResponse *urlResponse;
    
    bool cancelled;
    bool connectionDone;
    bool expectingJSONResponse;
}

@property (nonatomic) long offset;

- (instancetype)init:(id<SyncHandlerDelegate>)del;
- (SyncHandlerContentType)contentType;
- (NSString *)urlPath;

- (NSString *)server;

- (void)fillRequestParams:(NSMutableDictionary *)data;
- (void)fillHeaders:(NSMutableDictionary *)headers;

- (void)setParamDate:(NSDate *)date forKey:(NSString *)key inParams:(NSMutableDictionary *)data;
- (void)setParamDateTime:(NSDate *)date forKey:(NSString *)key inParams:(NSMutableDictionary *)data;
- (void)setParamBOOL:(BOOL)val forKey:(NSString *)key inParams:(NSMutableDictionary *)data;
- (void)setParamString:(NSString *)str forKey:(NSString *)key inParams:(NSMutableDictionary *)data;
- (void)cancel;
- (NSURLConnection *)createConnection:(SyncHandlerContentType)conn_type;
- (void)didReceiveData:(NSMutableData *)data;

+ (NSDate *)dateTimeFromJSONString:(NSString *)str;
+ (NSDate *)dateFromJSONString:(NSString *)str;
+ (NSString *)stringFromJSON:(id)val;
+ (int)intFromJSON:(id)val;
+ (double)doubleFromJSON:(id)val;
+ (bool)boolFromJSON:(id)val;
+ (NSDictionary *)dictionaryFromJSON:(id)val;
+ (NSArray *)arrayFromJSON:(id)val;
+ (void)defaultErrorHandler:(TaskResponse *)response;

@end
