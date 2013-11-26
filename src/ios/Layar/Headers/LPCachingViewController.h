//
//  LPCachingViewController.h
//  layarplayerinternal
//
//  Created by Matteo Manferdini on 06/12/11.
//  Copyright (c) 2011 Layar. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LPServiceProvider;

@interface LPCachingViewController : UIViewController

@property (nonatomic, readonly) LPServiceProvider *serviceProvider;

/**
 * Init the LPCachingViewController by providing the serviceProvider. This 
 * method is internally calling the -(void)initialize method. If you want to
 * configure a class that extends the LPCachingViewController you do your
 * configuration in the initialize method.
 */
- (id)initWithServiceProvider:(LPServiceProvider *)theServiceProvider;

/**
 * Init calles the initWithServiceProvider:(LPServiceProvider *)theServiceProvider
 * method.
 */
- (id)initWithNibName:(NSString *)nibNameOrNil
			   bundle:(NSBundle *)nibBundleOrNil
	  serviceProvider:(LPServiceProvider *)theServiceProvider;

/**
 * Overwrite this to do your own initialization. Is allways called upon init.
 */
- (void)initialize;

@end