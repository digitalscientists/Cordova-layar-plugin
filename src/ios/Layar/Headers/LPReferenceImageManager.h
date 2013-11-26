//
//  LPReferenceImageManager.h
//  layarplayerinternal
//
//  Created by Nikita Ivaniushchenko on 9/10/12.
//  Copyright (c) 2012 Layar. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LPReferenceImageManager;

@protocol LPReferenceImageManagerDelegate <NSObject>
- (void)referenceImageManager:(LPReferenceImageManager*)manager didAddReferenceImages:(NSArray*)referenceImages;
- (void)referenceImageManager:(LPReferenceImageManager*)manager didRemoveReferenceImages:(NSArray*)referenceImages;
- (void)referenceImageManager:(LPReferenceImageManager*)manager didSkipReferenceImages:(NSArray*)referenceImages;
@end

@class LSReferenceImage;

@interface LPReferenceImageManager : NSObject
{
    NSMutableDictionary *referenceImages;
    
    id<LPReferenceImageManagerDelegate> delegate;
}

@property (nonatomic, assign) id<LPReferenceImageManagerDelegate> delegate;

- (LSReferenceImage*)referenceImage:(NSString*)key;
- (void)addReferenceImages:(NSArray*)referenceImages;
- (void)removeReferenceImagesForKeys:(NSArray*)referenceImageKeys;
- (void)clearAllReferenceImages;
- (NSDictionary*)allReferenceImages;

@end
