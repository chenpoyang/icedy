//
//  Fraction.h
//  prog
//
//  Created by macbook on 14-11-1.
//  Copyright (c) 2014年 macbook. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Fraction : NSObject

@property int numerator, denominator;

-(void) print;
-(void) setTo: (int) n over: (int) d;
-(double) convertToNum;
-(void) reduce;
+(Fraction *) allocF;
+(int) count;
-(NSString *) description;

@end
