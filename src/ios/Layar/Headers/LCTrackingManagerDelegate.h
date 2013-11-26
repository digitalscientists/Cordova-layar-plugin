//
//  LCTrackingManagerDelegate.h
//  LayarCommon
//
//  Created by Anatoliy Samara on 11/20/12.
//  Copyright (c) 2012 Layar B.V. All rights reserved.
//

@class LCTrackingManager;

@protocol LCTrackingManagerDelegate <NSObject>

@optional
- (void)trackingManager:(LCTrackingManager*)trackingManager targetDetectorDetectedTargets:(NSArray*)targets;

/**
 * Called when target detector detects one or more QR Codes
 *
 * @param qrcodes Dictionary of detected QR Codes. Keys are target ID, values are decoded QR Code texts
 */
- (void)trackingManager:(LCTrackingManager*)trackingManager targetDetectorDetectedQRCodes:(NSDictionary*)qrcodes;

- (void)trackingManager:(LCTrackingManager*)trackingManager willAddTargetFingerprint:(NSString*)target;
- (void)trackingManager:(LCTrackingManager*)trackingManager didAddTargetFingerprint:(NSString*)target;
- (void)trackingManager:(LCTrackingManager*)trackingManager willRemoveTargetFingerprint:(NSString*)target;
- (void)trackingManager:(LCTrackingManager*)trackingManager didRemoveTargetFingerprint:(NSString*)target;

@end
