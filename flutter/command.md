# Flutter Command

## Initialize Source

- Create default source: `flutter create appname`

- Create source with custom package name: `flutter create --org com.yourdomain appname`

- Create with custom android language: `flutter create -a java --org com.yourdomain appname`

- Create with custom ios language `flutter create -i swift --org com.yourdomain appname` 🏄🏻🏄🏻🏄🏻

## Build Runner code

- Build default: `flutter packages pub run build_runner build`

- Build with remove file existed: `flutter packages pub run build_runner build --delete-conflicting-outputs`
    
    - If you was run __Build default__, you should use this command line

