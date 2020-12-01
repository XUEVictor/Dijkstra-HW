#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <sstream> //stringstream

#include "heap.h"

using namespace std;
typedef vector<int>::iterator vecIter;
typedef vector<int>::const_iterator vecCiter;

// Add a dud first elem
Heap::Heap() : size_(0) {}

bool Heap::isEmpty() const {
  return (queue_.size()<1);
}

int Heap::size() const {
  return size_;
}

void Heap::clear() {
  queue_.clear();
  queue_.push_back(Node(0,0)); //first item is a dud
}

int Heap::getItem(unsigned int idx) const {
  return queue_[idx].key;
}

int Heap::parent(unsigned int idx) const {
  if (size_ <= 1) return -1; //empty or root has no parent
  return ((int) idx / 2); //floor (idx/2)
}

int Heap::child(unsigned int idx) const {
  //cout<<"idx : "<<idx<<"    "<<"Size : "<<size_<<endl;
  if (size_ <= 1 || 2 * idx > size_ ) return -1; //empty or root has no child
  return (2 * idx);
}

int Heap::find(unsigned int idx, int val) const { //O(log n)
  //cout<<"idx : "<<idx<<"   size : "<<size_<<"   val : "<<val<<"  Key : "<<queue_[idx].key<<endl;
  if (idx > size_) return -1; //base case: idx out of bounds
  if (val < queue_[idx].key) return -1;   //base case: val not in min-heap
  if (queue_[idx].key == val) return idx; //Found the val, return its index

  int childIdx = child(idx), i = -1;

  if (childIdx != -1) { //find in left and right children
    i = max(find(childIdx, val), find(childIdx + 1, val));
  }

  return i;
} 
void Heap::swap(struct Node &p1, struct Node &p2){

    struct Node temp = p1;
    p1 = p2;
    p2 = temp;
}
void Heap::bubbleUp(int idx) { //O(log n)
  int parentIdx = parent(idx);
  if (parentIdx == -1) return; //base case: root of heap

  if (queue_[parentIdx].key > queue_[idx].key) {
    swap(queue_[parentIdx], queue_[idx]);
    bubbleUp(parentIdx);
  } 
}

void Heap::insert(int val) {
  queue_.push_back(Node(size_,val));
  size_++;
  bubbleUp(size_);
}

// @Precondition: index aIdx and bIdx exist in the array
int Heap::getMinIdx(int aIdx, int bIdx, int cIdx) {
  bool isLeftSmaller = (queue_[aIdx].key < queue_[bIdx].key);
  /*
  if (cIdx > (int) size_) { //the last right child doesnt exist
    return isLeftSmaller ? aIdx : bIdx;
  } else if (isLeftSmaller) {
    return (queue_[aIdx].key < queue_[cIdx].key) ? aIdx : cIdx;
  } else {
    return (queue_[bIdx].key < queue_[cIdx].key) ? bIdx : cIdx;
  }
  */
  int smallest;
  if (bIdx <= size_ && queue_[bIdx].key < queue_[aIdx].key)
    smallest = bIdx;
  else
    smallest = aIdx;
  if (cIdx <= size_ && queue_[cIdx].key < queue_[smallest].key)
    smallest = cIdx;

  return smallest;
}

void Heap::bubbleDown(int idx) { //O(log n)
  int childIdx = child(idx);
  if (childIdx == -1) return; //base case: no children left
  int minIdx = getMinIdx(idx, childIdx, childIdx + 1);
  //cout<<"minIdx : "<<minIdx<<endl;
  if (minIdx != idx) {
    swap(queue_[minIdx], queue_[idx]);
    bubbleDown(minIdx);
  }
}

void Heap::remove(int val) { //O(2 * log n)
  int idx = find(1, val);
  if (idx == -1) return;

  queue_[idx] = queue_[size_--]; // swap current with last item
  queue_.resize(size_ + 1); //idx 0 is a dud item
  bubbleDown(idx);
  bubbleUp(idx);
}

