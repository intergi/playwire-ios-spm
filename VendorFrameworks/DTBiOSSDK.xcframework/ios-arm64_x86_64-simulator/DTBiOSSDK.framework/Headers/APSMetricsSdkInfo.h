//
//  APSMetricsSdkInfo.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface APSMetricsSdkInfo : NSObject

@property(nonatomic, nullable, copy) NSString *version;
@property(nonatomic, nullable, copy) NSString *appId;

- (instancetype)initWithVersion:(NSString *)version;
- (instancetype)initWithVersion:(NSString *)version appId:(NSString *)appId;
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
