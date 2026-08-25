//
//  ApsBidderAdapter.h
//  DTBiOSSDK
//
//  Created by Gaonkar, Aditya on 9/10/25.
//  Copyright © 2025 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ApsBidderAdapterParam.h"
#import "ApsBidderSDKInitializationStatus.h"

NS_ASSUME_NONNULL_BEGIN
@protocol ApsBidderSDKInitializationListener;

@protocol ApsBidderAdapter <NSObject>

@property (nonatomic, strong, nullable) ApsBidderAdapterParam *apsBidderAdapterParams;

- (NSDictionary<NSString *, id> *)getSignal;
- (void)initializeWithCompletion:(void (^)(ApsBidderSDKInitializationStatus status, NSString* message))completionBlock;
- (NSString *)getBidderSDKVersion;
- (NSString *)getAdapterSDKVersion;
- (void)cleanUp;
- (void)setApsBidderAdapterParam:(ApsBidderAdapterParam *)bidderAdapterParam;
- (nullable ApsBidderAdapterParam *)getApsBidderAdapterParams NS_SWIFT_NAME(getApsBidderAdapterParams());



@end
NS_ASSUME_NONNULL_END



