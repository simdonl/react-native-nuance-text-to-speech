/*
  React Native Speech Notification Plugin
  https://github.com/kn4rfy/react-native-speech-notification

  Created by FRANCIS KNARFY ELOPRE
  https://github.com/kn4rfy

  MIT License
*/

'use strict';

var { DeviceEventEmitter, NativeModules } = require('react-native');
const RNNuanceTextToSpeech = NativeModules.NuanceTextToSpeech;

var NuanceTextToSpeech = {
  speak: function(params) {
    RNNuanceTextToSpeech.speak(params);
  },
  notify: function(params) {
    RNNuanceTextToSpeech.notify(params);
  }
};

module.exports = NuanceTextToSpeech;
