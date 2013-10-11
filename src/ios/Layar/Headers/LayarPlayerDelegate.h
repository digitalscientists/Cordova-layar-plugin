//
//  LayarPlayerDelegate.h
//  layarplayer
//
//  Created by Lawrence Lee on 11/26/10.
//  Copyright 2010 Layar. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 * @brief	The LayarPlayerDelegate provides you with several callback methods
 *			to inform you if the user dismisses the LPARVisionViewController or
 *			performed any other activity.
 *
 *			You get information about which layer has been loaded and when a
 *			certain reference image is tracked. This callback tells you which 
 *			page in your campaign is seen by the user.
 */

@protocol LayarPlayerDelegate <NSObject>

@optional

/**
 * @brief	Will be called before the LPARVisionViewController is
 *			dismissed.
 */
- (void)layarPlayerWillClose;

/**
 * @brief	Will be called after the LPARVisionViewController is
 *			dismissed.
 */
- (void)layarPlayerDidClose;

/**
 * @brief	Called when the user has scanned a reference image
 *			and this reference image has been detected to be one of your pages
 *			in one of your campaigns. Internally campaigns are related to layers
 *			so the layerName is your campaign's name and the layerTitle is your
 *			campaign's title.
 * @param	layerName	NSString*	The name of the detected campaign
 * @param	layerTitle	NSString*	The title of the detected campaign
 */
- (void)layarPlayerDidLaunchLayer:(NSString*)layerName withTitle:(NSString*)layerTitle;

/**
 * @brief	Informs your application that after a campaign is loaded the visual 
 *			tracking of one of the pages has started. You are provided with the
 *			referenceImageName which relates to one of your pages as well as the
 *			layarName (campaign name) and the layarTitle (campaign title).
 * @param	referenceImageName	NSString*	The name of the reference image
 * @param	layerName			NSString*	The name of the tracked campaign
 * @param	layerTitle			NSString*	The title of the tracked campaign
 */
- (void)layarPlayerStartedTrackingReferenceImage:(NSString*)referenceImageName withLayer:(NSString*)layerName withTitle:(NSString*)layerTitle;

@end
