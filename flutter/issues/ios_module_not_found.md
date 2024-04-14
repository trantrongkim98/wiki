# IOS Module Not Found

## Log

```swift
[   +5 ms] Failed to build iOS app
[        ] Parse Issue (Xcode): Module 'advertising_id' not found
           /Users/kimtt/Workplace/Freelancer/Main%20Files/heyto_app/ios/Runner/GeneratedPluginRegistrant.m:11:8
           
[   +1 ms] Could not build the application for the simulator.
[        ] Error launching application on iPhone 14 Pro Max.
```

## Fix

- pod deintegrate
- pod install