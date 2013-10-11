//
//  LPPOIViewController.h
//  
//
//  Created by Nikita Ivaniushchenko on 1/20/12.
//  Copyright (c) 2012 Ciklum. All rights reserved.
//

#import <MessageUI/MessageUI.h>
#import <AddressBookUI/AddressBookUI.h>

// LayarCore imports
#import "LSPOIView.h"

// Local imports

#if !defined(LPINTERNALBUILD) && !defined(WHITELABEL)
#import "LayarPlayerDelegate.h"
#endif

#import "LPStatusView.h"
#import "LPActionManager.h"
#import "LPCachingViewController.h"
#import "LPActionSheet.h"

#if defined(LPINTERNALBUILD)
#import "LPLayerSettingsViewController.h"
#endif

#define kOneDayInSeconds (24. * 60. * 60.)

@class LSAction;
@class LSRequest;
@class LSLayer;
@class LSPOI;
@class LSPOIModel;
@class LSPOIRenderable;
@class LSPOIParser;
@class LSLayerDetailsParser;

@class LPActionManager;
@class LPAudioPlayer;
@class LPWebViewController;
@class LPMessageView;

@class LPLocalyticsSession;
@class LPRequestConfigurationManager;

@class LPServiceProvider;

@interface LPPOIViewController : LPCachingViewController <	UIActionSheetDelegate, UIAlertViewDelegate, MFMailComposeViewControllerDelegate, LSPOIView, LPStatusViewDelegate,
#if defined(LPINTERNALBUILD)
															LPLayerSettingsViewControllerDelegate,
#endif
															LPActionManagerDelegate,
															ABNewPersonViewControllerDelegate,
															MFMessageComposeViewControllerDelegate>
{
#if !defined(LPINTERNALBUILD) && !defined(WHITELABEL)
	id <LayarPlayerDelegate> delegate;
#endif

	LSAction *layerAction;
	LPActionManager *actionManager;
	
	LSPOIModel *model;
	LSLayer *layer;
	LSRequest *poiRequest;
	
	NSString *countryCode;
	NSString *localCountryCode;

	NSString *oauthConsumerKey;
	NSString *oauthConsumerSecret;
	
	NSMutableDictionary *customParametersForPOIRequest;
	
	NSTimer *poiRequestTimer;
	int refreshInterval;
	BOOL fullRefresh;
	
	LPAudioPlayer *audioPlayer;
	LPMessageView *messageView;

	BOOL refreshPois;
	BOOL closing;
	BOOL visible;
	BOOL showLayerAuthenticationPage;
	BOOL keepMessageOnScreen;
	
	LPActionSheet *layerActionSheet;
	UIActionSheet *poiActionSheet;
	NSArray *poiActions;
	
	BOOL transitionInProgress;

#if !defined(LPINTERNALBUILD) && !defined(WHITELABEL)
	LPLocalyticsSession *localyticsSession;
	LPRequestConfigurationManager *playerRequestConfigurationManager;
#endif

@protected
	NSTimer *messageViewTimer;
}

/**
 * @brief The action manager
 */
@property (nonatomic, retain) LPActionManager *actionManager;

/**
 * @brief The program delegate
 */
#if !defined(LPINTERNALBUILD) && !defined(WHITELABEL)
@property (nonatomic, assign) id <LayarPlayerDelegate> delegate;
#endif

/**
 * @brief POI request
 */
@property (nonatomic, retain) LSRequest *poiRequest;

/**
 * @brief The POI model
 */
@property (nonatomic, retain) LSPOIModel *model;

/**
 * @brief The currently loaded layer
 */
@property (nonatomic, retain) LSLayer *layer;

/**
 * @brief The country code parameter for Layar API requests
 */
@property (nonatomic, copy) NSString *countryCode;

/**
 * @brief The local country code parameter for Layar API requests
 */
@property (nonatomic, copy) NSString *localCountryCode;

/**
 * @brief The OAuth consumer key
 *
 * All network requests are signed using this key
 */
@property (nonatomic, copy) NSString *oauthConsumerKey;

/**
 * @brief The OAuth consumer secret
 *
 * All network requests are signed using this key
 */
@property (nonatomic, copy) NSString *oauthConsumerSecret;

/**
 * @brief Custom getPoi request parameters
 *
 * These are the custom parameters that are sent with the POI request
 */
@property (nonatomic, retain) NSMutableDictionary *customParametersForPOIRequest;

/**
 * @brief The audio player
 */
@property (nonatomic, retain) LPAudioPlayer *audioPlayer;

/**
 * @brief View controller that presented modal view controller
 */
@property (nonatomic, readonly) UIViewController *presentingParentViewController;

/**
 * @brief injectable facebook sdk wrapper
 */
@property (nonatomic, retain) LPServiceProvider* serviceProvider;

- (void)releaseViews;

