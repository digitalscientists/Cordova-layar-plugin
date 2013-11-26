//
//  LPShowDialog.h
//  layarplayer
//
//  Created by Nikita Ivanyushchenko on 01/25/11.
//  Copyright (c) 2011 Layar B.V. All rights reserved.
//

//System imports
#import <UIKit/UIKit.h>

#define LPShowDialogActionFired	@"LPShowDialogActionFired"


@class LPShowDialog;

@class LSAction;
@class LSShowDialogData;
@class LCImageManager;
@class LPCloseButton;
@class LPExtendedBIWButtonContainer;

@interface LPShowDialog : NSObject
{	
}

@property (nonatomic, retain) LCImageManager *imageManager;

- (id)init;

/**
 * @brief Shows a popup dialog on top of screen, dimming underlying content.
 */
- (void)showWithData:(LSShowDialogData*)showDialogData andCompletion:(void (^)()) completion;

/**
 * @brief Dismisses currently shown dialog. Does not call completion block even if any showDialogData was previously called.
 */
- (void)cancel;

@end
