//
//  ApsBidderAdapterParam.h
//  DTBiOSSDK
//
//  Created by Gaonkar, Aditya on 9/9/25.
//  Copyright © 2025 amazon.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ApsBidderAdapterParamBuilder;

NS_ASSUME_NONNULL_BEGIN

@interface ApsBidderAdapterParam : NSObject

@property (nonatomic, readonly, copy) NSString *accountId;

+ (ApsBidderAdapterParam *)buildWithBlock:(void(^)(ApsBidderAdapterParamBuilder *builder))block;

@end

@interface ApsBidderAdapterParamBuilder : NSObject

@property (nonatomic, copy) NSString *accountId;

- (ApsBidderAdapterParam *)build;

@end


NS_ASSUME_NONNULL_END
