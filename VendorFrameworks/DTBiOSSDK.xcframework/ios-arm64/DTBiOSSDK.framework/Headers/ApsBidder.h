//
//  ApsBidder.h
//  DTBiOSSDK
//
//  Created by Gaonkar, Aditya on 9/10/25.
//  Copyright © 2025 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ApsBidderAdapter.h"

typedef NSMutableDictionary<NSString *, id<ApsBidderAdapter>> AdapterInstances;

NS_ASSUME_NONNULL_BEGIN

@interface ApsBidder : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (ApsBidder *)sharedInstance;
+ (nullable ApsBidder *)sharedInstanceIfAvailable;
- (void)reset;
- (void)initBidderSDK;

- (AdapterInstances *)getAllAdapterInstances;
-(id<ApsBidderAdapter> _Nullable)getAdapterInstance:(NSString* _Nonnull) bidderId;
@end

NS_ASSUME_NONNULL_END
