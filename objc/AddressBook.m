//
//  AddressBook.m
//  prog
//
//  Created by Peck Chen on 19/12/2016.
//  Copyright © 2016 peck.chen. All rights reserved.
//

#import "AddressBook.h"
#import "AddressCard.h"

@implementation AddressBook

@synthesize bookName, book;

-(id) initWithName: (NSString *) name
{
    self = [super init];
    if (self)
    {
        bookName = [NSString stringWithString: name];
        book = [NSMutableArray array];
    }
    
    return self;
}

-(id) init
{
    return [self initWithName: @"NoName"];
}

-(void) addCard: (AddressCard *) theCard
{
    [book addObject: theCard];
}

-(void) removeCard: (AddressCard *) theCard
{
    [book removeObject: theCard];
}

-(unsigned long) entries
{
    return [book count];
}

-(void) list
{
    NSLog(@"==== Contents of : %@ ====", bookName);
    
    for (AddressCard *theCard in book)
    {
        NSLog(@"%-15s %s", [theCard.name UTF8String], [theCard.email UTF8String]);
    }
    NSLog(@"============================================");
}

-(AddressCard *) lookup: (NSString *) theName
{
    for (AddressCard *nextCard in book)
    {
        if ([nextCard.name caseInsensitiveCompare: theName] == NSOrderedSame)
        {
            return nextCard;
        }
    }
    
    return nil;
}

-(void) sort
{
    //[book sortUsingSelector: @selector(compareNames:)];
//    [book sortUsingComparator:
//        ^(id obj1, id obj2)
//        {
//            return [obj1 compareNames: obj2];
//        }];
    [book sortUsingComparator:
        ^(id obj1, id obj2)
        {
            return [[obj1 name] compare: [obj2 name]];
        }];
}

@end
