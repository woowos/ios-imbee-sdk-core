//
//  TaskResponse.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 24/8/15.
//  Copyright (c) 2015 IMbee. All rights reserved.
//

#import <Foundation/Foundation.h>

@class Task;

@interface TaskResponse : NSObject

@property (nonatomic) bool              isJSON;
@property (nonatomic) bool              succeed;

@property (strong, nonatomic) id        processedObj;
@property (strong, nonatomic) id        body;
@property (strong, nonatomic) Task *    task;

// TODO: Per compatibilitat - s'ha de millorar
@property (nonatomic) unsigned int              code;
@property (nonatomic) float                     time;
@property (nonatomic) bool                      connectionHasFailed;

@property (strong, nonatomic) NSString*         message;
@property (strong, nonatomic) NSData*           rawData;

@end
