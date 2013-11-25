//  NSData+auth_otp.h
//  Created by jinean on 13-11-25.
//  Copyright (c) 2013年 jinean. All rights reserved.
//

#import <Foundation/Foundation.h>

#define NSDATA_AUTH_OTP_LENGTH_DEFAULT                6
#define NSDATA_AUTH_OTP_SECONDMAX_DEFAULT             30

@interface NSData (auth_otp)

- (NSString *)dynamicPasscode;

- (NSString *)dynamicPasscode:(NSDate *)sTime;

- (NSString *)dynamicPasscode:(NSDate *)sTime length:(int)length;

- (NSString *)dynamicPasscode:(NSDate *)sTime length:(int)length secondMax:(int)secondMax;

- (NSString *)dynamicPasscode:(NSDate *)sTime length:(int)length secondMax:(int)secondMax autoZero:(BOOL)autoZero;

@end
