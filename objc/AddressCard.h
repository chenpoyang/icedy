//
//  AddressCard.h
//  prog
//
//  Created by Peck Chen on 19/12/2016.
//  Copyright © 2016 peck.chen. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AddressCard : NSObject

@property (copy, nonatomic) NSString *name, *email;

-(void) setName: (NSString *) theName andEmail: (NSString *) theEmail;
-(void) print;
-(NSComparisonResult) compareNames: (AddressCard *) element;

@end
