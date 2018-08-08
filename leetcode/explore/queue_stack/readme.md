### Introduction 

- queue-related problem:BFS

- Understand how system stack helps you when you solve problems using DFS and other recursion algorithms;
 
### Queue: FIFO 

#### Implement 

Use a dynamic array and and an index pointing to the head of the queue

Two operations:enqueue/dequeue

[queue_imple_demo.cpp]()

Drawback:straightforward but unefficient

waste space 

#### Circular Queue

A fixed-size

Two pointers

[cir_que_demo.cpp]()

**Be careful**:

在传递数组当参数时候

```cpp
int sum(int array[3]);//指定数组长度

int sum(int array[],count);

//传入一个数组的话相当于只是传入了指针，并不知道分配了多少内存大小
```

#### Built-in Queue

[queue_use.cpp]()

process the elements in order, using a queue might be a good choice

## Queue and BFS

One common application of Breadth-first Search (BFS) is to find the shortest path from the root node to the target node.

Similar to tree's level-order traversal, the nodes closer to the root node will be traversed earlier

If a node X is added to the queue in the kth round, the length of the shortest path between the root node and X is exactly k

You are already in the shortest path the first time you find the target node

#### BFS Template 

Main scenarios:

Do traversal

Find the shortest path 

Typically it happens in a tree or a graph

**It will be important to determine the nodes and the edges before doing BFS in a specific question. Typically, the node will be an actual node or a status while the edge will be an actual edge or a possible transition.**

[BFS_Template_1.java]()

[BFS_Template_2.java]()

Sometimes, it is important to make sure that we never visit a node twice. Otherwise, we might get stuck in an infinite loop. If so, we can add a hash set to the code above to solve this problem

- There are two cases you don't need the hash set used:

You are absolutely sure there is no cycle, for example, in tree traversal;

You do want to add the node to the queue multiple times.

### Exercise

[Number of Islands]()


















