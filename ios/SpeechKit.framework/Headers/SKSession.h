//
//  SKSession.h
//  SpeechKit
//
// Copyright 2010, Nuance Communications Inc. All rights reserved.
//
// Nuance Communications, Inc. provides this document without representation 
// or warranty of any kind. The information in this document is subject to 
// change without notice and does not represent a commitment by Nuance 
// Communications, Inc. The software and/or databases described in this 
// document are furnished under a license agreement and may be used or 
// copied only in accordance with the terms of such license agreement.  
// Without limiting the rights under copyright reserved herein, and except 
// as permitted by such license agreement, no part of this document may be 
// reproduced or transmitted in any form or by any means, including, without 
// limitation, electronic, mechanical, photocopying, recording, or otherwise, 
// or transferred to information storage and retrieval systems, without the 
// prior written permission of Nuance Communications, Inc.
// 
// Nuance, the Nuance logo, Nuance Recognizer, and Nuance Vocalizer are 
// trademarks or registered trademarks of Nuance Communications, Inc. or its 
// affiliates in the United States and/or other countries. All other 
// trademarks referenced herein are the property of their respective owners.
//

#import <Foundation/Foundation.h>
#import "SKTransaction.h"


@class SKAudioPlayer;
@class SKTransaction;
@class SKAudio;
@protocol SKTransactionDelegate;


@interface SKSession : NSObject

/*!
 @abstract Audio Player.
 @discussion This is an instance of Audio Player that can be used to queue SKAudio objects.
 */
@property (nonatomic, readonly) SKAudioPlayer *audioPlayer;

@property (nonatomic, strong) SKAudio *startEarcon;
@property (nonatomic, strong) SKAudio *endEarcon;
@property (nonatomic, strong) SKAudio *cancelEarcon;
@property (nonatomic, strong) SKAudio *errorEarcon;

/*!
 @abstract Initialize the SKSession.
 @discussion Initializes an SKSession and may establish a connection with the speech server.
 @param url Speech service endpoint (nmsps://ApplicationID@service.nuance.com:443).
 WARNING: You must use SSL to make sure all transactions are made on a secure socket. (nmsps)
 @param token The application secret token.
 @result SKSession instance.
 */
- (instancetype)initWithURL:(NSURL *)url appToken:(NSString*)token;


/*!
 @abstract Initialize the SKSession.
 @discussion Initializes an SKSession and may establish a connection with the speech server. This will use your credentials provided by Twitter Fabric in Info.plist.
 @result SKSession instance.
 */
- (instancetype)initWithFabric;

