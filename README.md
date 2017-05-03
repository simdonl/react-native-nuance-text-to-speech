
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

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.simdo.react.RNNuanceTextToSpeechPackage;` to the imports at the top of the file
  - Add `new RNNuanceTextToSpeechPackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-nuance-text-to-speech'
  	project(':react-native-nuance-text-to-speech').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-nuance-text-to-speech/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-nuance-text-to-speech')
  	```

## Usage

Create first an developer account
[over here](https://developer.nuance.com/public/index.php?task=register).

```javascript
import NuanceTextToSpeech from 'react-native-nuance-text-to-speech';

NuanceTextToSpeech.configure({
      appKey: '',
      appId: '',
      serverHost: '',
      serverPort: '',
      language: ''
    });

NuanceTextToSpeech.speak({
      message: 'Hello World!',
      voice: 'Xander'
    });
```

## Available Languages and voices
You can checkout the available languages and voices
[over here](http://developer.nuance.com/public/index.php?task=supportedLanguages).
