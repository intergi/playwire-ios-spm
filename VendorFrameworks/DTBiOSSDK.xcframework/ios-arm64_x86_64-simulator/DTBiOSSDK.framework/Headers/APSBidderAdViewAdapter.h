//
//  APSBidderAdViewAdapter.h
//  DTBiOSSDK
//
//  Copyright © 2025 amazon.com. All rights reserved.
//
#import <Foundation/Foundation.h>

@class APSAd;
@protocol APSAdDelegate;

NS_ASSUME_NONNULL_BEGIN

@protocol APSBidderAdViewAdapter <NSObject>

- (void)loadAdViewWithAd:(APSAd *) apsAd andDelegate:(id<APSAdDelegate>)adDelegate;

@end

NS_ASSUME_NONNULL_END
