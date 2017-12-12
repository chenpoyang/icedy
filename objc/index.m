#import <Foundation/Foundation.h>

int main(int argc, char *argv[])
{
    @autoreleasepool {
        NSString *str = @"Hello World!";
        NSLog(@"str = %@, len = %lu", str, [str length]);
    }

    return 0;
}