int Heap::extractMin() { //Special case of remove: O(2 * log n)
  if (isEmpty()) throw "Empty Heap!";
  /*
    cout<<endl;
    cout<<"Start"<<endl;
    for(int i = 0;i<queue_.size();i++){
      cout<<queue_[i].ele<<"    "<<queue_[i].key<<endl;
    }
    cout<<endl;
  

*/
  int min = queue_[1].ele;

  //std::cout<<queue_[queue_.size()-1].ele<<"        "<<queue_[queue_.size()-1].key<<endl;

  //cout<<queue_[queue_.size()-1].ele<<"     "<<queue_[queue_.size()-1].key<<endl;
  queue_[1] = queue_[queue_.size()-1];            // 把最後一個element放到第一個位置,
  queue_.erase(queue_.begin()+queue_.size()-1);   // 再刪除最後一個element
  
  /*
  cout<<endl;
  cout<<"End"<<endl;
  for(int i = 0;i<size_ + 1;i++){
    cout<<queue_[i].ele<<"    "<<queue_[i].key<<endl;
  }
  cout<<endl;
  */

  //MinHeapify(1,(int)queue_.size()); //O(log n)


  bubbleDown(1);
  /*
  cout<<endl;
  for(int i = 0;i<size_ + 1;i++){
    cout<<queue_[i].ele<<"    "<<queue_[i].key<<endl;
  }
  cout<<endl;
  */

  return min;
}

vector<int> Heap::heapSort() { //O(n log n)
  vector<int> sortedItems;
  sortedItems.reserve(size_);
  while(!isEmpty()) {
    sortedItems.push_back(extractMin());
  }

  return sortedItems;
}

// Create the heap given an unsorted vector
void Heap::makeHeap(std::vector<int> input) { //O(n log n)?

  size_ = input.size();
  queue_.resize(size_ + 1);

  for (int i = 0; i < size_; i++) {     
    queue_[i + 1].ele = i;                 // 把array[]的idx視為element
    queue_[i + 1].key = input[i];              // 把array[]的數值視為key
  }
  for(int i = 0;i<queue_.size();i++){
    //std::cout<<queue_[i].ele<<"    "<<queue_[i].key<<std::endl;
  }
  for (int i = (int)queue_.size()/2; i >= 1 ; i--) {
    //MinHeapify(i,(int)queue_.size()-1); //O(log n)
    bubbleDown(i);
  }
  /*
  for(int i = 0;i<queue_.size();i++){
    std::cout<<queue_[i].ele<<"    "<<queue_[i].key<<std::endl;
  }
  */
}

void Heap::MinHeapify(int node, int length){

    /*
    cout<<endl;
    cout<<"Start"<<endl;
    for(int i = 0;i<size_ + 1;i++){
      cout<<queue_[i].ele<<"    "<<queue_[i].key<<endl;
    }
    cout<<endl;
    */
    int left = 2*node,          // 取得left child
        right = 2*node + 1,     // 取得right child
        smallest;               // smallest用來記錄包含root與child, 三者之中Key最小的node

    if (left <= length && queue_[left].key < queue_[node].key)
        smallest = left;
    else
        smallest = node;

    if (right <= length && queue_[right].key < queue_[smallest].key)
        smallest = right;

    //std::cout<<"Min idx : "<<smallest<<std::endl;
    if (smallest != node) {                 // 如果目前node的Key不是三者中的最小
        swap(queue_[smallest], queue_[node]);   // 就調換node與三者中Key最小的node之位置
        MinHeapify(smallest, length);       // 調整新的subtree成Min Heap
    }
    /*
    cout<<endl;
    cout<<"End"<<endl;
    for(int i = 0;i<size_ + 1;i++){
      cout<<queue_[i].ele<<"    "<<queue_[i].key<<endl;
    }
    cout<<endl;
    */
    
}
int Heap::GetIdx(int Node){
  int idx = 0;
  for (int i = 1; i < queue_.size(); i++) {
      if (queue_[i].ele == Node) {
        idx = i;
      }
  }
  return idx;
}
void Heap::chgkey(int node,int N_key){
  int idx = GetIdx(node);
  if (N_key > queue_[idx].key) {      
    return;
  }
  queue_[idx].key = N_key;
  while (idx > 1 && queue_[parent(idx)].key > queue_[idx].key) {
    swap(queue_[idx], queue_[parent(idx)]);
    idx = parent(idx);
  }
}

string Heap::toString() const {
  /*
  if (isEmpty()) return "";

  ostringstream sstream;
  copy(queue_.begin() + 1, queue_.end() - 1, ostream_iterator<int>(sstream, " "));
  sstream << *(queue_.end() - 1)->key;
  
  return sstream.str();
  */
}