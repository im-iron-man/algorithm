# 2 sorting and order statistics

## summary

### sort

|algorithm|best case|worst case|average case|extra space|stable|in place|
|---------|---------|----------|------------|-----------|------|--------|
|select   |n^2      |n^2       |n^2         |1          |no    |yes     |
|bubble   |n        |n^2       |n^2         |1          |yes   |yes     |
|insert   |n        |n^2       |n^2         |1          |yes   |yes     |
|merge    |nlg(n)   |nlg(n)    |nlg(n)      |n          |yes   |no      |
|mergeBU  |nlg(n)   |nlg(n)    |nlg(n)      |n          |yes   |no      |
|heap     |nlg(n)   |nlg(n)    |nlg(n)      |1          |no    |yes     |
|quick    |nlg(n)   |n^2       |nlg(n)      |lg(n)      |no    |yes     |

### select

|algorithm|worst case|average case|
|---------|----------|------------|
|min      |n         |n           |
|max      |n         |n           |
|select   |n^2       |n           |
|selectMD |n         |n           |

## API

### Sort

```
class Sort
-------------------------------------------------------------------------
  template <typename T, int N> void select(T (&a)[N])
  template <typename T, int N> void bubble(T (&a)[N])
  template <typename T, int N> void insert(T (&a)[N])
  template <typename T, int N> void merge(T (&a)[N])      
  template <typename T, int N> void mergeBU(T (&a)[N])
  template <typename T, int N> void heap(T (&a)[N])
  template <typename T, int N> void quick(T (&a)[N])
```

### Merge

```
class Merge
--------------------------------------------------------------------------
  template <typename T, int N> void sort(T (&a)[N])      
  template <typename T, int N> void BUsort(T (&a)[N])
```

### Heap

```
class Heap
--------------------------------------------------------------------------       
  template <typename T, int N> void sort(T (&a)[N])
```

### Quick

```
class Quick
--------------------------------------------------------------------------       
  template <typename T, int N> void sort(T (&a)[N])
```

### MaxPQ

```
template <typename T, int maxN> class MaxPQ
--------------------------------------------------------------------------
  MaxPQ()
  T max()
  T delMax()
  void insert(T key)
  bool isEmpty()
  int size()
```

### Select

```
class Select
--------------------------------------------------------------------------
  template <typename T, int N> T min(T (&a)[N])        
  template <typename T, int N> T max(T (&a)[N])
  template <typename T, int N> T select(T (&a)[N], int index)
  template <typename T, int N> T selectMD(T (&a)[N], int index)
```

## TODO

- write code for chapter 8
- add comments for code
- visualize the process of program