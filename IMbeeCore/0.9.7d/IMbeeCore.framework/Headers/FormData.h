//
//  File.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 19/11/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FormData : NSObject

@property (strong, nonatomic) NSData    *data;
@property (strong, nonatomic) NSString  *contentType;
@property (strong, nonatomic) NSString  *contentDisposition;

- (instancetype)initWithName:(NSString *)name;
- (void)setDataFromString:(NSString *)data;

@end
