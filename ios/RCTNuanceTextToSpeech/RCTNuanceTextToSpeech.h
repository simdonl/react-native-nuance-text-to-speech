//
//  RCTNuanceTextToSpeech.h
//  RCTNuanceTextToSpeech
//
//  Created by Dominique van Mil on 27/01/2017.
//  Copyright © 2017 SIMDO. All rights reserved.
//

#import "RCTBridgeModule.h"
#import "NuanceTextToSpeechDelegate.h"

@interface RCTNuanceTextToSpeech : NSObject <RCTBridgeModule>

@property (nonatomic, strong) NuanceTextToSpeechDelegate* nuanceTextToSpeechDelegate;

@end
