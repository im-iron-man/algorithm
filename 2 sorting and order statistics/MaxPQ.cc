#include <iostream>
using namespace std;

template <typename T, int maxN> class MaxPQ
{
	private:
		T a[maxN];
		int N;
		
		void sink(int i)
		{
			int left    = 2*i - 1;
			int right   = 2*i;
			int largest = i-1;
			
			if(left < N && a[left] > a[largest])   largest = left;
			if(right < N && a[right] > a[largest]) largest = right;
	
			if(largest != i-1)
			{
				T tmp = a[i-1];
				a[i-1] = a[largest];
				a[largest] = tmp;
		
				sink(largest+1);
			}
		}
		
		void swim(int i)
		{
			int parent = i/2 - 1;
	
			if(parent > -1 && a[i-1] > a[parent])
			{	
				int tmp = a[i-1];
				a[i-1] = a[parent];
				a[parent] = tmp;
		
				swim(parent+1);
			}
		}
		
	public:
		MaxPQ()
		{N = 0;}
		
		T max()
		{return a[0];}
		
		T delMax()
		{
			T max = a[0];
			a[0] = a[N-1];
			--N;
			sink(1);
			return max;
		}
		
		void insert(T key)
		{
			++N;
			a[N-1] = key;
			swim(N);
		}
		
		bool isEmpty()
		{return N == 0;}
		
		int size()
		{return N;}		
};

int main()
{
	int a[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	const int N = sizeof(a)/sizeof(a[0]);
	
	MaxPQ<int, N> pq;
	
	// test insert
	for(int i = 0; i < N; ++i)
		pq.insert(a[i]);

	// test delMax
	for(int i = 0; i < N; ++i)
		cout << pq.delMax() << " ";
	
	return 0;
}