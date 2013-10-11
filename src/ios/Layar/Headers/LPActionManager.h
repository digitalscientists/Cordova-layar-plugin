//
//  LPActionManager.h
//  layarplayerinternal
//
//  Created by Nikita Ivaniushchenko on 1/25/12.
//  Copyright (c) 2012 Layar. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LSAction;
@class LPActionRequest;
@class LPAsyncActionRequest;
@class LPServiceProvider;

@protocol LPActionManagerDelegate <NSObject>

- (void)textRequestStarted:(LPActionRequest*)textRequest;
- (void)textRequestCompletedWithResponse:(NSString*)response;
- (void)textRequest:(LPActionRequest*)textRequest failedWithError:(NSError*)error;

- (void)asyncRequestStarted:(LPAsyncActionRequest*)asyncRequest;
- (void)asyncRequestCompletedWithResponse:(NSString*)response andAction:(LSAction*)action;
- (void)asyncRequest:(LPAsyncActionRequest*)asyncRequest failedWithError:(NSError*)error;

- (void)performAudioActionWithUrl:(NSString*)url;
- (void)performVideoAction:(LSAction*)action;
- (void)performWebAction:(LSAction*)action;
- (void)performVCardAction:(LSAction*)action;
- (void)performSMSAction:(LSAction*)action;

- (void)applicationCannotOpenActionUrl:(NSString*)url;

- (void)performLayerAction:(LSAction*)action;

- (void)performShareAction:(LSAction*)action;
- (void)performScreenshotAction:(LSAction*)action;

@optional

- (void)actionPerformed:(LSAction*)action;
- (void)actionWasNotPerformed:(LSAction*)action;
- (void)performTakeMeThereAction:(LSAction*)action;
- (BOOL)autoTriggerAlertsEnabled;

@end

@interface LPActionManager : NSObject
{
	LPAsyncActionRequest *asyncRequest;
	LPActionRequest *textRequest;
	
	id<LPActionManagerDelegate> delegate;
	
	NSString *countryCode;
	NSString *localCountryCode;
}

@property (nonatomic, retain) LPAsyncActionRequest *asyncRequest;
@property (nonatomic, retain) LPActionRequest *textRequest;

@property (nonatomic, assign) id<LPActionManagerDelegate> delegate;

@property (nonatomic, retain) NSString *countryCode;
@property (nonatomic, retain) NSString *localCountryCode;

- (id)initWithServiceProvider:(LPServiceProvider *)theServiceProvider;

/**
 * @brief The text request completion callback
 */
- (void)textRequestCompleted:(NSNotification*)notification;

/**
 * @brief The text request failure callback
 */
- (void)textRequestFailed:(NSNotification*)notification;

/**
 * @brief The text request cancelation callback
 */
- (void)textRequestCancelled:(NSNotification*)notification;

/**
 * @brief The async request completion callback
 */
- (void)asyncRequestCompleted:(NSNotification*)notification;

/**
 * @brief The async request failure callback
 */
- (void)asyncRequestFailed:(NSNotification*)notification;

/**
 * @brief The async request cancelation callback
 */
- (void)asyncRequestCancelled:(NSNotification*)notification;

/**
 * @brief Reciever for action fired notification
 */
- (void)actionFired:(NSNotification*)notification;

/**
 * @brief Perform an action
 */
- (void)performAction:(LSAction*)action userInfo:(NSDictionary*)userInfo;

/**
 * @brief Perform triggered action
 */
- (void)performTriggeredAction:(LSAction*)action userInfo:(NSDictionary*)userInfo;

/**
 * @brief Perform an audio action
 */
- (void)performAudioActionWithUrl:(NSString*)url;

/**
 * @brief Perform a video action
 */
- (void)performVideoAction:(LSAction*)action;

/**
 * @brief Perform a web action
 */
- (void)performWebAction:(LSAction*)action;

/**
 * @brief Perform a take me there aciton
 */
- (void)performTakeMeThereAction:(LSAction*)action;

/**
 * @brief Perform a text action
 */
- (void)performTextAction:(LSAction*)action;

/**
 * @brief Perform a async action
 */
- (void)performAsyncAction:(LSAction*)action;

/**
 * @brief Stops all actions
 */
- (void)stopAllActions;

/**
 * @brief Perform an internal action
 */
- (void)performInternalAction:(LSAction*)action;

/**
 * @brief Perform a share action
 */
- (void)performShareAction:(LSAction*)action;

/**
 * @brief Perform an screenshot action
 */
- (void)performScreenshotAction:(LSAction*)action;

/**
 * @brief Shows alert view for action
 */
- (void)showAlertViewForAction:(LSAction*)action andUserInfo:(NSDictionary*)userInfo;

@end
