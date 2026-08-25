//
//  ApsBidderSDKInitializationListener.h
//  DTBiOSSDK
//
//  Created by Gaonkar, Aditya on 9/10/25.
//  Copyright © 2025 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ApsBidderSDKInitializationStatus.h"
NS_ASSUME_NONNULL_BEGIN

@protocol ApsBidderSDKInitializationListener <NSObject>

@required
- (void)onInitializationComplete:(ApsBidderSDKInitializationStatus)initializationStatus
                        message:(NSString *)message;

@optional
- (void)onInitializationFailure:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
