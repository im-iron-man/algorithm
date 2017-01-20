# 3 data structures

## summary

### stack

|Stack     |push|pop|
|----------|----|---|
|worst case|1   |1  |

### queue

|Queue     |enqueue|dequeue|
|----------|-------|-------|
|worst case|1      |1      |

### sequential search symbol table

|SequentialSearchST|put|get|del|
|------------------|---|---|---|
|worst case        |n  |n  |n  |
|average case      |n  |n  |n  |

### binary search tree

|BST         |put  |get  |del  |
|------------|-----|-----|-----|
|worst case  |n    |n    |n    |
|average case|lg(n)|lg(n)|lg(n)|

### red-black tree

|RBT         |put  |get  |del  |
|------------|-----|-----|-----|
|worst case  |lg(n)|lg(n)|lg(n)|
|average case|lg(n)|lg(n)|lg(n)|

## API

### Stack

```
template <typename Item> class Stack
-------------------------------------------------------------------------
  Stack()
  void push(Item item)
  Item pop()
  bool isEmpty()     
  int size()
```

### Queue

```
template <typename Item> class Queue
-------------------------------------------------------------------------
  Queue()
  void enqueue(Item item)
  Item dequeue()
  bool isEmpty()     
  int size()
```

### SequentialSearchST

```
template <typename Key, typename Value> class SequentialSearchST
-------------------------------------------------------------------------
  SequentialSearchST()
  void put(Key key, Value val)
  Value get(Key key)
  void del(Key key)
  bool isEmpty()     
  int size()
```

### BST

```
template <typename Key, typename Value> class BST
-------------------------------------------------------------------------
  BST()
  void put(Key key, Value val)
  Value get(Key key)
  void del(Key key)
  bool isEmpty()     
  int size()
```

### RBT

```
template <typename Key, typename Value> class RBT
-------------------------------------------------------------------------
  RBT()
  void put(Key key, Value val)
  Value get(Key key)
  void del(Key key)
  bool isEmpty()     
  int size()
```

## TODO

- read section 3.4 in [Algorithm](https://book.douban.com/subject/10432347)
  - write code for chapter 11
  - analyse the run time for hash table
- read section 3.2 in [Algorithm](https://book.douban.com/subject/10432347)
  - add more features
  - use recursive method to implement binary search tree
- read section 3.3 in [Algorithm](https://book.douban.com/subject/10432347)
  - learn 2-3 search tree
  - learn 1-1 correspondence between red-black tree and 2-3 search tree
- add comments for code
- visualize the process of program