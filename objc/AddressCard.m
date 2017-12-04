//
//  AddressCard.m
//  prog
//
//  Created by Peck Chen on 19/12/2016.
//  Copyright © 2016 peck.chen. All rights reserved.
//

#import "AddressCard.h"

@implementation AddressCard

@synthesize name, email;

-(void) setName: (NSString *) theName andEmail: (NSString *) theEmail
{
    self.name = theName;
    self.email = theEmail;
}

-(void) print
{
    NSLog(@"=================================");
    NSLog(@"|                               |");
    NSLog(@"| %-29s |", [name UTF8String]);
    NSLog(@"| %-29s |", [email UTF8String]);
    NSLog(@"|                               |");
    NSLog(@"|                               |");
    NSLog(@"|     o                   o     |");
    NSLog(@"=================================");
}

-(BOOL) isEqual: (AddressCard *) theCard
{
    if ([name isEqualToString: theCard.name] == YES &&
        [email isEqualToString: theCard.email] == YES)
    {
        return YES;
    }
    
    return NO;
}

-(NSComparisonResult) compareNames: (id) element
{
    return [name compare: [element name]];
    
//    if ([name compare: [element name]] == NSOrderedAscending)
//    {
//        return NSOrderedDescending;
//    }
//    else if ([name compare: [element name]] == NSOrderedDescending)
//    {
//        return NSOrderedAscending;
//    }
//    else
//    {
//        return NSOrderedSame;
//    }
}

@end
