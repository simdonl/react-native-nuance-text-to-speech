//
//  NuanceTextToSpeechDelegate.m
//  NuanceTextToSpeechDelegate
//
//  Created by Dominique van Mil on 27/01/2017.
//  Copyright © 2017 SIMDO. All rights reserved.
//

#import "NuanceTextToSpeechDelegate.h"
#import <SpeechKit/SpeechKit.h>

SKSession* _skSession;
SKTransaction *_skTransaction;

NSString* SKSAppKey;
NSString* SKSAppId;
NSString* SKSServerHost;
NSString* SKSServerPort;

NSString* SKSLanguage;

NSString* SKSServerUrl;

// Only needed if using NLU/Bolt
NSString* SKSNLUContextTag = @"!NLU_CONTEXT_TAG!";

@implementation NuanceTextToSpeechDelegate

- (void)configure:(NSDictionary*)args
{
	
	SKSAppKey = [args objectForKey:@"appKey"];
	SKSAppId = [args objectForKey:@"appId"];
	SKSServerHost = [args objectForKey:@"serverHost"];
	SKSServerPort = [args objectForKey:@"serverPort"];
	SKSLanguage = [args objectForKey:@"language"];
	
	SKSServerUrl = [NSString stringWithFormat:@"nmsps://%@@%@:%@", SKSAppId, SKSServerHost, SKSServerPort];

}

- (void)speak:(NSDictionary*)args
{
if (!_skTransaction) {
	
  NSString *message = [args objectForKey:@"message"];
  NSString *voice = [args objectForKey:@"voice"];
	
	_skSession = [[SKSession alloc] initWithURL:[NSURL URLWithString:SKSServerUrl] appToken:SKSAppKey];

		// Start a TTS transaction
		_skTransaction = [_skSession speakString:message
									   withVoice:voice
										delegate:self];
} else {
	// Cancel the TTS transaction
	[_skTransaction cancel];
	
	[self resetTransaction];
}

	
	
}

- (void)notify:(NSDictionary*)args
{
  if ([UIApplication instancesRespondToSelector:@selector(registerUserNotificationSettings:)]) {
    [[UIApplication sharedApplication] registerUserNotificationSettings:[UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert|UIUserNotificationTypeBadge|UIUserNotificationTypeSound categories:nil]];
  }

  NSString *message = [args objectForKey:@"message"];
  NSString *language = [args objectForKey:@"language"];

  if (!language || (id)language == [NSNull null]) {
    language = @"en-US";
  }

  UILocalNotification *notification = [[UILocalNotification alloc]init];
  [notification setAlertBody:message];

	
	
	_skSession = [[SKSession alloc] initWithURL:[NSURL URLWithString:SKSServerUrl] appToken:SKSAppKey];
	
	// Start a TTS transaction
	_skTransaction = [_skSession speakString:message
								   withVoice:@"Xander"
									delegate:self];

    AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
    [[UIApplication sharedApplication] setScheduledLocalNotifications:[NSArray arrayWithObject:notification]];
}


#pragma mark - SKTransactionDelegate

- (void)transaction:(SKTransaction *)transaction didReceiveAudio:(SKAudio *)audio
{
	    [self resetTransaction];
}

- (void)transaction:(SKTransaction *)transaction didFinishWithSuggestion:(NSString *)suggestion
{
	
	// Notification of a successful transaction. Nothing to do here.
}

- (void)transaction:(SKTransaction *)transaction didFailWithError:(NSError *)error suggestion:(NSString *)suggestion
{
	
	
	// Something went wrong. Check Configuration.mm to ensure that your settings are correct.
	// The user could also be offline, so be sure to handle this case appropriately.
	
	[self resetTransaction];
	
}

#pragma mark - SKAudioPlayerDelegate

- (void)audioPlayer:(SKAudioPlayer *)player willBeginPlaying:(SKAudio *)audio
{
	
	// The TTS Audio will begin playing.
}

- (void)audioPlayer:(SKAudioPlayer *)player didFinishPlaying:(SKAudio *)audio
{
	
	// The TTS Audio has finished playing.
}

- (void)resetTransaction
{
	[[NSOperationQueue mainQueue] addOperationWithBlock:^{
		_skTransaction = nil;
	}];
}



@end
