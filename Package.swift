// swift-tools-version: 5.9

import Foundation
import PackageDescription

enum PlaywireBuildMode: String {
    case source
    case prebuilt
}

let buildMode: PlaywireBuildMode = {
    if let value = ProcessInfo.processInfo.environment["PLAYWIRE_BUILD_MODE"] {
        guard let mode = PlaywireBuildMode(rawValue: value) else {
            fatalError("Invalid PLAYWIRE_BUILD_MODE '\(value)'. Expected 'source' or 'prebuilt'.")
        }
        return mode
    }

    // The private repository contains source; the public distribution repository does not.
    let packageRoot = URL(fileURLWithPath: #filePath).deletingLastPathComponent()
    let sourcePath = packageRoot.appendingPathComponent("Playwire").path
    return FileManager.default.fileExists(atPath: sourcePath) ? .source : .prebuilt
}()

let sdkDependencies: [Target.Dependency] = [
    "DTBiOSSDK",
    "AppLovinMediationAmazonAdMarketplaceAdapter",
    .product(name: "GoogleMobileAds", package: "swift-package-manager-google-mobile-ads"),
    .product(
        name: "GoogleInteractiveMediaAds", package: "swift-package-manager-google-interactive-media-ads-ios"),
    .product(name: "AppLovinAdapterTarget", package: "googleads-mobile-ios-mediation-applovin"),
    .product(name: "ChartboostAdapterTarget", package: "googleads-mobile-ios-mediation-chartboost"),
    .product(name: "MetaAdapterTarget", package: "googleads-mobile-ios-mediation-meta"),
    .product(name: "DTExchangeAdapterTarget", package: "googleads-mobile-ios-mediation-dtexchange"),
    .product(name: "InMobiAdapterTarget", package: "googleads-mobile-ios-mediation-inmobi"),
    .product(name: "IronSourceAdapterTarget", package: "googleads-mobile-ios-mediation-ironsource"),
    .product(name: "MolocoAdapterTarget", package: "googleads-mobile-ios-mediation-moloco"),
    .product(name: "PangleAdapterTarget", package: "googleads-mobile-ios-mediation-pangle"),
    .product(name: "UnityAdapterTarget", package: "googleads-mobile-ios-mediation-unity"),
    .product(name: "LiftoffMonetizeAdapterTarget", package: "googleads-mobile-ios-mediation-liftoffmonetize"),
    .product(name: "AppLovinSDK", package: "AppLovin-MAX-Swift-Package"),
    .product(name: "AppLovinMediationFyberAdapter", package: "AppLovin-MAX-Swift-Package-Fyber"),
    .product(
        name: "AppLovinMediationGoogleAdManagerAdapter",
        package: "AppLovin-MAX-Swift-Package-GoogleAdsManager"),
    .product(name: "AppLovinMediationGoogleAdapter", package: "AppLovin-MAX-Swift-Package-Google"),
    .product(name: "AppLovinMediationIronSourceAdapter", package: "AppLovin-MAX-Swift-Package-IronSource"),
    .product(name: "AppLovinMediationOguryPresageAdapter", package: "AppLovin-MAX-Swift-Package-Ogury"),
    .product(name: "AppLovinMediationPubMaticAdapter", package: "AppLovin-MAX-Swift-Package-PubMatic"),
    .product(name: "AppLovinMediationVerveAdapter", package: "AppLovin-MAX-Swift-Package-Verve"),
    .product(name: "AppLovinMediationByteDanceAdapter", package: "AppLovin-MAX-Swift-Package-Pangle"),
    .product(name: "AppLovinMediationFacebookAdapter", package: "AppLovin-MAX-Swift-Package-Meta"),
    .product(name: "AppLovinMediationVungleAdapter", package: "AppLovin-MAX-Swift-Package-Liftoff"),
    .product(name: "AppLovinMediationChartboostAdapter", package: "AppLovin-MAX-Swift-Package-Chartboost"),
    .product(name: "AppLovinMediationInMobiAdapter", package: "AppLovin-MAX-Swift-Package-InMobi"),
    .product(name: "AppLovinMediationMolocoAdapter", package: "AppLovin-MAX-Swift-Package-Moloco"),
    .product(name: "AppLovinMediationSmaatoAdapter", package: "AppLovin-MAX-Swift-Package-Smaato"),
    .product(name: "AppLovinMediationUnityAdsAdapter", package: "AppLovin-MAX-Swift-Package-UnityAds")
]

let playwireTarget: Target =
    buildMode == .source
    ? .target(
        name: "Playwire",
        dependencies: sdkDependencies,
        path: "Playwire",
        exclude: ["Info.plist", "Playwire.h"],
        resources: [
            .process("PlaywireAssets.xcassets"),
            .copy("PrivacyInfo.xcprivacy")
        ])
    : .binaryTarget(
        name: "Playwire",
        path: "sdks/Playwire.xcframework")

let distributionDependencies: [Target.Dependency] =
    buildMode == .source
    ? ["Playwire"]
    : ["Playwire"] + sdkDependencies

let package = Package(
    name: "Playwire",
    platforms: [.iOS(.v13)],
    products: [
        .library(name: "Playwire", targets: ["PlaywireDistribution"])
    ],
    dependencies: [
        .package(url: "https://github.com/googleads/swift-package-manager-google-mobile-ads.git", exact: "13.4.0"),
        .package(
            url: "https://github.com/googleads/swift-package-manager-google-interactive-media-ads-ios.git",
            exact: "3.26.1"),
        .package(url: "https://github.com/googleads/googleads-mobile-ios-mediation-applovin.git", exact: "13.6.300"),
        .package(url: "https://github.com/googleads/googleads-mobile-ios-mediation-chartboost.git", exact: "9.13.000"),
        .package(url: "https://github.com/googleads/googleads-mobile-ios-mediation-meta.git", exact: "6.21.101"),
        .package(url: "https://github.com/googleads/googleads-mobile-ios-mediation-dtexchange.git", exact: "8.4.701"),
        .package(url: "https://github.com/googleads/googleads-mobile-ios-mediation-inmobi.git", exact: "11.4.100"),
        .package(url: "https://github.com/googleads/googleads-mobile-ios-mediation-ironsource.git", exact: "9.4.10001"),
        .package(url: "https://github.com/googleads/googleads-mobile-ios-mediation-moloco.git", exact: "4.9.000"),
        .package(url: "https://github.com/googleads/googleads-mobile-ios-mediation-pangle.git", exact: "8.1.00600"),
        .package(url: "https://github.com/googleads/googleads-mobile-ios-mediation-unity.git", exact: "4.19.001"),
        .package(
            url: "https://github.com/googleads/googleads-mobile-ios-mediation-liftoffmonetize.git", exact: "7.7.400"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package.git", exact: "13.6.3"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-Fyber.git", exact: "8040700.0.0"),
        .package(
            url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-GoogleAdsManager.git", exact: "13040000.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-Google.git", exact: "13040000.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-IronSource.git", exact: "904010000.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-Ogury.git", exact: "5020300.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-PubMatic.git", exact: "5010100.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-Verve.git", exact: "3080100.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-Pangle.git", exact: "801000600.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-Meta.git", exact: "6210100.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-Liftoff.git", exact: "7070400.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-Chartboost.git", exact: "9130000.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-InMobi.git", exact: "11040101.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-Moloco.git", exact: "4090000.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-Smaato.git", exact: "23020100.0.0"),
        .package(url: "https://github.com/AppLovin/AppLovin-MAX-Swift-Package-UnityAds.git", exact: "4190001.0.0")
    ],
    targets: [
        .target(
            name: "PlaywireDistribution",
            dependencies: distributionDependencies
        ),
        playwireTarget,
        .binaryTarget(
            name: "DTBiOSSDK",
            path: "VendorFrameworks/DTBiOSSDK.xcframework"
        ),
        .binaryTarget(
            name: "AppLovinMediationAmazonAdMarketplaceAdapter",
            path: "VendorFrameworks/AppLovinMediationAmazonAdMarketplaceAdapter.xcframework"
        )
    ]
)
