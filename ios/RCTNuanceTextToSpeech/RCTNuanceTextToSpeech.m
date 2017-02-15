//
//  RCTNuanceTextToSpeech.m
//  RCTNuanceTextToSpeech
//
//  Created by Dominique van Mil on 27/01/2017.
//  Copyright © 2017 SIMDO. All rights reserved.
//

#import "RCTNuanceTextToSpeech.h"
#import "RCTLog.h"

@implementation RCTNuanceTextToSpeech

@synthesize nuanceTextToSpeechDelegate;

RCT_EXPORT_MODULE();

-(instancetype)init
{
  self = [super init];
  if (self) {
    nuanceTextToSpeechDelegate = [[NuanceTextToSpeechDelegate alloc] init];
  }

  return self;
}

RCT_EXPORT_METHOD(configure:(NSDictionary *)args)
{
	RCTLogInfo(@"RCTNuanceTextToSpeech #configure");
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
		[nuanceTextToSpeechDelegate configure:args];
	});
}

RCT_EXPORT_METHOD(speak:(NSDictionary *)args)
{
  RCTLogInfo(@"RCTNuanceTextToSpeech #speak");
  dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
    [nuanceTextToSpeechDelegate speak:args];
  });
}

RCT_EXPORT_METHOD(notify:(NSDictionary *)args)
{
  RCTLogInfo(@"RCTNuanceTextToSpeech #notify");
  dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
    [nuanceTextToSpeechDelegate notify:args];
  });
}

@end
