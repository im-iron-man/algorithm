#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

template <typename Key, typename Value> class RBT
{
	struct Node
	{
		Key key;
		Value val;
		bool color;
		Node *parent;
		Node *left;
		Node *right;
	};
	
	private:
		int N;
		Node *root;
		
		void rotateLeft(Node *x)
		{
			Node *y = x->right;
			
			x->right = y->left;
			if(y->left != NULL)
				y->left->parent = x;
			
			y->parent = x->parent;
			if(x->parent == NULL)         root             = y;
			else if(x == x->parent->left) x->parent->left  = y;
			else                          x->parent->right = y;
			
			y->left   = x;
			x->parent = y;
		}
		
		void rotateRight(Node *x)
		{
			Node *y = x->left;
			
			x->left = y->right;
			if(y->right != NULL)
				y->right->parent = x;
			
			y->parent = x->parent;
			if(x->parent == NULL)         root             = y;
			else if(x == x->parent->left) x->parent->left  = y;
			else                          x->parent->right = y;
			
			y->right  = x;
			x->parent = y;
		}
		
		Node *get(Node *x, Key key)
		{
			while(x != NULL && key != x->key)
			{
				if(key < x->key) x = x->left;
				else             x = x->right;
			}
			
			return x;
		}
		
		void putFix(Node *x)
		{
			while(x->parent != NULL && x->parent->color == 0)
			{
				if(x->parent == x->parent->parent->left)
				{
					Node *y = x->parent->parent->right;
					
					if(y->color == 0)
					{
						x->parent->color = 1;
						y->color = 1;
						x->parent->parent->color = 0;
						x = x->parent->parent;
					}
					else 
					{
						if(x == x->parent->right)
						{
							x = x->parent;
							rotateLeft(x);
						}
						
						x->parent->color = 1;
						x->parent->parent->color = 0;
						rotateRight(x->parent->parent);
					}
				}
				else
				{
					Node *y = x->parent->parent->left;
					
					if(y->color == 0)
					{
						x->parent->color = 1;
						y->color = 1;
						x->parent->parent->color = 0;
						x = x->parent->parent;
					}
					else
					{
						if(x == x->parent->left)
						{
							x = x->parent;
							rotateRight(x);
						}
						
						x->parent->color = 1;
						x->parent->parent->color = 0;
						rotateLeft(x->parent->parent);
					}
				}
			}
			
			root->color = 1;
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

		void delFix(Node *x)
		{
			while(x != NULL && x != root && x->color == 1)
			{
				if(x == x->parent->left)
				{
					Node *y = x->parent->right;
					
					if(y->color == 0)
					{
						y->color = 1;
						x->parent->color = 0;
						rotateLeft(x->parent);
						y = x->parent->right;
					}
					
					if(y->left->color == 1 && y->right->color == 1)
					{
						y->color = 0;
						x = x->parent;
					}
					else
					{
						if(y->right->color == 1)
						{
							y->left->color = 1;
							y->color = 0;
							rotateRight(y);
							y = x->parent->right;
						}
						
						y->color = x->parent->color;
						x->parent->color = 1;
						y->right->color = 1;
						rotateLeft(x->parent);
						x = root;
					}
				}
				else
				{
					Node *y = x->parent->left;
					
					if(y->color == 0)
					{
						y->color = 1;
						x->parent->color = 0;
						rotateRight(x->parent);
						y = x->parent->left;
					}
					
					if(y->left->color == 1 && y->right->color == 1)
					{
						y->color = 0;
						x = x->parent;
					}
					else
					{
						if(y->left->color == 1)
						{
							y->right->color = 1;
							y->color = 0;
							rotateLeft(y);
							y = x->parent->left;
						}
						
						y->color = x->parent->color;
						x->parent->color = 1;
						y->left->color = 1;
						rotateRight(x->parent);
						x = root;
					}
				}
			}
			
			if(x != NULL) 
				x->color = 1;
		}
		
	public:
		RBT()
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
			z->color  = 0;
			z->parent = x;
			z->left   = NULL;
			z->right  = NULL;
			
			if(x == NULL)         root     = z;
			else if(key < x->key) x->left  = z;
			else if(key > x->key) x->right = z;
			else                  
			{
				x->val   = val;
				return;
			}
			
			putFix(z);
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
			
			Node *y = x;
			bool color = y->color;
			Node *z = new Node();
			
			if(x->left == NULL)       
			{
				z = x->right;
				transplant(x, x->right);
			}
			else if(x->right == NULL) 
			{
				z = x->left;
				transplant(x, x->left);
			}
			else
			{
				y = min(x->right);
				color = y->color;
				z = y->right;
				
				if(z != NULL && y->parent == x) z->parent = y;
				else if(y->parent != x)
				{
					transplant(y,y->right);
					y->right = x->right;
					y->right->parent = y;
				}
				
				transplant(x, y);
				y->left = x->left;
				y->left->parent = y;

				if(z != NULL) y->color = z->color;
				else          y->color = 1;
			}
			
			
			if(color == 1)
				delFix(z);
			
			--N;
		}
		
		bool isEmpty()
		{return N==0;}
		
		int size()
		{return N;}
};

int main()
{
	RBT<int, string> rbt;
	
	rbt.put(6, "A");
	rbt.put(4, "B");
	rbt.put(7, "C");
	rbt.put(2, "D");
	rbt.put(5, "E");
	rbt.put(8, "F");
	
	rbt.del(6);
	rbt.del(4);
	
	cout << rbt.get(7) << " ";
	cout << rbt.get(2) << " ";
	cout << rbt.get(5) << " ";
	cout << rbt.get(8) << endl;
	
	cout << rbt.isEmpty() << " ";
	cout << rbt.size()    << endl;

	return 0;
}