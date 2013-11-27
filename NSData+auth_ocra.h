//
//  NSData+auth_ocra.h
//  Created by jinean on 13-11-27.
//  Copyright (c) 2013年 jinean. All rights reserved.
//

#import <Foundation/Foundation.h>
#define NSDATA_AUTH_OCRA_SUITE_DEFAULT  @"OCRA-1:HOTP-SHA1-6:QN08"
@interface NSData (auth_ocra)

- (NSString *)dynamicOcraPasscode:(NSString*)question error:(NSError**) error;

- (NSString *)dynamicOcraPasscode:(NSString*)ocraSuite question:(NSString*)question error:(NSError**) error;

- (NSString *)dynamicOcraPasscode:(NSString*)ocraSuite
                          counter:(NSString*)counter
                         question:(NSString*)question
                         password:(NSString*)password
               sessionInformation:(NSString*)sessionInformation
                        timestamp:(NSString*)timeStamp
                            error:(NSError**)error;

@end
