#include <iostream>
using namespace std;

class Quick
{
	private:
		template <typename T, int N> int partition(T (&a)[N], int p, int r)
		{
			T key = a[r-1];
			int index = p-2;
			
			for(int j = p-1; j < r-1; ++j)
			{
				if(a[j] <= key)
				{
					++index;
					
					T tmp = a[index];
					a[index] = a[j];
					a[j] = tmp;
				}
			}
			
			T tmp = a[index+1];
			a[index+1] = a[r-1];
			a[r-1] = tmp;
			
			return index + 2;
		}
		
		template <typename T, int N> void sort(T (&a)[N], int p, int r)
		{
			if(p < r)
			{
				int index = partition(a, p, r);
				sort(a, p, index-1);
				sort(a, index+1, r);
			}
		}
		
	public:
		template <typename T, int N> void sort(T (&a)[N])
		{sort(a, 1, N);}
};

int main()
{
	Quick quick;
	
	// test quick sort
	int a[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	int N = sizeof(a)/sizeof(a[0]);
	
	quick.sort(a);
	for(int i = 0; i < N; ++i)
		cout << a[i] << " ";
	
	return 0;
}