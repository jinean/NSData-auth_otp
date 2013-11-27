//
//  NSData+auth_otp.h
//
//  Created by jinean on 13-11-25.
//  Copyright (c) 2013年 jinean. All rights reserved.
//

#import <Foundation/Foundation.h>

#define NSDATA_AUTH_TOTP_LENGTH_DEFAULT                8
#define NSDATA_AUTH_TOTP_SECONDMAX_DEFAULT             30
#define NSDATA_AUTH_TOTP_AUTOFILLUP                    @"0"
@interface NSData (auth_totp)

- (NSString *)dynamicTotpPasscode;

- (NSString *)dynamicTotpPasscode:(NSDate *)sTime;

- (NSString *)dynamicTotpPasscode:(NSDate *)sTime length:(int)length;

- (NSString *)dynamicTotpPasscode:(NSDate *)sTime length:(int)length secondMax:(int)secondMax;

- (NSString *)dynamicTotpPasscode:(NSDate *)sTime length:(int)length secondMax:(int)secondMax autoZero:(BOOL)autoZero;

- (NSString *)dynamicTotpPasscode:(NSDate *)sTime length:(int)length secondMax:(int)secondMax autofillUp:(NSString *)autofillUp;

@end
