#include <iostream>
using namespace std;

class Select
{
	private:
		template <typename T, int N> void sort(T (&a)[N], int p, int r)
		{
			for(int i = p-1; i < r; ++i)
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

		template <typename T, int N> int partition(T (&a)[N], int p, int r)
		{
			T key = a[r-1];
			int q = p-2;
			
			for(int j = p-1; j < r-1; ++j)
			{
				if(a[j] <= key)
				{
					++q;
					
					T tmp = a[q];
					a[q] = a[j];
					a[j] = tmp;
				}
			}
			
			T tmp = a[q+1];
			a[q+1] = a[r-1];
			a[r-1] = tmp;
			
			return q + 2;
		}
		
		template <typename T, int N> T select(T (&a)[N], int p, int r, int index)
		{
			if(p == r) return a[p-1];
			
			int q = partition(a, p, r);
			int tmp = q - p + 1;
			
			if(index == tmp)     return a[q-1];
			else if(index < tmp) return select(a, p, q-1, index);
			else                 return select(a, q+1, r, index-tmp);
		}

		template <typename T, int N> int partitionMD(T (&a)[N], int p, int r, T key)
		{
			for(int i = p-1; i < r; ++i)
			{
				if(a[i] == key)
				{
					T tmp = a[r-1];
					a[r-1] = a[i];
					a[i] = tmp;
					
					break;
				}
			}
			
			return partition(a, p, r);
		}

		template <typename T, int N> T selectMD(T (&a)[N], int p, int r, int index)
		{
			if(p == r) return a[p-1];
			
			int n = r - p + 1; 
			int size = n/5 + (n%5 ? 1 : 0);
			T b[N];
			
			for(int i = 1; i <= size; ++i)
			{
				int left  = (i - 1)*5 + 1;
				int right = left + (left + 4 > n ? n%5 - 1 : 4); 
				sort(a, left, right);
				b[i-1] = a[(left + right)/2 - 1];
			}
			
			T key = selectMD(b, 1, size, (1 + size)/2);
			int q = partitionMD(a, p, r, key);
			int tmp = q - p + 1;
			
			if(index == tmp)     return a[q-1];
			else if(index < tmp) return selectMD(a, p, q-1, index);
			else                 return selectMD(a, q+1, r, index-tmp);	
		}
		
	public:
		template <typename T, int N> T min(T (&a)[N])
		{
			T min = a[0];
			for(int i = 1; i < N; ++i)
				if(min > a[i])
					min = a[i];
			return min;
		}
		
		template <typename T, int N> T max(T (&a)[N])
		{
			T max = a[0];
			for(int i = 1; i < N; ++i)
				if(max < a[i])
					max = a[i];
			return max;
		}
		
		template <typename T, int N> T select(T (&a)[N], int index)
		{return select(a, 1, N, index);}
		
		template <typename T, int N> T selectMD(T (&a)[N], int index)
		{return selectMD(a, 1, N, index);}
};

int main()
{
	Select select;
	
	int a[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	cout << select.min(a) << endl;
	
	int b[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	cout << select.max(b) << endl;
	
	int c[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	int N = sizeof(c)/sizeof(c[0]);
	
	for(int i = 1; i <= N; ++i)
		cout << select.select(c, i) << " ";
	cout << endl;
	
	int d[] = {0, 5, 6, 4, 8, 9, 74, 65, 123, 94};
	N = sizeof(d)/sizeof(d[0]);
	
	for(int i = 1; i <= N; ++i)
		cout << select.selectMD(d, i) << " ";
	
	return 0;
}