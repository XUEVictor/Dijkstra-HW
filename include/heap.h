/*
  Heap using an array
  Enables us to represent binary trees without pointers:
  - Left child sits at 2n
  - Right child sits at 2n + 1
  - Parent sits at floor(n/2)
*/

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <string>



class Heap {
  struct Node
  {
    int ele;
    int key;
    Node():ele(0),key(0){}
    Node(int node, int key):ele(node), key(key){};
  };
  std::vector<Node> queue_;
  unsigned    int  size_;

  // Called by insert()
  // If the parent's value is greater than current
  //  the current item bubbles up till we reach root
  void bubbleUp  (int idx);
  // Called by delete() 
  // If the current is greater than children
  //  the current item bubbles down till no more children
  void bubbleDown(int idx);
  // Used by bubbleDown()
  //  Get the index of the min value 
  //  between 3 given indices to the heap array.
  int getMinIdx  (int aIdx, int bIdx, int cIdx);

public:
  Heap();
  ~Heap() {};
  bool              isEmpty   () const;
  int               size      () const;
  void              clear     ();
  int               getItem   (unsigned int idx) const;
  int               parent    (unsigned int idx) const;
  int               child     (unsigned int idx) const;
  int               find      (unsigned int idx, int val) const;
  void              insert    (int val);
  void              remove    (int val);
  void              makeHeap  (int array[], int size);
  void              makeHeap  (std::vector<int> input);
  void              chgkey    (int node,int N_key);
  int               GetIdx    (int Node);
  void              MinHeapify(int node, int length);
  int               extractMin(); //Removes and returns min value
  void              swap      (struct Node &p1, struct Node &p2);
  std::vector<int>  heapSort  (); //O(n log n)
  std::string       toString  () const;
};

#endif