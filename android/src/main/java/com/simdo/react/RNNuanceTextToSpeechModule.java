
package com.simdo.react;

import android.net.Uri;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.ReadableMapKeySetIterator;

import com.nuance.speechkit.Audio;
import com.nuance.speechkit.AudioPlayer;
import com.nuance.speechkit.Language;
import com.nuance.speechkit.Voice;
import com.nuance.speechkit.Session;
import com.nuance.speechkit.Transaction;
import com.nuance.speechkit.TransactionException;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class RNNuanceTextToSpeechModule extends ReactContextBaseJavaModule {

  private Session speechSession;
  private Transaction ttsTransaction;
  private ReadableMap configuration;
  private String LANGUAGE;

  private final ReactApplicationContext reactContext;

  public RNNuanceTextToSpeechModule(ReactApplicationContext reactContext) {
    super(reactContext);
    this.reactContext = reactContext;
  }

  @Override
  public String getName() {
      return "NuanceTextToSpeech";
  }

  @ReactMethod
  public void configure(ReadableMap settings) {

    String APP_KEY = settings.getString("appKey");
  	String APP_ID = settings.getString("appId");
  	String SERVER_HOST = settings.getString("serverHost");
  	String SERVER_PORT = settings.getString("serverPort");
  	LANGUAGE = settings.getString("language");
    Uri SERVER_URI = Uri.parse("nmsps://" + APP_ID + "@" + SERVER_HOST + ":" + SERVER_PORT);
    speechSession = Session.Factory.session(this.reactContext, SERVER_URI, APP_KEY);

  }

  @ReactMethod
  public void speak(ReadableMap speakSettings) {

    String MESSAGE = speakSettings.getString("message");
    String VOICE = speakSettings.getString("voice");

    Transaction.Options options = new Transaction.Options();
        options.setLanguage(new Language(LANGUAGE));
        options.setVoice(new Voice(VOICE)); //optionally change the Voice of the speaker, but will use the default if omitted.

        //Start a TTS transaction
        ttsTransaction = speechSession.speakString(MESSAGE, options, new Transaction.Listener() {
            public void onAudio(Transaction transaction, Audio audio) {

                //The TTS audio has returned from the server, and has begun auto-playing.
                ttsTransaction = null;
            }
            public void onSuccess(Transaction transaction, String s) {

                //Notification of a successful transaction. Nothing to do here.
            }
            public void onError(Transaction transaction, String s, TransactionException e) {

                //Something went wrong. Check Configuration.java to ensure that your settings are correct.
                //The user could also be offline, so be sure to handle this case appropriately.

                ttsTransaction = null;
            }
        });
}

@ReactMethod
public void notify(ReadableMap speakSettings) {

  String MESSAGE = speakSettings.getString("message");
  String VOICE = speakSettings.getString("voice");

  Transaction.Options options = new Transaction.Options();
      options.setLanguage(new Language(LANGUAGE));
      options.setVoice(new Voice(VOICE)); //optionally change the Voice of the speaker, but will use the default if omitted.

      //Start a TTS transaction
      ttsTransaction = speechSession.speakString(MESSAGE, options, new Transaction.Listener() {
          @Override
          public void onAudio(Transaction transaction, Audio audio) {

              //The TTS audio has returned from the server, and has begun auto-playing.
              ttsTransaction = null;
          }

          @Override
          public void onSuccess(Transaction transaction, String s) {

              //Notification of a successful transaction. Nothing to do here.
          }

          @Override
          public void onError(Transaction transaction, String s, TransactionException e) {

              //Something went wrong. Check Configuration.java to ensure that your settings are correct.
              //The user could also be offline, so be sure to handle this case appropriately.

              ttsTransaction = null;
          }
      });
}

}
