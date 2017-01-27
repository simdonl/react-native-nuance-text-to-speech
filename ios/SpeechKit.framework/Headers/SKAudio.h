//
//  SKAudio.h
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

typedef NS_ENUM(NSInteger, SKPCMSampleFormat) {
    SKPCMSampleFormatSignedLinear16, // Linear, signed, 16-bit samples
};


/*!
 @abstract Description of format of PCM audio.
 */
@interface SKPCMFormat : NSObject

/*!
 @abstract Sampling rate of audio in Hz
 */
@property (assign) float sampleRate;
/*!
 @abstract Number of channels, assumed to be interleaved.
 */
@property (assign) int channels;
/*!
 @abstract Encoding of each sample, assumed to be little-endian.
 */
@property (assign) SKPCMSampleFormat sampleFormat;

@end
/*!
 @abstract The SKAudio class contains audio data for use with SKAudioPlayer.
 */
@interface SKAudio : NSObject

@end

/*!
 @abstract The SKAudioFile class represents an audio file from disk.
 
 @discussion This class is usually used to load user provided earcons.  The transaction delegate may however provide an SKAudioFile instance instead of an SKSynthesizedAudio instance in transaction:didReceiveAudio: for non-traditional TTS responses or service specific responses.
 */
@interface SKAudioFile : SKAudio
/*!
 @abstract Initializes with audio from a URL.
 
 @discussion Right now only single-channel, 16kHz, 16-bit signed linear PCM is accepted.
 */
- (instancetype)initWithURL:(NSURL *)url pcmFormat:(SKPCMFormat*)pcmFormat;

@end
