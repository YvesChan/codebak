//Max-heap class
#include<cstdio>
#include<iostream>
using namespace std;

template <class Elem> class maxheap {
private:
	Elem* heap;   //pointer to the heap array
	int size;     //Maximum size of the heap
	int n;      //number of elem in the heap
	void siftdown(int pos);   //set the elem in correct order
public:
	maxheap(Elem* h,int number,int maxsize){
		heap = h; size = maxsize; n = number;
		buildHeap();
	}
	int heapSize() const{     //const function:not allow to modify the data member
		return size;
	}
	bool isLeaf(int pos) const{
		return (pos >= n) && (pos < n);
	}
	int leftChild(int pos) const{
		return 2 * pos + 1;    //return index(in array) of the left child
	}
	int rightChild(int pos) const{
		return 2 * pos + 2;
	}
	int parent(int pos) const {
		return (pos - 1) / 2;
	}
	void swap(Elem* h,int a,int b) const{   //swap two elems' value
		h[a] ^= h[b]; h[b] ^= h[a]; h[a] ^= h[b];
	}
	bool insert(const Elem& val);
	bool pop(Elem& it);
	bool remove(int pos,Elem& it);
	void buildHeap(){
		for(int i = n / 2 - 1;i >= 0;i --)siftdown(i);
	}
	void print(){
		if(n == 0){printf("empty heap");return;}
		for(int i = 0;i < n;i ++)cout<<heap[i]<<"  ";
		cout<<endl;
	}
};
template <class Elem>
void maxheap<Elem>::siftdown(int pos){
	while(!isLeaf(pos)){
		int l = leftChild(pos);
		int r = rightChild(pos);
		l = heap[l] > heap[r] ? l : r;    //set l is the greater elem'index
		if(heap[pos] > heap[l])return;     //position correct
		swap(heap,pos,l);
		pos = l;
	}
}
template <class Elem>
bool maxheap<Elem>::remove(int pos,Elem& it){
	if(pos < 0 || pos >= n)return false;    //index out of array
	swap(heap,pos,n - 1);
	n --;
	it = heap[n];
	//sift up or sift down
	while(pos > 0 && heap[pos] > heap[parent(pos)]){
		swap(heap,pos,parent(pos));
		pos = parent(pos);
	}
	siftdown(pos);
	return true;
}
template <class Elem>
bool maxheap<Elem>::pop(Elem& it){
	if(n == 0)return false;    //heap is empty
	swap(heap,0,n - 1);        //exchange root(max) with the last elem
	n --;
	it = heap[n];
	if(n != 0)siftdown(0);
	return true;
}
template <class Elem>
bool maxheap<Elem>::insert(const Elem& val){
	if(n >= size)return false;   //heap is full
	int curr = n ++;     //index of new elem
	heap[curr] = val;
	//now sfit up the new elem
	while(curr > 0 && heap[curr] > heap[parent(curr)]){
		swap(heap,curr,parent(curr));
		curr = parent(curr);     //sift up the new elem
	}
	return true;
}

int main()
{
	int a[100] = {0},num;
	scanf("%d",&num);
	for(int i = 0;i < num;i ++)scanf("%d",a + i);
	maxheap<int> h(a,num,100);
	h.print();
	int t;
	h.pop(t);
	h.print();
	return 0;
}