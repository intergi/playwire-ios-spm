//
//  APSBidderInterstitialAdAdapter.h
//  DTBiOSSDK
//
//  Copyright © 2025 amazon.com. All rights reserved.
//
#import <Foundation/Foundation.h>

@class APSAd;
@protocol APSAdDelegate;

@protocol APSBidderInterstitialAdAdapter <NSObject>

- (void)fetchInterstitialAd:(APSAd *) apsAd andDelegate:(id<APSAdDelegate>)adDelegate;
- (void)showInterstitialAd:(APSAd *) apsAd andDelegate:(id<APSAdDelegate>)adDelegate;

@end
