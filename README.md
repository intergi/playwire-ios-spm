# Playwire iOS SDK

## Requirements

- iOS 13.0 or later

## Add Playwire to an Xcode project

1. Open your app project in Xcode.
2. Select **File > Add Package Dependencies**.
3. Enter the package URL:

   ```text
   https://github.com/intergi/playwire-ios-spm.git
   ```

4. Choose the dependency rule and Playwire release required by your app.
5. Add the **Playwire** package product to your app target.

## Add Playwire to another Swift package

Add this repository to the package's dependencies, replacing `<version>` with the desired Playwire release:

```swift
dependencies: [
    .package(
        url: "https://github.com/intergi/playwire-ios-spm.git",
        from: "<version>"
    )
]
```

Then add the Playwire product to the target that uses it:

```swift
.target(
    name: "YourTarget",
    dependencies: [
        .product(name: "Playwire", package: "playwire-ios-spm")
    ]
)
```

## Add the required linker flag

Configure the consumer app target after adding the package:

1. Select the project in Xcode's Project navigator.
2. Select the **app target**, then open **Build Settings**.
3. Search for **Other Linker Flags**.
4. Add `-ObjC` for every build configuration used by the app, while retaining `$(inherited)`.

The setting should contain:

```text
$(inherited) -ObjC
```

## Import the SDK

After Xcode resolves the package, import Playwire where it is needed:

```swift
import Playwire
```

## Next steps

For SDK initialization and ad integration, see the [Playwire Mobile App SDK documentation](https://support.playwire.com/playwire-mobile-app-sdk#get-started-with-playwire-mobile-app-sdk).
