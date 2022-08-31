/*
Simple heap implementation using an array with functions
Variables are global to avoid dealing with pointers
Recursive heapify functions
*/
#include <stdio.h>
#define MAXHEAPSIZE 20
int HeapInsert(int item);
int HeapDelete();
int PrintHeap();
int HeapifyDownRecursive(int i);
int HeapifyUpRecursive(int i);

// global variables for heap
int heapSize = 0; // number of elements in heap
int heap[MAXHEAPSIZE];

int main()
{
	int j, valReturned;
	
	HeapInsert(6);
	HeapInsert(9);
	HeapInsert(3);
	HeapInsert(2);
	HeapInsert(7);
	HeapInsert(4);
	HeapInsert(3);
	HeapInsert(8);
	
	PrintHeap();

	valReturned = HeapDelete();
	printf("deleted value is = %d\n",valReturned);
	
	PrintHeap();

	valReturned = HeapDelete();
	PrintHeap();
	valReturned = HeapDelete();
	PrintHeap();
	valReturned = HeapDelete();
	PrintHeap();
	valReturned = HeapDelete();
	PrintHeap();
	
	return 0;
}

// function to push an element onto the heap
int HeapInsert(int item)
{
	if(heapSize<MAXHEAPSIZE)  // COMPLETE condition to ensure heap not full
	{
		// COMPLETE body; see lecture notes
		heap[heapSize] = item;
		HeapifyUpRecursive(heapSize);
		heapSize++;

		return 0;
	}
	else 
	{
		printf("Insertion error; heap is full\n");
		return 1;
	}
}

// function to delete an element from the heap
int HeapDelete()
{
	if(heapSize > 0)		// COMPLETE condition to ensure heap not empty
	{
		int returnValue;
		returnValue =  heap[0];			// COMPLETE

		// COMPLETE remainder of function; see lecture notes
		heap[0] = heap[heapSize-1];
		heapSize--;
		HeapifyDownRecursive(0);
		
		return(returnValue);
	}
	else
	{
		printf("Deletion error; heap is empty\n");
		return -1;
	}
}


// function to print out heap elements
int PrintHeap()
{

	// COMPLETE
	if( heapSize > 0 )  // COMPLETE missing condition
	{
		int j;
		printf("heap contents: ");
		for ( j = 0; j < heapSize; j++ )	// COMPLETE missing loop info
		{
			printf("%d ",heap[j]);
		}
		printf("\n");
		return 0;
	}
	else
	{
		printf("Printing error; heap is empty\n");
		return -1;
	}
}

// Heapify Up function used when inserting
// recursive version
int HeapifyUpRecursive(int i)
{
	int temp;
	if (i == 0)		// COMPLETE condition indicating this is the root
		return 0;
	if (heap[i] < heap[(i-1)/2])		// COMPLETEthis node < its parent
	{
		// COMPLETE including recursive function call
		temp = heap[i];
		heap[i] = heap[(i-1)/2];
		heap[(i-1)/2] = temp;
		HeapifyUpRecursive((i-1)/2);
	}
	return 0;
		
}

// Heapify Down function used when deleting
// recursive version
int HeapifyDownRecursive(int i)
{
	int temp;
	// if i exceeds heapsize or if no child nodes
	if (i > heapSize || 2*i+1 > heapSize-1) // COMPLETE condition described above
		return 0;
	else if (2*i+2 > heapSize-1) // COMPLETE condition for one child node case
	{
		if(heap[i] > heap[2*i+1])   // COMPLETE condition needed for swap with child
		{
			// COMPLETE swap
			temp = heap[i];
			heap[i] = heap[2*i+1];
			heap[2*i+1] = temp;
		}
	}
	
	if (heap[i] < heap[2*i+1] && heap[i] < heap[2*i+2]) // COMPLETE check heap property
		return 0;
	if (heap[2*i+1] < heap[2*i+2]) 		// COMPLETE left node < right
	{
		// COMPLETE swap
		// add recursive call, conditions needed?
		temp = heap[i];
		heap[i] = heap[2*i+1];
		heap[2*i+1] = temp;
		HeapifyDownRecursive(2*i+1);
	}
	else								// right node >= left
	{
		// COMPLETE swap
		// add recursive call, conditions needed?
		temp = heap[i];
		heap[i] = heap[2*i+2];
		heap[2*i+2] = temp;
		HeapifyDownRecursive(2*i+2);
	}
	return 0;
}
