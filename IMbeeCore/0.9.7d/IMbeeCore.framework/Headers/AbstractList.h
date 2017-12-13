//
//  AbstractList.h
//  IMbee
//
//  Created by Jordi Masip i Riera on 24/12/14.
//  Copyright (c) 2014 IMbee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <pthread.h>
#import "IntersectionResult.h"
#import "ListFilter.h"

void init_bg_queue_abstract_list(void);

#define for_each_generic(class, al) \
    for (class *each = nil; each == nil; each = (id) self) \
        for (NSUInteger _i = 0; (each = [al objectAtIndex:_i]); ++_i)

typedef enum : NSUInteger {
    IMObserverAdd,
    IMObserverRemoved
} IMObserverEvent;

typedef void (^IMObserverBlock)(IMObserverEvent event, id obj, NSUInteger index);

@protocol AbstractListProtocol

@required

- (void)_initWithArray:(NSArray *)arr;
- (void)_doWithElementAlreadyInList:(id)el;
- (bool)_elementInList:(id)el;
- (bool)_elementIsValid:(id)el;
- (void)_add:(id)el;
- (bool)_saveAll:(NSArray *)all;
- (bool)_saveModified:(NSArray *)mods;
- (bool)_remove:(id)el;
- (bool)_reorder;
- (id)_createElementWithId:(NSString *)withId;
- (NSString *)_getIdentifierOfElement:(id)element;

@optional

- (int)_getNumericIdentifierOfElement:(id)element;

@end

@interface AbstractList<__covariant ObjectType> : NSObject {
    NSMutableArray<ObjectType> *arrContent;
    NSMutableDictionary<NSString *, ObjectType> *modified;
    NSMutableDictionary<NSString *, ObjectType> *dictContent;
    
    NSMutableArray<__kindof AbstractList *> *sublists;
    NSMutableArray<ListFilter *> *filters;
    NSMutableArray<IMObserverBlock> *observers;
    
    pthread_mutex_t generalLock;
    pthread_mutex_t arrayLock;
    pthread_mutex_t modifiedLock;
    
    int max_identifier;
}

@property (strong, nonatomic) NSString      *className;
@property (strong, nonatomic) AbstractList  *parent;

- (instancetype)init;
- (instancetype)initWithArray:(NSArray<ObjectType> *)arr;
- (NSUInteger)count;
- (instancetype)createChild;
- (bool)add:(ObjectType)el;
- (bool)addMultiple:(NSArray<ObjectType> *)elements;
- (void)addChildList:(AbstractList *)list;
- (void)addListFilter:(ListFilter *)filter;
- (NSArray<ObjectType> *)copyArray;
- (bool)containsObject:(ObjectType)object;
- (bool)remove:(ObjectType)el;
- (bool)remove:(ObjectType)el onlyMemory:(bool)onlyMemory;
- (void)removeWithId:(NSString *)withId;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeAll;
- (ObjectType _Nullable)objectAtIndex:(NSUInteger)index;
- (AbstractList *)childListAtIndex:(NSUInteger)index;
- (ObjectType _Nullable)first;
- (ObjectType _Nullable)last;
- (ObjectType _Nullable)lastObject __deprecated;
- (ObjectType)getWithId:(NSString * _Nonnull)withId;
- (bool)isElementValid:(ObjectType _Nullable)el;
- (bool)reorder;
- (void)reorderAsync;
- (void)reorderAsync:(void (^)(bool reordered))callback;
- (void)saveAll;
- (void)saveAllAsync;
- (void)saveModified;
- (void)saveModifiedAsync;
- (bool)setElementAsModified:(ObjectType _Nonnull)el;

- (void)addObserver:(IMObserverBlock)callback;
- (void)notifyObservers:(IMObserverEvent)event object:(id)obj atIndex:(NSInteger)index;
- (void)removeObserver:(IMObserverBlock)callback;

- (IntersectionResult *)intersection:(AbstractList *)list;
+ (void)clearIntersection:(IntersectionResult *)ir;

- (dispatch_queue_t)_bg_queue;

@end
