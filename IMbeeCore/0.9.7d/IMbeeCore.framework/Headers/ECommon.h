//
//  ECommon.h
//
//  Created by Jordi Masip i Riera  (c) on 24/02/12.
//  Copyright (c) 2012 Jordi Masip i Riera  (c) Software. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ECommon : NSObject

+ (int)datetime2timestamp:(NSString *)datetime;
+ (NSString *)formatDate:(NSDate *)date;
+ (NSString *)formatDate:(NSDate *)date withFormat:(NSString *)format;
+ (NSString *)formatDate:(NSDate *)date withStyle:(NSDateFormatterStyle)style;
+ (NSString *)formatDate:(NSDate *)date forCurrentLocaleWithFormat:(NSString *)format;
+ (NSString *)formatDateTime:(NSDate *)date withDateStyle:(NSDateFormatterStyle)dateStyle andTimeStyle:(NSDateFormatterStyle)timeStyle;
+ (NSString *)formatDateTime:(NSDate *)date;
+ (NSDate *)dateFromString:(NSString *)str withFormat:(NSString *)format;
+ (NSDate *)dateFromString:(NSString *)str withFormat:(NSString *)format andLocale:(NSString *)locale;

+ (void)showNetworkActivityIndicator;
+ (void)hideNetworkActivityIndicator;

+ (void)initAppLanguage;
+ (void)setAppLanguage:(NSString *)l;
+ (NSString *)getLocalizedKey:(NSString *)key alter:(NSString *)alternate;

+ (BOOL)isValidEmail:(NSString *)checkString;
+ (BOOL)isNumeric:(NSString *)inputString;

+ (NSString *)documentsPath;
+ (NSString *)getStringDateAgo:(NSString *)since_date;
+ (NSURL *)getResourcesBasePathForWebView;

+ (NSURLConnection *)createURLMultipartFormDataConnectionTo:(NSString *)host path:(NSString *)path delegate:(id)delegate headers:(NSMutableDictionary *)headers body:(NSMutableDictionary *)dict;
+ (NSURLConnection *)createURLConnectionTo:(NSString *)host path:(NSString *)path delegate:(id)delegate body:(NSData *)body headers:(NSDictionary *)headers contentType:(NSString *)contentType timeout:(NSTimeInterval)timeout andHttpMethod:(NSString *)httmethod;

+ (NSString *)getURLFilename:(NSString *)str;

+ (void)logNSDictionary:(NSDictionary *)dict;

+ (NSString *)getAppVersion;
+ (NSString *)getAppVersionBuild;

+ (BOOL)isWideScreen;

+ (NSString *)createUUID;

+ (NSString *)sha1:(NSString *)input;

@end

@interface UIColor (SomeExtras)

+ (UIColor *)colorWithR:(CGFloat)red G:(CGFloat)green B:(CGFloat)blue A:(CGFloat)alpha;

@end
