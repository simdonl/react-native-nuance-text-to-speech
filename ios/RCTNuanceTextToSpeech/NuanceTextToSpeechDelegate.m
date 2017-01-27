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

NSString* SKSAppKey = @"[>>>APPKEY<<<]";
NSString* SKSAppId = @"[>>>APPID<<<]";
NSString* SKSServerHost = @"[>>>SERVERHOST<<<]";
NSString* SKSServerPort = @"[>>>SERVERPORT<<<]";

NSString* SKSLanguage = @"[>>>LANGUAGE<<<]";

NSString* SKSServerUrl;

// Only needed if using NLU/Bolt
NSString* SKSNLUContextTag = @"!NLU_CONTEXT_TAG!";

@implementation NuanceTextToSpeechDelegate

-(instancetype)init
{
  self = [super init];
	
SKSServerUrl = [NSString stringWithFormat:@"nmsps://%@@%@:%@", SKSAppId, SKSServerHost, SKSServerPort];
  return self;
}

- (void)speak:(NSDictionary*)args
{

  NSString *message = [args objectForKey:@"message"];
  NSString *language = [args objectForKey:@"language"];
	
	_skSession = [[SKSession alloc] initWithURL:[NSURL URLWithString:SKSServerUrl] appToken:SKSAppKey];

		// Start a TTS transaction
		_skTransaction = [_skSession speakString:message
									   withVoice:@"Xander"
										delegate:self];
	
	
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
}

- (void)transaction:(SKTransaction *)transaction didFinishWithSuggestion:(NSString *)suggestion
{
	
	// Notification of a successful transaction. Nothing to do here.
}

- (void)transaction:(SKTransaction *)transaction didFailWithError:(NSError *)error suggestion:(NSString *)suggestion
{
	
	// Something went wrong. Check Configuration.mm to ensure that your settings are correct.
	// The user could also be offline, so be sure to handle this case appropriately.
	
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



@end
