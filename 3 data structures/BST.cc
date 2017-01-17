#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

template <typename Key, typename Value> class BST
{
	struct Node
	{
		Key key;
		Value val;
		Node *parent;
		Node *left;
		Node *right;
	};
	
	private:
		int N;
		Node *root;
		
		Node *get(Node *x, Key key)
		{
			while(x != NULL && key != x->key)
			{
				if(key < x->key) x = x->left;
				else             x = x->right;
			}
			
			return x;
		}
		
		Node *min(Node *x)
		{	
			while(x != NULL && x->left != NULL)
				x = x->left;
			
			return x;
		}
		
		void transplant(Node *x, Node *y)
		{
			if(x->parent == NULL)         root             = y;
			else if(x == x->parent->left) x->parent->left  = y;
			else                          x->parent->right = y;
			
			if(y != NULL)                 y->parent = x->parent;
		}
		
	public:
		BST()
		{
			N = 0;
			root = NULL;
		}
		
		void put(Key key, Value val)
		{
			Node *x = NULL;
			Node *y  = root;
			
			while(y != NULL)
			{
				x = y;
				if(key < y->key)      y = y->left;
				else if(key > y->key) y = y->right;
				else                  break;
			}
			
			Node *z   = new Node();
			z->key    = key;
			z->val    = val;
			z->parent = x;
			z->left   = NULL;
			z->right  = NULL;
			
			if(x == NULL)         root     = z;
			else if(key < x->key) x->left  = z;
			else if(key > x->key) x->right = z;
			else                  x->val   = val;
			
			++N;
		}
		
		Value get(Key key)
		{
			Node  *x = get(root, key);
			
			if(x == NULL)
			{
				cout << "There is no key " << key << "." << endl;
				exit(-1);
			}
			
			return x->val;
		}
		
		void del(Key key)
		{
			Node *x = get(root, key);
			
			if(x == NULL)
			{
				cout << "There is no key " << key << "." << endl;
				exit(-1);
			}
			
			if(x->left == NULL)       transplant(x, x->right);
			else if(x->right == NULL) transplant(x, x->left);
			else
			{
				Node *y = min(x->right);
				
				if(y->parent != x)
				{
					transplant(y,y->right);
					y->right = x->right;
					y->right->parent = y;
				}
				
				transplant(x, y);
				y->left = x->left;
				y->left->parent = y;
			}
			
			--N;
		}
		
		bool isEmpty()
		{return N==0;}
		
		int size()
		{return N;}
};

int main()
{
	BST<int, string> bst;
	
	bst.put(6, "A");
	bst.put(4, "B");
	bst.put(7, "C");
	bst.put(2, "D");
	bst.put(5, "E");
	bst.put(8, "F");
	
	bst.del(6);
	bst.del(4);
	
	cout << bst.get(7) << endl;
	cout << bst.get(2) << endl;
	cout << bst.get(5) << endl;
	cout << bst.get(8) << endl;
	
	cout << bst.isEmpty() << endl;
	cout << bst.size() << endl;

	return 0;
}