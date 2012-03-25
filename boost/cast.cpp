#include <iostream>
#include <boost/lexical_cast.hpp>

int main(int argc, char *argv[])
{
	using std::cout;
	using std::endl;
	unsigned int num;

	num = 0xffffffff;
	try
	{
		num = boost::lexical_cast<int>("4294967295");
	}
	catch (boost::bad_lexical_cast &e)
	{
		cout << e.what() << endl;
	}
	cout << num << endl;

	return 0;
}
