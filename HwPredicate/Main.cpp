#include <iostream>
#include <vector>
using namespace std;

class Func 
{
	int a;
	int b;
public:
	Func(int x, int y) 
	{
		a = x;
		b = y;
	}

	bool operator()(int el) 
	{
		return ((el >= a) && (el <= b));
	}
};


int main() 
{
	vector<char> array{ 'S', 'a', 'b', 'Q', 'o', 'L', 'y', 'M', 'N' };
	
	ostream_iterator<char> out(cout, "\t");

	copy(array.begin(), array.end(), out);
	cout << "\n";
	auto it = remove_if(array.begin(), array.end(), Func(97, 122));
	array.erase(it, array.end());

	copy(array.begin(), array.end(), out);

	return 0;
}