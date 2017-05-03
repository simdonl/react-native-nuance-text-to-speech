/*
  React Native Speech Notification Plugin
  https://github.com/simdonl/react-native-speech-notification

  Created by SIMDO
  https://github.com/simdonl

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
  },
  notify: function(params) {
    RNNuanceTextToSpeech.notify(params);
  }
};

module.exports = NuanceTextToSpeech;
