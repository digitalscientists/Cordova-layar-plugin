//
//  LPLayerAction.h
//  layarplayerinternal
//
//  Created by Anatoliy Samara on 2/8/13.
//  Copyright (c) 2013 Layar. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^LPLayerActionHandlerBlock)(void);

@interface LPLayerActionHandler : NSObject

+(id)layerActionHandlerWithTitle:(NSString *)title andHandler:(LPLayerActionHandlerBlock)handler;

-(id)initWithTitle:(NSString *)title andHandler:(LPLayerActionHandlerBlock)handler;

@property (nonatomic, copy) NSString* title;
@property (nonatomic, copy) LPLayerActionHandlerBlock handler;

@end
