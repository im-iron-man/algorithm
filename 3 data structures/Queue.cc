#include <iostream>
using namespace std;

template <typename Item> class Queue
{
	struct Node
	{
		Item item;
		Node *next;
	};
	
	private:
		int N;
		Node *first;
		Node *last;
		
	public:
		Queue()
		{
			N = 0;
			first = NULL;
			last = NULL;
		}
		
		void enqueue(Item item)
		{
			Node *oldlast = last;
			last = new Node();
			last->item = item;
			last->next = NULL;
			if(isEmpty()) first = last;
			else          oldlast->next = last;
			++N;
		}
		
		Item dequeue()
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
	Queue<int> queue;
	
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	
	cout << queue.isEmpty() << " ";
	cout << queue.size()    << endl;
	
	cout << queue.dequeue() << " ";
	cout << queue.dequeue() << " ";
	cout << queue.dequeue() << endl;
	
	return 0;
}