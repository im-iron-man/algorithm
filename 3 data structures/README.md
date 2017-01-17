# 3 data structures

## summary

### binary search tree

|BST         |put  |get  |del  |
|------------|-----|-----|-----|
|worst case  |n    |n    |n    |
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

## TODO