/**
 * @brief Close the view
 *
 * This dismissed the modally presented view controller
 */
- (void)close:(id)sender;

/**
 * @brief Internet connection not available
 */
- (void)internetConnectionNotAvailable;

/**
 * @brief Call when application will background
 */
- (void)applicationWillResignActive;

/**
 * @brief Call when application did background
 */
- (void)applicationDidEnterBackground;

/**
 * @brief Call when application will enter foreground
 */
- (void)applicationWillEnterForeground;

/**
 * @brief Call when application resumes from background
 */
- (void)applicationDidBecomeActive;

/**
 * @brief Call when the application will terminate
 */
- (void)applicationWillTerminate;

/**
 * @brief Show layer settings
 */
- (void)showLayerAuthenticationPage;

/**
 * @brief Returns an array of layer-level action handlers (see LPLayerActionHandler)
 *
 * Layer action handlers are constructed based on layer actions array.
 */
- (NSArray*)layerActionHandlers;

/**
 * @brief Create layer action sheet for layer action handlers
 */
- (void)createLayerActionSheet;

/**
 * @brief Show layer action sheet
 */
- (void)showLayerActionSheet;

/**
 * @brief Handler for notifications about fired actions
 */
- (void)actionFired:(NSNotification*)notification;

/**
 * @brief Handler for ar video played
 */
- (void)videoPlayed:(NSNotification*)notification;

/**
 * @brief Handler for ar video switched to fullscreen or back
 */
- (void)videoSwitched:(NSNotification*)notification;

/**
 * @brief Handler for web view renderable clicks
 */
- (void)webViewRenderableClicked:(NSNotification*)notification;

/**
 * @brief Show a message popup
 */
- (void)showMessage:(NSString*)message;

/**
 * @brief Close message popup
 */
- (void)closeMessageView:(NSTimer*)timer;

/**
 * @brief Message popup closed
 */
- (void)messageViewClosed;

/**
 * @brief Invalidate the refresh pois timer
 */
- (void)invalidateRefreshPoisTimer;

/**
 * @brief Initialize the refresh pois timer
 */
- (void)initializeRefreshPoisTimerWithInterval:(NSTimeInterval)interval timerRepeats:(BOOL)repeats;

/**
 * @brief Parse error code for a request
 */
- (void)parseErrorForRequest:(LSRequest*)request;

/**
 * @brief Parse error code for a poi request
 */
- (void)parseErrorForPoiRequest:(LSRequest*)request;

/**
 * @brief Refresh pois by force (getPois with a few checks)
 */
- (void)forceRefreshPOIs;

/**
 * @brief Callback for poi refresh timer
 */
- (void)refreshPois:(NSTimer*)timer;

/**
 * @brief Perform a GetPOI request for the current layer
 *
 * This will issue a refresh request for POI's for the current layer.
 * When the request completes, it will replace all currently loaded POI's
 */
- (BOOL)getPois;

/**
 * @brief Perform a GetPOI request with a layer action
 */
- (BOOL)getPoisWithLayerAction:(LSAction*)action;

/**
 * @brief Helper function called by poiRequestCompleted
 */
- (void)handleCompletedGetPoisRequest;

/**
 * @brief Parse GetPOI request
 *
 * @param request The request to parse
 * @param parser The parser with which to parse the request
 */
- (void)parseGetPoisRequest:(LSRequest*)request withParser:(LSPOIParser*)parser;

/**
 * @brief The get poi request completion callback
 */
- (void)poiRequestCompleted:(NSNotification*)notification;

/**
 * @brief The get poi request failure callback
 */
- (void)poiRequestFailed:(NSNotification*)notification;

/**
 * @brief The get poi request cancelation callback
 */
- (void)poiRequestCancelled:(NSNotification*)notification;

/**
 * @brief Handle POI click event
 */
- (void)handlePoiClick:(LSPOI *)poi;

/**
 * @brief Stops all actions
 */
- (void)stopAllActions;

/**
 * @brief Perform the first  action for a poi
 *
 * This is normally used for a poi that has showBiwOnClick set to false
 */
- (void)performFirstTriggerAction:(LSPOI*)poi;

/**
 * @brief Returns the first action for a poi that the user can click (i.e. where autoTriggerOnly = false etc.). 
 * If no such action found returns nil.
 */
- (LSAction*)clickableActionForPOI:(LSPOI*)poi;

/**
 * @brief Audio player stopped playing callback
 */
- (void)audioPlayerStoppedPlaying:(NSNotification*)notification;

/**
 * @brief Video finished playing callback
 */
- (void)videoFinishedPlaying:(NSNotification*)notification;

/**
 * @brief Video exited fullscreen callback
 */
- (void)videoExitedFullscreen:(NSNotification*)notification;

/**
 * @brief Show settings
 */
- (void)showSettings;

@end
