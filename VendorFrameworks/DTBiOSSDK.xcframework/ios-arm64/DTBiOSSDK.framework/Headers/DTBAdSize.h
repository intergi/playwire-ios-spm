//
//  DTBAdSize.h
//  DTBiOSSDK
//
//  Copyright (c) 2021 Amazon Publisher Services. All rights reserved.

#import <Foundation/Foundation.h>
#import "APSDeprecatedMessage.h"
#import "APSSlotInfoExtra.h"

#define DTB_VIDEO_WIDTH  ((int)640)
#define DTB_VIDEO_HEIGHT ((int)390)

typedef enum {
    VIDEO,
    DISPLAY,
    INTERSTITIAL
} ADType;

@interface DTBAdSize : NSObject
@property(readonly, nonatomic) ADType adType APS_DEPRECATED_MESSAGE("Use -[APSAd adFormat] instead.");
@property(readonly, nonatomic) NSInteger width APS_DEPRECATED_MESSAGE();
@property(readonly, nonatomic) NSInteger height APS_DEPRECATED_MESSAGE();
@property(readonly, nonatomic, nonnull) NSString *slotUUID APS_DEPRECATED_MESSAGE("Use -[APSAd slotUUID] intead.");
@property(nonatomic, copy, nullable) NSDictionary *pubSettings APS_DEPRECATED_MESSAGE();
@property(nonatomic, nullable) APSSlotInfoExtra *slotInfoExtra;

- (instancetype _Nullable ) init NS_UNAVAILABLE APS_DEPRECATED_MESSAGE();

- (instancetype _Nonnull )initBannerAdSizeWithWidth:(NSInteger)width height:(NSInteger)height andSlotUUID:(NSString *_Nonnull) slotUUID APS_DEPRECATED_MESSAGE();

- (instancetype _Nonnull )initInterstitialAdSizeWithSlotUUID:(NSString * _Nonnull) slotUUID APS_DEPRECATED_MESSAGE();

- (instancetype _Nonnull)initVideoAdSizeWithSlotUUID:(NSString * _Nonnull) slotUUID APS_DEPRECATED_MESSAGE();

- (instancetype _Nonnull)initVideoAdSizeWithPlayerWidth:(NSInteger)width height:(NSInteger)height andSlotUUID:(NSString * _Nonnull) slotUUID APS_DEPRECATED_MESSAGE();

- (instancetype _Nonnull)initVideoAdSizeWithPlayerWidth:(NSInteger)width height:(NSInteger)height slotUUID:(NSString * _Nonnull)slotUUID andPubSettings:(NSDictionary * _Nullable) pubSettings APS_DEPRECATED_MESSAGE();

- (BOOL) isInterstitialAd APS_DEPRECATED_MESSAGE();

-(void)setSlotInfoExtra:(nonnull APSSlotInfoExtra *) slotIntoExtra;
@end
