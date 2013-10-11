//
//  LPActionSheet.h
//  layarplayerinternal
//
//  Created by Anatoliy Samara on 2/8/13.
//  Copyright (c) 2013 Layar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef void(^LPActionSheetHandler)(void);

@interface LPActionSheetButton : NSObject

+(id)buttonWithTitle:(NSString *)title andHandler:(LPActionSheetHandler)handler;

-(id)initWithTitle:(NSString *)title andHandler:(LPActionSheetHandler)handler;

@property (nonatomic, copy) NSString* title;
@property (nonatomic, copy) LPActionSheetHandler handler;

@end

@interface LPActionSheet : NSObject <UIActionSheetDelegate>

@property (nonatomic, retain) NSArray* buttons;
@property (nonatomic, copy) NSString* title;
@property (nonatomic, readonly) BOOL shown;
@property (nonatomic, copy) LPActionSheetHandler closeHandler;

-(id)initWithTitle:(NSString*)title andCloseHandler:(LPActionSheetHandler)closeHandler;

- (void)showFromToolbar:(UIToolbar *)view;
- (void)showInView:(UIView *)view;
- (void)cancel;

@end
