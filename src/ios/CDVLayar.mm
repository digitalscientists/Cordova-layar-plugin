//
//  CDVLayar.m
//  AMC
//
//  Created by Sergey Popenko on 10/7/13.
//
//

#import "CDVLayar.hpp"
#import "LayarPlayer.hpp"

@implementation CDVLayar

- (void)pluginInitialize
{
    [super pluginInitialize];
}


- (void)launchLayarVision:(CDVInvokedUrlCommand*)command
{
    
    NSString *consumerKey = [[NSUserDefaults standardUserDefaults] valueForKey:@"LayarKey"];
    NSString *consumerSecret = [[NSUserDefaults standardUserDefaults] valueForKey:@"LayarSecret"];
    LPARVisionViewController *augmentedRealityViewController = [[LPARVisionViewController alloc] init];
    augmentedRealityViewController.oauthConsumerKey = consumerKey;
    augmentedRealityViewController.oauthConsumerSecret = consumerSecret;
    augmentedRealityViewController.delegate = nil;
    [self.viewController presentViewController:augmentedRealityViewController animated:YES completion:nil];
    
    CDVPluginResult* pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"Done"];

    
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
