#include <iostream>
using namespace std;

class Sort
{
	public:
		template <typename T, int N> void select(T (&a)[N])
		{
			for(int i = 0; i < N-1; ++i)
			{
				int index = i;
		
				for(int j = i+1; j < N; ++j)
					if(a[index] > a[j])
						index = j;
		
				T tmp = a[index];
				a[index] = a[i];
				a[i] = tmp;
			}
		}
	
		template <typename T, int N> void bubble(T (&a)[N])
		{	
			for(int i = N-1; i > 1; --i)
			{
				for(int j = 0; j < i; ++j)
				{
					if(a[j] > a[j+1])
					{
						T tmp = a[j];
						a[j] = a[j+1];
						a[j+1] = tmp;
					}
				}
			}
		}
	
		template <typename T, int N> void insert(T (&a)[N])
		{
			for(int i = 1; i < N; ++i)
			{
				T key = a[i];
				int j = i-1;
				
				while(j >= 0 && a[j] > key)
				{
					a[j+1] = a[j];
					--j;
				}
		
				a[j+1] = key;
			}
		}
};

int main()
{
	Sort sort;
	
	// test selection sort
	int a[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	int N = sizeof(a)/sizeof(a[0]);
	
	sort.select(a);
	for(int i = 0; i < N; ++i)
		cout << a[i] << " ";
	cout << endl;
	
	// test bubble sort
	int b[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	N = sizeof(b)/sizeof(b[0]);
	
	sort.bubble(b);
	for(int i = 0; i < N; ++i)
		cout << b[i] << " ";
	cout << endl;
	
	// test insert sort
	int c[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	N = sizeof(c)/sizeof(c[0]);
	
	sort.insert(c);
	for(int i = 0; i < N; ++i)
		cout << c[i] << " ";
	
	return 0;
}