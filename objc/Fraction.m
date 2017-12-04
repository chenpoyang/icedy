//
//  Fraction.m
//  prog
//
//  Created by macbook on 14-11-1.
//  Copyright (c) 2014年 macbook. All rights reserved.
//

#import "Fraction.h"

static int gCounter;

@implementation Fraction

@synthesize numerator, denominator;

-(void) print
{
	NSLog(@"%i/%i", numerator, denominator);
}

-(double) convertToNum
{
	if (denominator != 0)
	{
		return (double) numerator / denominator;
	}
	else
	{
		return NAN;
	}
}

-(void) setTo:(int)n over:(int)d
{
	numerator = n;
	denominator = d;
}

-(void) reduce
{
	int u = numerator;
	int v = denominator;
	int temp;
    
	while (v != 0)
	{
		temp = u % v;
		u = v;
		v = temp;
	}
    
	numerator /= u;
	denominator /= u;
}

+(Fraction *) allocF
{
    extern int gCounter;
    
    ++gCounter;
    
    return [Fraction alloc];
}

+(int) count
{
    extern int gCounter;
    
    return gCounter;
}

-(NSString *) description
{
    return [NSString stringWithFormat: @"%i/%i", numerator, denominator];
}

@end
