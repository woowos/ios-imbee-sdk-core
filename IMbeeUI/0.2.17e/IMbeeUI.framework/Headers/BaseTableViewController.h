//
//  BaseTableViewController.h
//  woowos
//
//  Created by Jordi Masip i Riera on 25/5/15.
//  Copyright (c) 2015 nutec. All rights reserved.
//

#import "BaseViewController.h"

typedef enum {
    ScrollViewStateStoped           = 0,
    ScrollViewStateDragging         = 1,
    ScrollViewStateScrolling        = 2,
    ScrollViewStateAnimating        = 4,
    ScrollViewStateDecelerating     = 8,
} scrollViewState_t;

typedef enum {
    TableViewStateReloadEnabled     = 0,
    TableViewStateEditing           = 1,
    TableViewStateNotVisible        = 2,
    TableViewStateInMotion          = 4,
} tableViewState_t;

typedef enum {
    TableViewVelocityNone           = 0,
    TableViewVelocityTurtle         = 1,
    TableViewVelocityModerate       = 2,
    TableViewVelocityFast           = 3,
    TableViewVelocityCosmic         = 4,
} tableViewVelocity_t;

typedef double timestamp_t;

typedef struct {
    CGPoint point;
    timestamp_t last_check;
    int last_velocity[3];
} previousScrollViewPoint_t;

@protocol BaseTableViewControllerProtocol
@required

- (UITableView *)tableView;

@optional

- (UISearchBar *)searchBar;

@end

@interface BaseTableViewController : BaseViewController<UITableViewDelegate, BaseTableViewControllerProtocol> {
    bool     shouldRefresh;
    bool     firstLoad;
    NSTimer *checkVelocity;
    
    timestamp_t lastScrollViewVelocityCalc;
}

@property (nonatomic) timestamp_t lastTableReloadData;

@property (nonatomic, strong) NSTimer* retryReloadData;

@property (nonatomic, readonly) int scrollViewVelocity;
@property (nonatomic, readonly) tableViewState_t tableViewState;
@property (nonatomic, readonly) scrollViewState_t scrollViewState;
@property (nonatomic, readonly) tableViewVelocity_t tableViewVelocity;
@property (nonatomic, readonly) previousScrollViewPoint_t scrollViewPosition;

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;

- (void)beforeReloadTableView:(UITableView *)tableView;
- (void)afterReloadTableView:(UITableView *)tableView;
- (void)checkTableViewReloadPolicy:(UIScrollView *)scrollView;
- (void)setReloadDataEnabled:(bool)enabled;
- (void)setShouldReloadData:(bool)shouldReload;
- (void)setupReloadDataTimer;
- (void)forceReloadData;
- (bool)reloadData;

- (void)set_tableViewState:(tableViewState_t)state;
- (void)clear_tableViewState:(tableViewState_t)state;
- (bool)contains_tableViewState:(tableViewState_t)state;

@end
