//
//  NSSet+Printing.m
//  prog
//
//  Created by Peck Chen on 22/12/2016.
//  Copyright © 2016 peck.chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSSet+Printing.h"

@implementation NSSet (Printing)

-(void) print
{
    printf("{ ");
    
    for (NSNumber *element in self)
    {
        printf(" %li ", (long) [element integerValue]);
    }
    
    printf("} \n");
}


@end
