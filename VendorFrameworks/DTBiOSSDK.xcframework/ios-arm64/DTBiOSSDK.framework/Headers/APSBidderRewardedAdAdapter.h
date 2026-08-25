//
//  APSBidderRewardedAdAdapter.m
//  DTBiOSSDK
//
//  Copyright © 2025 amazon.com. All rights reserved.
//
#import <Foundation/Foundation.h>

@class APSAd;
@protocol APSAdDelegate;

@protocol APSBidderRewardedAdAdapter <NSObject>

- (void)fetchRewardedAd:(APSAd *) apsAd andDelegate:(id<APSAdDelegate>)adDelegate;
- (void)showRewardedAd:(APSAd *) apsAd andDelegate:(id<APSAdDelegate>)adDelegate;

@end
