#include <iostream>
using namespace std;

class Heap
{
	private:
		template <typename T, int N> void sink(T (&a)[N], int size, int i)
		{
			int left    = 2*i - 1;
			int right   = 2*i;
			int largest = i-1;
			
			if(left < size && a[left] > a[largest])   largest = left;
			if(right < size && a[right] > a[largest]) largest = right;
	
			if(largest != i-1)
			{
				T tmp = a[i-1];
				a[i-1] = a[largest];
				a[largest] = tmp;
		
				sink(a, size, largest+1);
			}
		}
		
	public:
		template <typename T, int N> void sort(T (&a)[N])
		{
			for(int i = N/2; i > 0; --i)
				sink(a, N, i);
			
			for(int i = N; i > 1; --i)
			{
				T tmp = a[0];
				a[0] = a[i-1];
				a[i-1] = tmp;
		
				sink(a, i-1, 1);
			}
		}
};

int main()
{
	Heap heap;
	
	// test heap sort
	int a[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	int N = sizeof(a)/sizeof(a[0]);
	
	heap.sort(a);
	for(int i = 0; i < N; ++i)
		cout << a[i] << " ";
	
	return 0;
}