/**
 * @file LayarSDKViewController.h
 * @brief This file contains protocol declaration for LayarSDKViewController.
 *
 * @copyright Copyright (c) 2013 Layar. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * @brief	The LayarSDKViewController gives you access to extended
 *			functionality of AR view controller, e.g. allows you to launch
 *			map view representation of layers or open layer settings screen.
 *
 * @headerfile LayarSDK/LayarSDK.h
 */
@protocol LayarSDKViewController <NSObject>

/**
 * @brief	This property is set to YES when layer settings are available for
 *			currently loaded layer.
 */
@property (nonatomic, readonly) BOOL layerSettingsAvailable;

/**
 * @brief	This property is set to YES when it is possible to open a map view for
 *			currently loaded layer.
 */
@property (nonatomic, readonly) BOOL mapViewAvailable;

/**
 * @brief	Open a screen with layer settings for currently loaded layer.
 *			If the settings are not available this method does nothing.
 *
 * @sa layerSettingsAvailable
 */
- (void)showLayerSettings;

/**
 * @brief	Open a map view for currently loaded layer.
 *			If the map representation is not available this method does nothing.
 *
 * @sa mapViewAvailable
 */
- (void)showMapView;

@end