/*!
 @abstract Perform speech recognition.
 @param type Speech recognition model.
 @param detection End of speech detection.
 @param language Spoken language of the end user.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)recognizeWithType:(NSString *)type
                           detection:(SKTransactionEndOfSpeechDetection)detection
                            language:(NSString *)language
                            delegate:(id <SKTransactionDelegate>)delegate
 NS_SWIFT_UNAVAILABLE("Use the options variety of recognize");

/*!
 @abstract Perform speech recognition.
 @param type Speech recognition model.
 @param detection End of speech detection.
 @param language Spoken language of the end user.
 @param options Additional ASR options.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)recognizeWithType:(NSString *)type
                           detection:(SKTransactionEndOfSpeechDetection)detection
                            language:(NSString *)language
                             options:(NSDictionary *)options
                            delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Perform a custom speech recognition.
 @discussion This method recognizes speech using a custom service which may perform many service specific tasks.  The result is not limited to speech recognition and may return application data, audio or any of the possible transaction results.
 @param service Service ID.
 @param detection End of speech detection.
 @param language Spoken language of the end user.
 @param data Application specific data dictionary.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)recognizeWithService:(NSString *)service
                              detection:(SKTransactionEndOfSpeechDetection)detection
                               language:(NSString *)language
                                   data:(NSDictionary *)data
                               delegate:(id <SKTransactionDelegate>)delegate
 NS_SWIFT_UNAVAILABLE("Use the options variety of recognize");

/*!
 @abstract Perform a custom speech recognition.
 @discussion This method recognizes speech using a custom service which may perform many service specific tasks.  The result is not limited to speech recognition and may return application data, audio or any of the possible transaction results.
 @param service Service ID.
 @param detection End of speech detection.
 @param language Spoken language of the end user.
 @param data Application specific data dictionary.
 @param options Additional ASR options.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)recognizeWithService:(NSString *)service
                                detection:(SKTransactionEndOfSpeechDetection)detection
                                 language:(NSString *)language
                                     data:(NSDictionary *)data
                                  options:(NSDictionary *)options
                                 delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Send a message to a custom service.
 @discussion This method is the same as the recognizeWithService:... methods except that it does not record and stream audio to the service.  Instead this method may be used for non-speech queries such as configuration or text recognition.
 @param service Service ID.
 @param language Spoken language of the end user.
 @param data Application specific data dictionary.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)transactionWithService:(NSString *)service
                                 language:(NSString *)language
                                     data:(NSDictionary *)data
                                 delegate:(id <SKTransactionDelegate>)delegate
 NS_SWIFT_UNAVAILABLE("Use the options variety of transaction");

/*!
 @abstract Send a message to a custom service.
 @discussion This method is the same as the recognizeWithService:... methods except that it does not record and stream audio to the service.  Instead this method may be used for non-speech queries such as configuration or text recognition.
 @param service Service ID.
 @param language Spoken language of the end user.
 @param data Application specific data dictionary.
 @param options Additional ASR options.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)transactionWithService:(NSString *)service
                                 language:(NSString *)language
                                     data:(NSDictionary *)data
                                  options:(NSDictionary *)options
                                 delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Peform text to speech from a string.
 
 @param string The text to synthesize.
 @param voice The voice to use for speech synthesis.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)speakString:(NSString *)string
                       withVoice:(NSString *)voice
                        delegate:(id <SKTransactionDelegate>)delegate
 NS_SWIFT_UNAVAILABLE("Use the options variety of speak");

/*!
 @abstract Peform text to speech from a string.
 
 @param string The text to synthesize.
 @param voice The voice to use for speech synthesis.
 @param options Additional ASR options.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)speakString:(NSString *)string
                       withVoice:(NSString *)voice
                         options:(NSDictionary *)options
                        delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Perform text to speech from SSML markup.
 
 @param markup The SSML to synthesize.
 @param voice The voice to use for speech synthesis.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)speakMarkup:(NSString *)markup
                       withVoice:(NSString *)voice
                        delegate:(id <SKTransactionDelegate>)delegate
 NS_SWIFT_UNAVAILABLE("Use the options variety of speak");

/*!
 @abstract Perform text to speech from SSML markup.
 
 @param markup The SSML to synthesize.
 @param voice The voice to use for speech synthesis.
 @param options Additional TTS options.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)speakMarkup:(NSString *)markup
                       withVoice:(NSString *)voice
                         options:(NSDictionary *)options
                        delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Perform text to speech from a string.
 
 @param string The text to synthesize.
 @param language The language to use for speech synthesis. We will select the best voice for the language.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)speakString:(NSString *)string
                    withLanguage:(NSString *)language
                        delegate:(id <SKTransactionDelegate>)delegate
 NS_SWIFT_UNAVAILABLE("Use the options variety of speak");

/*!
 @abstract Perform text to speech from a string.
 
 @param string The text to synthesize.
 @param language The language to use for speech synthesis.  The server will select the best voice for the language.
 @param options Additional TTS options.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)speakString:(NSString *)string
                    withLanguage:(NSString *)language
                         options:(NSDictionary *)options
                        delegate:(id <SKTransactionDelegate>)delegate;

/*!
 @abstract Perform text to speech from SSML markup.
 @param markup The SSML to synthesize.
 @param language The language to use for speech synthesis. We will select the best voice for the language.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)speakMarkup:(NSString *)markup
                    withLanguage:(NSString *)language
                        delegate:(id <SKTransactionDelegate>)delegate
 NS_SWIFT_UNAVAILABLE("Use the options variety of speak");

/*!
 @abstract Perform text to speech from SSML markup.
 
 @param markup The SSML to synthesize.
 @param language The language to use for speech synthesis.  The server will select the best voice for the language.
 @param options Additional TTS options.
 @param delegate SKTransactionDelegate to be notified throughout the transaction.
 @result SKTransaction instance.
 */
- (SKTransaction *)speakMarkup:(NSString *)markup
                    withLanguage:(NSString *)language
                         options:(NSDictionary *)options
                        delegate:(id <SKTransactionDelegate>)delegate;
@end
