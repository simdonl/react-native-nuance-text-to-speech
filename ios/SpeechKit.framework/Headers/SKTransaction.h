//
//  SKTransaction.h
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


@class SKRecognition;
@class SKInterpretation;
@class SKAudio;


/*
 Recognition Types
 */

/*!
 @abstract Search optimized recognition.
 */
extern NSString * const SKTransactionSpeechTypeSearch;

/*!
 @abstract Dictation optimized recognition.
 */
extern NSString * const SKTransactionSpeechTypeDictation;

/*!
 @abstract TV NLU optimized recognition.
 */
extern NSString * const SKTransactionSpeechTypeTV;

/*!
 @abstract An NSNumber with a boolean value indicating whether TTS should be automatically played when received.
 */
extern NSString * const SKTransactionAutoPlayTTSKey;

/*!
 @abstract An NSNumber with a boolean value indicating whether SpeechKit should set and restore the audio sesssion category.
 */
extern NSString * const SKTransactionManageCategoryKey;

/*!
 @abstract An NSString equal to one of the result delivery method constants.
 */
extern NSString * const SKTransactionResultDeliveryKey;

/*!
 @abstract Deliver results during speech recognition, when possible, that contain the text recognized up to that point as well as delivering a final result containing text for all speech recognized.  Use as a value for SKTransactionResultDeliveryKey.
 */
extern NSString * const SKTransactionResultDeliveryProgressive;

/*!
 @abstract Deliver only a final result containing text for all speech recognized.  Use as a value for SKTransactionResultDeliveryKey.
 */
extern NSString * const SKTransactionResultDeliveryFinal;

/*!
 @enum End-of-Speech Detection Models.
 @abstract These constants define the various end-of-speech detection models.
 @constant SKTransactionEndOfSpeechDetectionNone Do not detect the end of speech.
 @constant SKTransactionEndOfSpeechDetectionShort Detect the end of a short phrase with no pauses.  Because this model does not tolerate much silence once speech has started, it detects the end of speech more quickly.
 @constant SKTransactionEndOfSpeechDetectionLong Detect the end of a longer phrase, sentence or sentences that may have brief pauses.  Because this model tolerates longer (but still brief) intervals of silence in the middle of speech, it is less likely to wrongly detect the end of speech prematurely but also takes longer to detect the end of speech when the speaker is actually finished.
 */

typedef NS_ENUM(NSUInteger, SKTransactionEndOfSpeechDetection) {
    SKTransactionEndOfSpeechDetectionNone = 1,
    SKTransactionEndOfSpeechDetectionShort = 2,
    SKTransactionEndOfSpeechDetectionLong = 3,
};


@protocol SKTransaction <NSObject>

@optional

/*!
 @abstract Audio power level.
 @discussion Indicates the current power level of the microphone audio. Use this value to indicate to you user how loudly they are speaking.
 */
@property(nonatomic,readonly) float audioLevel;

/*!
 @abstract Stop recording audio and complete the transaction.
 */
- (void)stopRecording;

@required

@property (nonatomic, readonly) NSString *sessionId;

/*!
 @abstract Cancel the transaction.
 */
- (void)cancel;

@end


@interface SKTransaction : NSObject <SKTransaction>

@end


@protocol SKTransactionDelegate <NSObject>
@optional

/*!
 @abstract Called when the transaction starts recording audio.
 */
- (void)transactionDidBeginRecording:(SKTransaction *)transaction;

/*!
 @abstract Called when the transaction stops recording audio.
 */
- (void)transactionDidFinishRecording:(SKTransaction *)transaction;

/*!
 @abstract Called when the transaction receives a text recognition.
 @discussion This delegate method may be called multiple times depending on the specific recognition operation and options.  In a standard one-shot recognition this method will be called once after recording completes and the text is successfully recognized.  When using progressive dictation results, this method may be called multiple times before recording completes.  Each successive recognition will replace any previously received recognition with the same chunk ID.
 */
- (void)transaction:(SKTransaction *)transaction didReceiveRecognition:(SKRecognition *)recognition;

/*!
 @abstract Called when the transaction receives an interpretation.
 @discussion This delegate method is only called when using a grammar, explicitly or as a side effect of a custom recognition service.  The interpretation is a structured response that varies by grammar.  This method may be called multiple times during a transaction although under normal circumstances this will only be called once.
 */
- (void)transaction:(SKTransaction *)transaction didReceiveInterpretation:(SKInterpretation *)interpretation;

/*!
 @abstract Called when the transaction returns a custom application response.
 @discussion This delegate method is only called when using a custom service. The response dictionary is an application specific json-like data structure as defined by the service. This method may be called zero or more times.
 */
- (void)transaction:(SKTransaction *)transaction didReceiveServiceResponse:(NSDictionary *)response;

/*!
 @abstract Called when the transaction returns audio data.
 @discussion This delegate method is usually called in response to a TTS request. The audio object may contain a proprietary TTS audio buffer or other generic audio data.  It is usually not necessary to implement this delegate method; using the speakString:withVoice:delegate: and related methods on the SKSession will automatically play and enqueue TTS responses on the associated session SKAudioPlayer.  Implementing this method will override the default action and allow you to intercept and store the response.  Implementing this method will prevent the audio from being enqueued automatically, however you may enqueue the audio manually via the default SKSession SKAudioPlayer. Usually this is used to create cached TTS prompts that will be played multiple times or in the future when network connectivity is uncertain.
 */
- (void)transaction:(SKTransaction *)transaction didReceiveAudio:(SKAudio *)audio;

/*!
 @abstract Called when the transaction completes successfully.
 @discussion This method is called when the transaction has completed successfully; all recognition responses, interpretations, application responses and audio buffers have been fully received.  The suggestion is a string with helpful user text that describes how the user may improve recognition in future transactions.  This suggestion will only be present if the recognition is sub-optimal and may be `nil` when there are no problems.  This method or transaction:didFailWithError:suggestion: will always be called, but never both.
 */
- (void)transaction:(SKTransaction *)transaction didFinishWithSuggestion:(NSString *)suggestion;

/*!
 @abstract Called when the transaction has an error.
 @discussion This method is called when the recognition process results in an error due to any number of circumstances.  The audio system may fail to initialize, the server connection may be disrupted or a parameter specified during initialization, such as language or authentication information was invalid.  This method will still be called in the case that multiple responses are returned and an error occurs before the transaction completes.  This method or transaction:didFinishWithSuggestion: will always be called, but never both.
 */
- (void)transaction:(SKTransaction *)transaction didFailWithError:(NSError *)error suggestion:(NSString *)suggestion;

@end
