
# Nuance Text-To-Speech for React Native

## Getting started

`$ npm install react-native-nuance-text-to-speech --save`

### Mostly automatic installation

`$ react-native link react-native-nuance-text-to-speech`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-nuance-text-to-speech` and add `RNNuanceTextToSpeech.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNNuanceTextToSpeech.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

## Usage
```javascript
import NuanceTextToSpeech from 'react-native-nuance-text-to-speech';

NuanceTextToSpeech.init({
      appKey: '',
      appId: '',
      serverHost: '',
      serverPort: '',
      language: ''
    });

NuanceTextToSpeech.speak({
        message: 'Hello World!'
      });
```
  