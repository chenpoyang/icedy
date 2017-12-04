//
//  AddressBook.h
//  prog
//
//  Created by Peck Chen on 19/12/2016.
//  Copyright © 2016 peck.chen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AddressCard.h"

@interface AddressBook : NSObject

@property (nonatomic, copy) NSString *bookName;
@property (nonatomic, strong) NSMutableArray *book;

-(id) initWithName: (NSString *) name;
-(void) addCard: (AddressCard *) theCard;
-(void) removeCard: (AddressCard *) theCard;
-(unsigned long) entries;
-(void) list;
-(AddressCard *) lookup: (NSString *) theName;
-(void) sort;

@end
