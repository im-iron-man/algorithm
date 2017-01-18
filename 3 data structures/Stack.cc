#include <iostream>
using namespace std;

template <typename Item> class Stack
{
	struct Node
	{
		Item item;
		Node *next;
	};
	
	private:
		int N;
		Node *first;
	
	public:
		Stack()
		{
			N = 0;
			first = NULL;
		}
		
		void push(Item item)
		{
			Node *newfirst = new Node();
			newfirst->item = item;
			newfirst->next = first;
			first = newfirst;
			++N;
		}
		
		Item pop()
		{
			Item item = first->item;
			first = first->next;
			--N;
			return item;
		}
		
		bool isEmpty()
		{return N==0;}
		
		int size()
		{return N;}	
};

int main()
{
	Stack<int> stack;
	
	stack.push(1);
	stack.push(2);
	stack.push(3);
	
	cout << stack.isEmpty() << " ";
	cout << stack.size()    << endl;
	
	cout << stack.pop() << " ";
	cout << stack.pop() << " ";
	cout << stack.pop() << endl;
	
	return 0;
}