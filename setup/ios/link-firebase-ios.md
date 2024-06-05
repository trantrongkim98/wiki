# Link Firebase To IOS

## Overview

1. Register Keys

2. Register Cerfication

3. setup APNs in Firebase

### Register Key

1. Go to [Certificates, Identifiers & Profiles](https://developer.apple.com/account/resources/authkeys/list) -> Click Keys

2. Click Button +

3. Enter Key Name

4. Download Key file and copy Key ID

5. Upload to Firebase Console

### Register Certificate

#### Create SignRequest File

1. Open KeyChain Access

2. Click KeyChain Access -> KeyChain Assistants -> Request a Certificate From a Certificate Authority
3. Enter Email and choose saved to disk

#### Create Certificate

1. Go to [Certificates, Identifiers & Profiles](https://developer.apple.com/account/resources/authkeys/list) -> Certificates

2. Click Button +

3. Choose a service Example (Apple Push Notification service SSL (Sandbox & Production)) -> Continue

4. Choose AppId do you want to create a Certificate

5. Click Choose File and upload SignRequest created at above step

6. Download file .cer to your personal computer

### Setup APNs in Firebase Console

1. Drag file .cer to Access Keychain

2. Choose login at the left side

3. Choose My Certificate

4. right click and Export file to p12

5. Enter password what do you want

6. Drag it to Firebase Console

