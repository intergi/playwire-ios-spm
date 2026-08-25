//
//  APSMetricsConfigOverride.h
//  APSiOSSharedLib
//
//  Copyright © 2023 amazon.com. All rights reserved.

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * APSMetricsConfigOverride represents metrics configuration settings received from APS Config Service /getConfig call.
 * These settings override the default S3-based metrics configuration.
 */
@interface APSMetricsConfigOverride : NSObject

/**
 * Sampling percentage for metrics (0-100). This field is required.
 */
@property (nonatomic, assign) NSInteger samplingPercentage;

/**
 * If true, only custom metrics should be sent. Performance metrics are filtered out.
 * This field is optional.
 */
@property (nonatomic, assign) BOOL customOnly;

/**
 * Indicates whether customOnly flag was explicitly set in the configuration.
 * Used to distinguish between default false and explicitly set false.
 */
@property (nonatomic, assign, readonly) BOOL hasCustomOnlyFlag;

/**
 * Initialize with dictionary from /getConfig response metricsConfig field.
 * @param dict Dictionary containing metricsConfig values
 * @return Initialized instance or nil if required fields are missing/invalid
 */
- (instancetype _Nullable)initWithDictionary:(NSDictionary *)dict;

/**
 * Validates the configuration values.
 * @return YES if samplingPercentage is 0-100
 */
- (BOOL)isValid;

/**
 * Converts the configuration to dictionary for persistence.
 * @return Dictionary representation suitable for storage
 */
- (NSDictionary *)toDictionary;

/**
 * Creates instance from persisted dictionary.
 * @param dict Dictionary from storage
 * @return Initialized instance or nil if invalid
 */
+ (instancetype _Nullable)fromDictionary:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
