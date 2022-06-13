#include <iostream>
using namespace std;

template <class T>

class Accumulate
{
public:
	virtual bool operator () (T x) = 0;
};
	

template <class T>
class Positive : public Accumulate<T>
{
 public:
	bool operator () (T x)
	{
		return x > 0;
	}
};

template<class T>
class Even : public Accumulate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 == 0;
	}
};

template <class T> T accumulate(T* begin, T* end)
{
	T result = 0;
	for (T* from = begin; from < end; from++)
	{
		result += *from;
	}
	return result;
}

template <class T> T accumulate_if( T* begin, T* end, Accumulate<T>& predicate)
{
	T result = 0;
	for (T* from = begin; from < end; from++)
	{
		if (predicate(*from))
		{
			result += *from;
		}
	}
	return result;
}

int main()
{
	int a[] = { 0, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int r = accumulate(&a[0], &a[10]);
	cout << "Accumulate " << endl;
	cout << r << endl;

	Accumulate <int>* p = new Positive<int>;
	r = accumulate_if(&a[0], &a[10], *p);
	cout << "Accumulate_if (Positive)" << endl;
	cout << r << endl;
	

	p= new Even<int>;
	r = accumulate_if(&a[0], &a[10], *p);
	cout << "Accumulate_if (Even)" << endl;
	cout << r << endl;

	return 0;
	

}