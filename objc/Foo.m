//
//  Foo.m
//  prog
//
//  Created by Peck Chen on 13/12/2016.
//  Copyright © 2016 peck.chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Foo.h"

@implementation Foo

-(void) setGlobalVar: (int) val
{
    extern int gGlobalVar;
    
    gGlobalVar = val;
}

@end
