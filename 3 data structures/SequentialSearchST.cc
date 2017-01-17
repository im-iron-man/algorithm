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
	st.put(6, "A");
	st.put(4, "B");
	st.put(7, "C");
	st.put(2, "D");
	st.put(5, "E");
	st.put(8, "F");
	
	st.del(6);
	st.del(4);
	
	cout << st.get(7) << endl;
	cout << st.get(2) << endl;
	cout << st.get(5) << endl;
	cout << st.get(8) << endl;
	
	cout << st.isEmpty() << endl;
	cout << st.size() << endl;
	
	return 0;
}