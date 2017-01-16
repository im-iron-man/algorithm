#include <iostream>
using namespace std;

class Merge
{
	private:
		template <typename T, int N> void merge(T (&a)[N], int p, int q, int r)
		{
			int N1 = q - p + 1;
			int N2 = r - q;
			T a1[N1], a2[N2];

			for(int i = 0; i < N1; ++i)
				a1[i] = a[p + i - 1];
			for(int i = 0; i < N2; ++i)
				a2[i] = a[q + i];
	
			int index1 = 0;
			int index2 = 0;
			
			for(int i = p-1; i < r; ++i)
			{
				if(index1 > N1-1)
				{
					for(int j = index2; j < N2; ++j)
						a[i + j - index2] = a2[j];
					break;
				}
		
				if(index2 > N2-1)
				{
					for(int j = index1; j < N1; ++j)
						a[i + j - index1] = a1[j];
					break;
				}
		
				if(a1[index1] <= a2[index2])
				{
					a[i] = a1[index1];
					++index1;
				}
				else
				{
					a[i] = a2[index2];
					++index2;
				}
			}
		}
		
		template <typename T, int N> void sort(T (&a)[N], int p, int r)
		{
			if(p < r)
			{
				int q = (p + r)/2;
				sort(a, p, q);
				sort(a, q + 1, r);
				merge(a, p, q, r);
			}
		}
	
	public:
		template <typename T, int N> void sort(T (&a)[N])
		{sort(a, 1, N);}
		
		template <typename T, int N> void BUsort(T (&a)[N])
		{
			for(int i = 1; i < N; i *= 2)
			{
				for(int j = 0; j < N-i; j += 2*i)
				{
					int min = 2*i + j - 1;
					if(N-1 < min)
						min = N-1;
					merge(a, j+1, i+j, min+1);
				}
			}
		}
};

int main()
{
	Merge merge;
	
	// test merge sort
	int a[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	int N = sizeof(a)/sizeof(a[0]);
	
	merge.sort(a);
	for(int i = 0; i < N; ++i)
		cout << a[i] << " ";
	cout << endl;
	
	// test buttom-up merge sort
	int b[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	N = sizeof(b)/sizeof(b[0]);
	
	merge.BUsort(b);
	for(int i = 0; i < N; ++i)
		cout << b[i] << " ";
	
	return 0;
}