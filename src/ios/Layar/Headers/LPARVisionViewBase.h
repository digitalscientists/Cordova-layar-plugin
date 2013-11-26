//
//  LPARVisionViewBase.h
//  LayarPlayer
//
//  Created by Nikita Ivaniushchenko on 7/3/11.
//  Copyright (c) 2011 Layar B.V. All rights reserved.
//

//System imports

#import <UIKit/UIKit.h>

@class EAGLContext;

@class LSPOIModel;
@class LS1DRenderable;
@class LSTrackableObjectsRenderer;
@class LSLayer;
@class LSRenderableManager;
@class LSTexture2D;
@class LSARObjectRenderable;
@class LSARTrackableObjectRenderable;
@class LSReferenceImage;

@class LCTrackingManager;

@class LPReferenceImageManager;
@class LPVisionAnalyticsHelper;

#define LPARVisionViewFPSNotification			@"LPARVisionViewFPSNotification"
#define LPARVisionViewFPS						@"LPARVisionViewFPS"

@protocol LPARVisionView <NSObject>

@property (nonatomic, readonly) dispatch_semaphore_t renderingSemaphore;
@property (nonatomic, readonly) dispatch_queue_t renderingQueue;
@property (nonatomic, retain) LSRenderableManager *renderableManager;
@property (nonatomic, retain) LSLayer *lslayer;
@property (nonatomic, assign) LSPOIModel *model;
@property (nonatomic, assign) UIDeviceOrientation deviceOrientation;
@property (nonatomic, readonly) int backingWidth;
@property (nonatomic, readonly) int backingHeight;
@property (nonatomic, readonly) LSTrackableObjectsRenderer *trackableObjectsRenderer;
@property (nonatomic, readonly) EAGLContext *mainContext;
@property (nonatomic, retain) LCTrackingManager *trackingManager;
@property (nonatomic, retain) LPReferenceImageManager *referenceImageManager;
@property (nonatomic, assign) NSInteger animationFrameInterval;
@property (nonatomic, assign) id<UIWebViewDelegate> webViewDelegate;
@property (nonatomic, assign) BOOL freezeCameraImage;
@property (nonatomic, retain) LPVisionAnalyticsHelper* analyticsHelper;

- (BOOL)initialize;
- (void)bindResources;
- (void)unbindResources;
- (void)startAnimating;
- (void)pauseAnimating;
- (void)stopAnimating;
- (void)drawView;

/**
 * @brief Update the resource for a POI renderable
 *
 * @param poiRenderable The POI renderable for which to update the resouce
 */
- (void)updateARTrackableObjectRenderableResources:(LSARTrackableObjectRenderable*)trackingRenderable;

- (void)calculateTriggeredActionForARObject;

/**
 * @brief get the POI renderable at given coordinates
 */
- (LSARObjectRenderable*)getPOIRenderableAtCoordinatesWithX:(int)x andY:(int)y;

// for screenshot making purpose
- (void)setProjectionMatrixParameters:(int)surfaceWidth surfaceHeight:(int)surfaceHeight fx:(float)fx fy:(float)fy cx:(float)cx cy:(float)cy;

- (void)updateProjectionMatrix;


/**
 * @brief Set the camera feed size
 */
- (void)setCameraFeedSize:(CGSize)size;

/**
 * @brief ask POI renderable to handle click at given coordinates
 */
- (void)handlePOIRenderableClick:(LSARObjectRenderable*)poiRenderable atX:(int)x andY:(int)y;

- (void)takeScreenshotWithCompletion:(void(^)(UIImage *image)) completion;


@end
