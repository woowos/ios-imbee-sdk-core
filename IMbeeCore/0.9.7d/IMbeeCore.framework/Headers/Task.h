//
//  Task.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 24/8/15.
//  Copyright (c) 2015 IMbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TaskResponse.h"

@class Task;

#define invoke_taskDone_delegate(task, response) \
    if ([self.delegate respondsToSelector:@selector(task:doneWithResponse:)]) { \
        [self.delegate task:task doneWithResponse:response]; } \
    else { \
        /*[NSException raise:NSStringFromClass([self class]) format:@"syncDone delegate not found!"];*/ }

typedef enum {
    TaskTypeOnlyProcess,
    TaskTypeDownloadAndProcess
} TaskType;

@protocol TaskDoneDelegate <NSObject>

- (void)task:(Task *)task doneWithResponse:(TaskResponse *)response;

@end

@protocol TaskProtocol <NSObject>

- (bool)start;
- (bool)processResponse:(TaskResponse *)response;
- (void)task:(Task *)task doneWithResponse:(TaskResponse *)response;
- (bool)loudyCrashOnException;

@end

typedef enum {
    VeryLow         = 1 << 0,    // Es posa ben bé al final
    Low             = 1 << 1,    // Es posa cal al final
    Default         = 1 << 2,    // Es posa al final de la pila, davant dels de prioritat Low
    Hight           = 1 << 3,    // S'executa just després de que quedi un lloc a la cua d'execució
    Now             = 1 << 4     // S'executa a l'instant (independenment del que ja s'està executant)
} TaskPriority;

@interface Task : NSObject <TaskProtocol> {
    NSString *identifier;
}

@property (nonatomic) bool          isProcessed;
@property (nonatomic) TaskType      taskType;
@property (nonatomic) TaskPriority  priority;
@property (nonatomic) int16_t       processAttemps; /* # d'intents realitzats per processar la tasca */
@property (nonatomic) int16_t       downloadAttemps; /* # d'intents realitzats per baixar la tasca */

@property (nonatomic, strong) id delegate;
@property (nonatomic, strong) TaskResponse* response;
@property (nonatomic, strong) NSString*     uid;

@end
