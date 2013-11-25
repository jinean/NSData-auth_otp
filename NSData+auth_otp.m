//  Created by jinean on 13-11-25.
//  Copyright (c) 2013年 jinean. All rights reserved.
//

#import "NSData+auth_otp.h"

@implementation NSData (auth_otp)

- (NSString *)dynamicPasscode
{
    return [self dynamicPasscode:[NSDate date]];
}

- (NSString *)dynamicPasscode:(NSDate *)sTime
{
    return [self dynamicPasscode:sTime length:NSDATA_AUTH_OTP_LENGTH_DEFAULT];
}

- (NSString *)dynamicPasscode:(NSDate *)sTime length:(int)length
{
    return [self dynamicPasscode:sTime length:length secondMax:NSDATA_AUTH_OTP_SECONDMAX_DEFAULT autoZero:YES];
}

- (NSString *)dynamicPasscode:(NSDate *)sTime length:(int)length secondMax:(int)secondMax
{
    return [self dynamicPasscode:sTime length:length secondMax:secondMax autoZero:YES];
}

- (NSString *)dynamicPasscode:(NSDate *)sTime length:(int)length secondMax:(int)secondMax autoZero:(BOOL)autoZero
{
    NSTimeInterval seconds = [sTime timeIntervalSince1970];
    uint64_t counter = (uint64_t) (seconds / secondMax);
    return [self _generateDynamicPasscode:counter length:length autoZero:autoZero];
}

- (NSString *)_generateDynamicPasscode:(uint64_t)counter length:(int)length autoZero:(BOOL)autoZero
{
    CCHmacAlgorithm alg = kCCHmacAlgSHA1;
    NSUInteger hashLength = CC_SHA1_DIGEST_LENGTH;
    NSMutableData *hash = [NSMutableData dataWithLength:hashLength];
    counter = NSSwapHostLongLongToBig(counter);
    NSData *counterData = [NSData dataWithBytes:&counter length:sizeof(counter)];
    CCHmacContext ctx;
    CCHmacInit(&ctx, alg, [self bytes], [self length]);
    CCHmacUpdate(&ctx, [counterData bytes], [counterData length]);
    CCHmacFinal(&ctx, [hash mutableBytes]);
    
    const char *ptr = [hash bytes];
    char const offset = ptr[hashLength-1] & 0x0f;
    unsigned long truncatedHash = NSSwapBigLongToHost(*((unsigned long *)&ptr[offset])) & 0x7fffffff;
    
    int maxDigits = 1;while (length--)maxDigits*=10;

    unsigned long pinValue = truncatedHash % maxDigits;
    
    if(autoZero)
    {
        return [NSString stringWithFormat:@"%0*ld", length, pinValue];
    }
    else
    {
        return [NSString stringWithFormat:@"%ld",pinValue];
    }
}

@end
