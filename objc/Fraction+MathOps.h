//
//  Fraction+MathOps.h
//  prog
//
//  Created by Peck Chen on 14/12/2016.
//  Copyright © 2016 peck.chen. All rights reserved.
//

#ifndef Fraction_MathOps_h
#define Fraction_MathOps_h

#import "Fraction.h"

@interface Fraction (MathOps)

-(Fraction *) add: (Fraction *) f;
-(Fraction *) subtract: (Fraction *) f;
-(Fraction *) multiply: (Fraction *) f;
-(Fraction *) divide: (Fraction *) f;

@end

#endif /* Fraction_MathOps_h */
