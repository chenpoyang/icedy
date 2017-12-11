//  main.m
//  prog
//
//  Created by Peck Chen on 28/11/2016.
//  Copyright © 2016 peck.chen. All rights reserved.

#import <Foundation/Foundation.h>
#import "Complex.h"
#import "Fraction.h"
#import "Rectangle.h"
#import "Square.h"
#import "XYPoint.h"
#import "Foo.h"
#import "Fraction+MathOps.h"
#import "AddressCard.h"
#import "AddressBook.h"
#import "NSSet+Printing.h"

int gGlobalVar = 5;

int main(int argc, const char * argv[])
{
	@autoreleasepool {
		Fraction *f1 = [[Fraction alloc] init];
		Fraction *f2 = [[Fraction alloc] init];
		Fraction *fracResult;

		[f1 setTo:-1 over:10];
		[f2 setTo:2 over:15];
		fracResult = [f1 divide:f2];
		[fracResult print];

		NSLog(@"description print of Fraction: %@", fracResult);

		Rectangle *myRect = [[Rectangle alloc] init];
		[myRect setWidth: 5 andHeight: 8];

		NSLog(@"Rectangle: w = %i, h = %i", myRect.width, myRect.height);
		NSLog(@"Area = %i, Perimeter = %i", [myRect area], [myRect perimeter]);

		Square *mySquare = [[Square alloc] init];
		[mySquare setSide: 5];
		NSLog(@"Square s = %i", [mySquare side]);
		NSLog(@"Area = %i, Perimeter = %i", [mySquare area], [mySquare perimeter]);

		Rectangle *rect = [[Rectangle alloc] init];
		XYPoint *myPoint = [[XYPoint alloc] init];

		[myPoint setX: 100 andY: 200];
		[rect setWidth: 5 andHeight: 8];
		rect.origin = myPoint;

		NSLog(@"Rectangle w = %i, h = %i", rect.width, rect.height);
		NSLog(@"Origin at (%i, %i)", rect.origin.x, rect.origin.y);
		NSLog(@"Area = %i, Perimeter = %i", [rect area], [rect perimeter]);

		[myPoint setX: 50 andY: 50];
		NSLog(@"Origin at (%i, %i)", rect.origin.x, rect.origin.y);

		Complex *c1 = [[Complex alloc] init];
		Complex *c2 = [[Complex alloc] init];
		Complex *compResult;

		[c1 setReal:18.0 andImaginary:2.5];
		[c2 setReal:-5.0 andImaginary:3.2];

		[c1 print];
		NSLog(@"      +");
		[c2 print];
		NSLog(@"-------");
		compResult = [c1 add: c2];
		[compResult print];

		id dataValue;
		dataValue = fracResult;
		[dataValue print];

		dataValue = compResult;
		[dataValue print];

		Square *square = [[Square alloc] init];

		// isMemberOf:
		if ([square isMemberOfClass: [Square class]] == YES)
			NSLog(@"square is member of Square class");

		if ([square isMemberOfClass: [Rectangle class]] == YES)
			NSLog(@"square is member of Rectangle class");

		if ([square isMemberOfClass: [NSObject class]])
			NSLog(@"square is member of NSObject class");

		// isKindOf:
		if ([square isKindOfClass: [Square class]] == YES)
			NSLog(@"square is a kind of Square");

		if ([square isKindOfClass: [Rectangle class]] == YES)
			NSLog(@"square is a kind of Rectangle");

		if ([square isKindOfClass: [NSObject class]] == YES)
			NSLog(@"square is a kind of NSObject");

		// responsTo:
		if ([square respondsToSelector: @selector(setSide:)] == YES)
	NSLog(@"square responds to setSide: method");

		if ([square respondsToSelector: @selector(setWidth:andHeight:)] == YES)
   NSLog(@"square responds to setWidth:andWidth method");

		if ([square respondsToSelector: @selector(alloc)] == YES)
			NSLog(@"square responds to alloc method");

		// instanceRespondTo:
		if ([Rectangle instancesRespondToSelector: @selector(setSide:)] == YES)
NSLog(@"Instances of Rectangle respond to setSide: method");

		if ([Square instancesRespondToSelector: @selector(setSide:)] == YES)
NSLog(@"Instances of Square respond to setSide: method");

		if ([Square isSubclassOfClass: [Rectangle class]] == YES)
			NSLog(@"Square is a subclass of a rectangle");

		@try {
			[fracResult numerator];
		} @catch (NSException *exception) {
			NSLog(@"Caught %@ %@", [exception name], [exception reason]);
		} @finally {
			NSLog(@"Finished!");
		}

		Foo *myFoo = [[Foo alloc] init];
		NSLog(@"Global val: %i", gGlobalVar);

		[myFoo setGlobalVar: 100];
		NSLog(@"Global val: %i", gGlobalVar);

		Fraction *a, *b, *c;

		NSLog(@"Fraction allocated: %i", [Fraction count]);

		a = [[Fraction allocF] init];
		b = [[Fraction allocF] init];
		c = [[Fraction allocF] init];

		NSLog(@"Fraction allocated: %i", [Fraction count]);

		NSString *str = @"Hello World!";
		NSLog(@"string: %@, length = %lu", str, [str length]);

		NSNumber *myNumber, *floatNumber, *intNumber;
		NSInteger myInt;

		// integer
		intNumber = [NSNumber numberWithInteger: 100];
		myInt = [intNumber integerValue];
		NSLog(@"%li", myInt);

		// long
		myNumber = [NSNumber numberWithLong: 0xabcdef];
		NSLog(@"%lx", [myNumber longValue]);

		// char
		myNumber = [NSNumber numberWithChar: 'X'];
		NSLog(@"%c", [myNumber charValue]);

		// float
		floatNumber = [NSNumber numberWithFloat: 100.00];
		NSLog(@"%g", [floatNumber floatValue]);

		// double
		myNumber = [NSNumber numberWithDouble: 12345e+15];
		NSLog(@"%lg", [myNumber doubleValue]);

		// error occur
		NSLog(@"%li", (long)[myNumber integerValue]);

		// 验证两个number是否相等
		if ([intNumber isEqualToNumber: floatNumber] == YES)
		{
			NSLog(@"numbers are equal");
		}
		else
		{
			NSLog(@"Number are not equal");
		}

		// 验证一个Number是否小于、等于或大于另一个Number
		if ([intNumber compare: myNumber] == NSOrderedAscending)
		{
			NSLog(@"First Number is less than second");
		}

		NSLog(@"--------------------------------------");
		NSString *str1 = @"This is string A";
		NSString *str2 = @"This is string B";
		NSString *res;
		NSComparisonResult compareResult;

		// 计算字符串中的字符
		NSLog(@"Length of str1: %lu", [str1 length]);

		// 将一个字符串复制到另一个字符串
		res = [NSString stringWithString: str1];
		NSLog(@"copy: %@", res);

		// 验证两个字符串是否相等
		if ([str1 isEqualToString: res] == YES)
		{
			NSLog(@"str1 == res");
		}
		else
		{
			NSLog(@"str1 != res");
		}

		// 验证一个字符串是否小于、等于或大于另一个字符串
		compareResult = [str1 compare: str2];
		if (compareResult == NSOrderedAscending)
		{
			NSLog(@"str1 < str2");
		}
		else if (compareResult == NSOrderedSame)
		{
			NSLog(@"str1 == str2");
		}
		else // 必然是NSOrderedDescending
		{
			NSLog(@"str1 > str2");
		}

		// 将字符串转换为大写
		res = [str1 uppercaseString];
		NSLog(@"Uppercase conversion: %s", [res UTF8String]);

		// 将字符串转换为小字
		res = [str1 lowercaseString];
		NSLog(@"Lowercase conversion: %s", [res UTF8String]);

		NSLog(@"Original string: %@", str1);
		NSLog(@"Original string: %@", str2);
		NSLog(@"--------------------------------------");
		NSRange subRange;

		// 从字符串中提取前3个字符
		res = [str1 substringToIndex: 3];
		NSLog(@"First 3 chars of str1: %@", res);

		// 提取从索引5开始直到结尾的子字符串
		res = [str1 substringFromIndex: 5];
		NSLog(@"Chars from index 5 of str1: %@", res);

		// 提取从索引8开始到索引13的子字符串(6个字符)
		res = [[str1 substringFromIndex: 8] substringToIndex: 6];
		NSLog(@"Chars from index 8 through 13: %@", res);

		// 更简单的方法
		res = [str1 substringWithRange: NSMakeRange(8, 6)];
		NSLog(@"Chars from index 8 through 13: %@", res);
		// 从另一个字符串中查找一个字符串
		subRange = [str1 rangeOfString: @"string A"];
		NSLog(@"String is at index %lu, length is %lu",
				subRange.location, subRange.length);

		subRange = [str1 rangeOfString: @"string B"];

		if (subRange.location == NSNotFound)
			NSLog(@"String not found");
		else
			NSLog(@"String is at index %lu, length is %lu",
					subRange.location, subRange.length);

		NSLog(@"Original string: %@", str1);
		NSLog(@"Original string: %@", str2);
		NSLog(@"--------------------------------------");
		NSString *search, *replace;
		NSMutableString *mstr;
		NSRange substr;

		// 从不可变字符串创建可变字符串
		mstr = [NSMutableString stringWithString: str1];
		NSLog(@"可变字符串: %@", mstr);

		// 插入字符串
		[mstr insertString: @" mutable" atIndex: 7];
		NSLog(@"插入字符串后的可变字符串为: %@", mstr);

		// 插入末尾进行有效拼接
		[mstr insertString: @" and string B" atIndex: [mstr length]];
		NSLog(@"末尾增加字符串: %@", mstr);

		// 直接用appendString
		[mstr appendString: @" and string C"];
		NSLog(@"append: %@", mstr);

		// 根据范围删除子字符串
		[mstr deleteCharactersInRange: NSMakeRange(16, 13)];
		NSLog(@"%@", mstr);

		// 查找然后将其删除
		substr = [mstr rangeOfString: @"string B and "];
		if (substr.location != NSNotFound)
		{
			[mstr deleteCharactersInRange: substr];
			NSLog(@"%@", mstr);
		}

		// 直接设置为可变的字符串
		[mstr setString: @"This is string A"];
		NSLog(@"%@", mstr);

		// 替换一些字符串
		[mstr replaceCharactersInRange: NSMakeRange(8, 8) withString: @"a mutable string"];
		NSLog(@"%@", mstr);

		// 查找和替换
		search = @"This is";
		replace = @"An example of";

		substr = [mstr rangeOfString: search];
		if (substr.location != NSNotFound)
		{
			[mstr replaceCharactersInRange: substr withString: replace];
			NSLog(@"%@", mstr);
		}

		// 查找和替换所有的匹配项
		search = @"a";
		replace = @"X";

		substr = [mstr rangeOfString: search];
		while (substr.location != NSNotFound)
		{
			[mstr replaceCharactersInRange: substr withString: replace];
			substr = [mstr rangeOfString: search];
		}

		NSLog(@"%@", mstr);

		NSLog(@"--------------------------------------");

		NSArray *monthNames = [NSArray arrayWithObjects:
			@"January", @"February", @"March", @"April",
			@"May", @"June", @"July", @"August", @"September",
			@"October", @"November", @"December", nil];

		NSLog(@"Month  Name");
		NSLog(@"=====  ====");
		for (int i = 0; i < 12; ++i)
		{
			NSLog(@" %2i    %@", i + 1, [monthNames objectAtIndex: i]);
		}

		NSLog(@"--------------------------------------");

		NSMutableArray *numbers = [[NSMutableArray alloc] init];
		NSNumber *myNum;
		int i;

		// 创建0~9数字的数组
		for (i = 0; i < 10; ++i)
		{
			myNum = [NSNumber numberWithInteger: i];
			[numbers addObject: myNum];
		}

		// 遍历数组与显示其值
		for (i = 0; i < 10; ++i)
		{
			myNum = [numbers objectAtIndex: i];
			NSLog(@"%@", myNum);
		}

		// 使用带有%@的格式的NSLog显示
		NSLog(@"====== Using a single NSLog");
		NSLog(@"%@", numbers);

		NSLog(@"--------------------------------------");

		NSString *aName = @"Julia Kochan";
		NSString *aEmail = @"jewls337@axlc.com";
		NSString *bName = @"Tony Iannino";
		NSString *bEmail = @"tony.iannino@techfitness.com";
		NSString *cName = @"Stephen Kochan";
		NSString *cEmail = @"steve@classroomM.com";
		NSString *dName = @"Jamie Baker";
		NSString *dEmail = @"jbaker@classroomM.com";

		AddressCard *card1 = [[AddressCard alloc] init];
		AddressCard *card2 = [[AddressCard alloc] init];
		AddressCard *card3 = [[AddressCard alloc] init];
		AddressCard *card4 = [[AddressCard alloc] init];

		// 创建一个新的地址簿
		AddressBook *myBook = [[AddressBook alloc]
			initWithName: @"Linda's Address Book"];

		NSLog(@"Entries in address book after creation: %lu", [myBook entries]);

		// 创建4个地址卡片
		[card1 setName: aName andEmail: aEmail];
		[card2 setName: bName andEmail: bEmail];
		[card3 setName: cName andEmail: cEmail];
		[card4 setName: dName andEmail: dEmail];

		// 将地址卡片添加到地址簿
		[myBook addCard: card1];
		[myBook addCard: card2];
		[myBook addCard: card3];
		[myBook addCard: card4];

		NSLog(@"Entries in address book after adding cards: %lu", [myBook entries]);

		// 列出地址簿的所有条目
		[myBook list];

		AddressCard *myCard;

		// 通过名字查找一个人
		NSLog(@"Stephen Kochan");
		myCard = [myBook lookup: @"stephen kochan"];

		if (myCard != nil)
			[myCard print];
		else
			NSLog(@"Not found");

		// 从电话簿中删除条目
		//[myBook removeCard: myCard];
		[myBook list];

		// 对其进行排序并再次列出它
		[myBook sort];
		[myBook list];

		NSLog(@"--------------------------------------");

		NSMutableDictionary *glossary = [NSMutableDictionary dictionary];

		// 存储三个条目在类别中
		[glossary setObject: @"A class defined so other classes can inherit from it"
					 forKey: @"abstract class"];
		[glossary setObject: @"To implement all the methods defined in a protocol"
					 forKey: @"adopt"];
		[glossary setObject: @"Storing an object for later use"
					 forKey: @"archiving"];

		// 检索并显示它们
		NSLog(@"abstract class: %@", [glossary objectForKey: @"abstract class"]);
		NSLog(@"adopt: %@", [glossary objectForKey: @"adopt"]);
		NSLog(@"archiving: %@", [glossary objectForKey: @"archiving"]);

		NSLog(@"--------------------------------------");

		NSMutableSet *set1 = [NSMutableSet setWithObjects:
			INTOBJ(1), INTOBJ(3), INTOBJ(5), INTOBJ(10), nil];
		NSSet *set2 = [NSSet setWithObjects:
			INTOBJ(-5), INTOBJ(100), INTOBJ(3), INTOBJ(5), nil];
		NSSet *set3 = [NSSet setWithObjects:
			INTOBJ(12), INTOBJ(200), INTOBJ(3), nil];

		NSLog(@"set1: ");
		[set1 print];
		NSLog(@"set2: ");
		[set2 print];

		// 相等性测试
		if ([set1 isEqualToSet: set2] == YES)
		{
			NSLog(@"set1 equals set2");
		}
		else
		{
			NSLog(@"set1 is not equal to set2");
		}

		// 成员测试
		if ([set1 containsObject: INTOBJ(10)] == YES)
		{
			NSLog(@"set1 contains 10");
		}
		else
		{
			NSLog(@"set1 does not contain 10");
		}

		if ([set2 containsObject: INTOBJ(10)] == YES)
		{
			NSLog(@"set2 contains 10");
		}
		else
		{
			NSLog(@"set2 does not contain 10");
		}

		// 在可变集合set1中添加和移除对象
		[set1 addObject: INTOBJ(4)];
		[set1 removeObject: INTOBJ(10)];
		NSLog(@"set1 after adding 4 and removing 10: ");
		[set1 print];

		// 获得两个集合的交集
		[set1 intersectSet: set2];
		NSLog(@"set1 intersect set2: ");
		[set1 print];

		// 两个集合的并集
		[set1 unionSet: set3];
		NSLog(@"set1 union set3: ");
		[set1 print];

		NSLog(@"--------------------------------------");

		NSString *fName = @"testfile";
		NSFileManager *fm;
		NSDictionary *attr;

		// 需要创建文件管理器的实例
		fm = [NSFileManager defaultManager];

		NSLog(@"current directory: %@", [fm currentDirectoryPath]);

		// 将存在的newfile2改名为testfile以便程序正常运行
		if ([fm fileExistsAtPath: @"newfile2"] == YES)
		{
			[fm moveItemAtPath: @"newfile2" toPath: @"testfile" error: NULL];
		}

		// 首先确认测试文件存在
		if ([fm fileExistsAtPath: fName] == NO)
		{
			NSLog(@"File doesn't exist!");
			return 1;
		}

		// 创建一个副本
		if ([fm copyItemAtPath: fName toPath: @"newfile" error: NULL] == NO)
		{
			NSLog(@"File Copy Failed!");
			return 2;
		}

		// 测试两个文件是否一致
		if ([fm contentsEqualAtPath: fName andPath: @"newfile"] == NO)
		{
			NSLog(@"Files are Not Equal!");
			return 3;
		}

		// 重命名副本
		if ([fm moveItemAtPath: @"newfile" toPath: @"newfile2" error: NULL] == NO)
		{
			NSLog(@"File rename Failed");
			return 4;
		}

		// 获取newfile2的大小
		if ((attr = [fm attributesOfItemAtPath: @"newfile2" error: NULL]) == nil)
		{
			NSLog(@"Couldn't get file attributes!");
			return 5;
		}

		NSLog(@"File size is %llu bytes", [[attr objectForKey: NSFileSize] unsignedLongLongValue]);
		NSLog(@"File type is %@", [attr objectForKey: NSFileType]);
		NSLog(@"File creation date is %@", [attr objectForKey: NSFileCreationDate]);


		// 最后删除原始文件
		if ([fm removeItemAtPath: fName error: NULL] == NO)
		{
			NSLog(@"file removal failed");
			return 6;
		}

		// 显示新创建的文件内容
		NSLog(@"%@", [NSString stringWithContentsOfFile: @"newfile2" encoding: NSUTF8StringEncoding error: NULL]);
	}

	return 0;
}
