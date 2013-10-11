/**
 * @file LPARVisionViewController.hpp
 *
 * @author Lawrence Lee, Layar B.V.
 * @date 25th October 2010
 */

//System imports
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

//LayarCommon imports
#import "LCTrackingManagerDelegate.h"

//Local imports
#import "LPBIW.h"
#import "LPShowDialog.h"
#import "LPPOIViewController.h"
#import "LPARVisionViewBase.h"

#import "LPReferenceImageManager.h"

#define kBirdsEyeViewCheckedNotification	@"BirdsEyeViewCheckedNotification"

typedef void(^LPARStillFrameCaptureCompletionHandler)(UIImage *image);

@class AVCaptureSession;
@class AVCaptureDevice;
@class AVCaptureDeviceInput;
@class AVCaptureVideoPreviewLayer;

@class LSAction;
@class LCResourceManager;
@class LCFeatureSet;
@class LPARVisionOverlayView;
@class LPVisionAnalyticsHelper;

/**
 * @class LPARVisionViewController
 * @brief UIViewController subclass that manages the Augmented Reality View
 *
 * The most important functionality of this class is to facilitate the loading
 * of a layer. This can be done using the loadLayerWithName method. When an
 * instance of this class is presented, it will request that the location
 * services and accelerometer services be enabled. It will also initialize
 * the camera and various overlay views for the Augmented Reality view, and
 * create the underlying OpenGL contexts for rendering.
 * The class also manages the various resources needed to render the scene,
 * and if necessary will also download any resources the POIs in the scene
 * require.
 */

@class LPVisionScanOverlayView;

@interface LPARVisionViewController : LPPOIViewController <	AVCaptureVideoDataOutputSampleBufferDelegate, 
															LCTrackingManagerDelegate,
															UIWebViewDelegate, LPReferenceImageManagerDelegate>
{
	LCTrackingManager *trackingManager_;
    LPReferenceImageManager *referenceImageManager;
		
	NSString* lastDetectedTarget;
	
	dispatch_queue_t videoQueue;
	BOOL videoQueueRunning;
    
	AVCaptureSession *captureSession;
	AVCaptureDevice *videoDevice;
	AVCaptureVideoDataOutput *videoDataOutput;

	BOOL subjectAreaChanged;
	
	dispatch_semaphore_t videoBufferSemaphore;
	
	size_t cameraFeedWidth;
	size_t cameraFeedHeight;
    
	UIView<LPARVisionView> *arView;
	LPARVisionOverlayView *overlayView;
	LPVisionScanOverlayView *scanOverlayView;
	NSTimer *scanOverlayViewHideTimer;
	
	LSRequest *layersRequest;
	
	LPShowDialog *showDialog;
	
	BOOL needsPois;
    
	id lastClickedPOI;
	NSArray *lastTargets_;
	NSArray *layers;
	
	LSARObjectRenderable *touchedRenderable;
	
	BOOL isProcessingFrame_;
	LSPOI *fakePoi;
	
	BOOL needStillFrame;
	LPARStillFrameCaptureCompletionHandler stillFrameCaptureCompletionHandler;

#if defined(WHITELABEL)
	UIButton *infoButton;
#endif

#if !defined(LPINTERNALBUILD) && !defined(WHITELABEL)
	UIButton *closeButton;
#endif

	LSLayer* qrcodeLayer_;
	BOOL detectedQRCodeAfterScan_;
	BOOL lastScanWasCancelled_;
	NSTimer* qrCodeStopScanTimer_;
	
	LPVisionAnalyticsHelper* analyticsHelper_;
}

#if defined(LPINTERNALBUILD)

@property (nonatomic, readonly) LPARVisionOverlayView *overlayView;

- (void)updateOrientation;
- (void)showTapToViewTimerFired:(NSTimer*)aTimer;
- (void)trackingWasLost;
- (void)trackingWasLostForScannedImage;
- (void)trackingWasFound:(BOOL)isScannedImage;
- (void)performStillImageCaptureWithCompletionHandler:(LPARStillFrameCaptureCompletionHandler)aStillFrameCaptureCompletionHandler;
- (void)takeScreenshotWithCompletion:(void(^)(UIImage *image)) completion;
- (void)scanOverlayViewStateChanged:(NSNotification *)notification;

#endif

- (void)releaseViews;

/**
 * @brief Array of layers
 *
 * Array of layers recieved from scanning. Can contain any count of layers.
 */
@property (nonatomic, retain) NSArray *layers;


- (void)scanButtonClicked;

@end
