#include "pch.h"
#include <iostream>
#define MAX(a, b) (a > b) ? a : b

template<typename T>
T my_max(T& a, T& b) {
	return ((a > b) ? a : b);
}


//inline int my_max(int a, int b)
//{
//	return (a > b) ? a : b;
//}

int main()
{
	int a = MAX(3, 5);
	int b = 2 * MAX(3, 5);
	int c = MAX(3, 5) + 1;

	/*std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << c << "\n";*/

	int i = 3;

	int f = 2;
	int g = 7;
	double h = 4.2;
	double j = 6.2;

	const char* chr = "abc";
	const char* chr2 = "dbe";

	std::string str( "asdfkjdfgkldfg" );
	std::string str2( "phpphphphphphph" );

	//int d = MAX(++i, 2);

	//std::cout << d << "\n";

	//std::cout << my_max(++i, 2) << "\n";

	std::cout << my_max(f, g);
	
	std::cout << my_max(j, h) <<"\n";
	std::cout << my_max(chr, chr2) << "\n";
	std::cout << my_max(str, str2) << "\n";

}
