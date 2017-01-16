#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

template <typename Key, typename Value> class SequentialSearchST
{
	struct Node
	{
		Key key;
		Value val;
		Node *prev;
		Node *next;
	};
	
	private:
		int N;
		Node *first;
		
	public:
		SequentialSearchST()
		{
			N = 0;
			first = NULL;
		}
		
		void put(Key key, Value val)
		{
			for(Node *x = first; x != NULL; x = x->next)
			{
				if(key == x->key)
				{
					x->val = val;
					return;
				}
			}
			
			Node *newfirst = new Node();
			newfirst->key = key;
			newfirst->val = val;
			newfirst->prev = NULL;
			newfirst->next = first;
			if(first != NULL) first->prev = newfirst;
			first = newfirst;
			++N;
		}
		
		Value get(Key key)
		{
			for(Node *x = first; x != NULL; x = x->next)
				if(key == x->key)
					return x->val;
			
			cout << "There is no key " << key << "." << endl;
			exit(-1);
		}
		
		void del(Key key)
		{
			for(Node *x = first; x != NULL; x = x->next)
			{	
				if(key == x->key)
				{
					if(x->prev != NULL) x->prev->next = x->next;
					if(x->next != NULL) x->next->prev = x->prev;
					--N;
					return;
				}
			}
			
			cout << "There is no key " << key << "." << endl;
			exit(-1);
		}
		
		bool isEmpty()
		{return N==0;}
		
		int size()
		{return N;}
};

int main()
{
	SequentialSearchST<int, string> st;
	st.put(1, "A");
	st.put(2, "B");
	st.put(3, "C");
	st.del(2);
	// st.del(4);
	
	cout << st.get(1) << endl;
	cout << st.get(3) << endl;
	// cout << st.get(2) << endl;
	
	return 0;
}