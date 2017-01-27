//
//  NuanceTextToSpeechDelegate.h
//  NuanceTextToSpeechDelegate
//
//  Created by Dominique van Mil on 27/01/2017.
//  Copyright © 2017 SIMDO. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioServices.h>

@interface NuanceTextToSpeechDelegate : NSObject <AVSpeechSynthesizerDelegate>
{
  AVSpeechSynthesizer* synthesizer;
}

- (void)speak:(NSDictionary*)args;

- (void)notify:(NSDictionary*)args;

@end
