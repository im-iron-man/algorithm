# 3 data structures

## summary

## api

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