# Playwire iOS SDK

The Playwire iOS SDK is distributed through Swift Package Manager and supports iOS 13 or later.

## Add Playwire to an Xcode project

1. In Xcode, open your project and select **File > Add Package Dependencies**.
2. Enter this repository's URL in the search field.
3. Select the version rule appropriate for your project, then click **Add Package**.
4. Add the **Playwire** library to your app target.

You can then import the SDK where needed:

```swift
import Playwire
```

## Add Playwire to a Swift package

Add this repository to the `dependencies` array in your `Package.swift`, replacing `<version>` with the desired release:

```swift
dependencies: [
    .package(
        url: "https://github.com/intergi/playwire-ios-spm.git",
        from: "<version>"
    )
]
```

Then add Playwire to your target dependencies:

```swift
.target(
    name: "YourTarget",
    dependencies: [
        .product(name: "Playwire", package: "playwire-ios-spm")
    ]
)
```

## Usage

Setup and usage instructions are available in the [Playwire Mobile App SDK documentation](https://support.playwire.com/playwire-mobile-app-sdk#get-started-with-playwire-mobile-app-sdk).