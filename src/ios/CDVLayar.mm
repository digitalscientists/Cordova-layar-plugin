//
//  CDVLayar.m
//  AMC
//
//  Created by Sergey Popenko on 10/7/13.
//
//

#import "CDVLayar.hpp"
#import "LayarSDK.h"

@interface CDVLayar()
// This goes into your class declaration
@property (nonatomic, strong) LayarSDK *layarSDK;
@end

@implementation CDVLayar

- (void)pluginInitialize
{
    [super pluginInitialize];
}


- (void)launchLayarVision:(CDVInvokedUrlCommand*)command
{
    NSBundle* mainBundle = [NSBundle mainBundle];
    
    // The Info.plist is considered the mainBundle.
    mainBundle = [NSBundle mainBundle];
    
    NSString *consumerKey = [mainBundle objectForInfoDictionaryKey:@"LayarKey"];
    NSString *consumerSecret = [mainBundle objectForInfoDictionaryKey:@"LayarSecret"];

    self.layarSDK = [LayarSDK layarSDKWithConsumerKey:consumerKey andConsumerSecret:consumerSecret andDelegate:nil];

    // This is how you construct a view controller for scanning
    __weak typeof(self) weakSelf = self;
    [self.layarSDK viewControllerForScanningWithCompletion:
    ^(UIViewController<LayarSDKViewController> *viewController)
    {
        [weakSelf.viewController presentViewController:viewController animated:YES completion:nil];
    }];

    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"Done"];    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
