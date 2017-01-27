//
//  SKRecognition.h
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


/*!
 @class SKRecognition
 @abstract The SKRecognition class contains speech recognition text results.
 */
@interface SKRecognition : NSObject

/*!
 @abstract Text for top recognition.
 @discussion This is the recognized phrase with the highest confidence and is equivalent to calling `[recognition.details firstObject].text`.
 */
@property (nonatomic, readonly) NSString *text;

/*!
 @abstract Returns all of the recognized phrases for the recognition.
 @discussion This array contains SKRecognizedPhrase objects that each represent a single recognition alternative.  The phrases are listed in priority order such that the first element has the highest confidence and the last element has the least confidence.  Each phrase consists of a sequence of SKRecognizedWord objects with indidual confidences and timing information. Using the timing data it is possible to allow the user to correct recognition errors by providing alternate choices.  The SKTextBuffer class provides a robust implementation of alternate selection that allows for multiple recognitions and user modifications within a single block of text.  Usually the SKTextBuffer class should be used instead of using these detailed results directly.
 */
@property (nonatomic, readonly) NSArray *details;

@end


/*!
 @abstract The information related to the recognized phrase.
 @discussion The SKRecognizedPhrase class contains a sequence of SKRecognizedWord objects and information related to the phrase.
 */
@interface SKRecognizedPhrase : NSArray

/*!
 @abstract The text representation of the recognized phrase.
 @discussion This string is the properly formatted concatenation of all of the SKRecognizedWord elements.
 */
@property (nonatomic, readonly) NSString *text;

/*!
 @abstract The score representing how accurately the phrase was recognized.
 @discussion Confidence scores are not explicitly defined and can not be directly evaluated on any scale.  Confidence scores are useful for comparing the recognition quality between multiple recognized phrases received from a single recognition.
 */
@property (nonatomic, readonly) NSInteger confidence;

/*!
 @abstract A sequence of SKRecognizedWord consisting of the current recognized phrase.
 */
@property (nonatomic, readonly) NSArray *words;

@end


/*!
 @abstract A single recognized word within a recognized phrase.
 */
@interface SKRecognizedWord : NSObject

/*!
 @abstract The text representation of the recognized word.
 */
@property (nonatomic, readonly) NSString *text;

/*!
 @abstract The start time of the segment of speech represented by this word.
 @discussion This value is a time interval relative to the beginning of the complete utterance.
 */
@property (nonatomic, readonly) NSTimeInterval start;

/*!
 @abstract The end time of the segment of speech represented by this word.
 */
@property (nonatomic, readonly) NSTimeInterval end;

/*!
 @abstract True if the word should be separated from the next word by a space.
 @discussion This value is language dependent.  In many languages this value will be False for words at the end of a sentence followed by punctuation.
 */
@property (nonatomic, readonly) Boolean noSpaceBefore;

/*!
 @abstract True if the word should be separated from the next word by a space.
 @discussion This value is language dependent. In many languages this value will be False for words at the end of a sentence followed by punctuation.
 */
@property (nonatomic, readonly) Boolean noSpaceAfter;

/*!
 @abstract The score representing how accurately the word was recognized.
 @discussion While the confidence score can not be individually evaluated on a scale, you can compare the confidences scores between words in a phrase to identify the higher confidence and lower confidence words.  This can be useful to provide user feedback, such as underlining the word, for the words that may have useful alternates.
 */
@property (nonatomic, readonly) NSInteger confidence;

@end
