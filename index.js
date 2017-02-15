/*
  React Native Nuance Text To Speech
  https://github.com/simdonl/react-native-nuance-text-to-speech

  Created by SIMDO

  MIT License
*/

'use strict';

var { DeviceEventEmitter, NativeModules } = require('react-native');
const RNNuanceTextToSpeech = NativeModules.NuanceTextToSpeech;

var NuanceTextToSpeech = {
  configure: function(params) {
    RNNuanceTextToSpeech.configure(params);
  },
  speak: function(params) {
    RNNuanceTextToSpeech.speak(params);
  }
};

module.exports = NuanceTextToSpeech;
