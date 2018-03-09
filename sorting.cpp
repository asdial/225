// File:        sorting.cpp
// Author:      Geoffrey Tien
//              (your name)
// Date:        2015-06-10
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here

#include <cstdlib>
#include <ctime>


template <class T>
int SelectionSort(T arr[], int n)	// selection sort algorithm, takes an array and the size of the array as parameters with a return type of int that is counting the barometer comparisons 
{
	T temp;
	int barometerCount = 0;
  
	for(int i = 0; i < (n-1); i++)
	{
		int smallest = i;
		for(int j = i+1; j < n; j++)
		{
			if(arr[j] < arr[smallest])
			{
				smallest = j;
			}
			barometerCount ++;
		}

		temp = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = temp;
	}

	return barometerCount;
}


template <class T>
int Quicksort(T arr[], int n)	// quicksort sort algorithm, takes an array and the size of the array as parameters with a return type of int that is counting the barometer comparisons
{
	int first = 0;
	int last = n-1;
	int barometerCount = 0;

	QuicksortHelper(arr, first, last, barometerCount);

	return barometerCount;
}


template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)	//calls the QSPartition function, also this helper function is a resursive function because it calls itself twice 
{
	if(low < high)
	{
		int thePivot = QSPartition(arr, low, high, counter);
		QuicksortHelper(arr, low, thePivot-1, counter);
		QuicksortHelper(arr, thePivot+1, high, counter);
	}
}


template <class T>
int QSPartition(T arr[], int low, int high, int& counter)	// partitioning of the the left side of the array and the right side, the function takes in an array, low index, high index, and the barometer count and returns the index of pivot 
{

	int pivot = high;
	high = high-1;
	T temp;
	
	while(low <= high)
	{
		counter++;
		while (( arr[low] <= arr[pivot]) && (low <= high))
		{
			low++;
			counter++;
		}

		while ((arr[high] > arr[pivot]) && (high >= low))
		{
				high--;
				counter++;
		} 
		
		counter++;
		if ((high >= 0) && (low <= high))
		{
			if((arr[low] > arr[pivot]) && (arr[high] <= arr[pivot]))
			{
				temp = arr[low];
				arr[low] = arr[high];
				arr[high] = temp;
		
				low++;
				high--;
			}
		}
	}

	if	(high==low)
	{

			temp = arr[pivot];
			arr[pivot] = arr[low];
			arr[low] = temp; 
			pivot = low;
	}

	if (arr[low] > arr[pivot])
	{
			temp = arr[pivot];
			arr[pivot] = arr[low];
			arr[low] = temp; 
			pivot = low;
	}
	
	return pivot;
}


template <class T>
int Mergesort(T arr[], int n)	//calls the helper function, takes in an array and its size
{
  int low = 0;
  int high = n-1;
  int barometerCount = 0;

  MergesortHelper(arr, low, high, n, barometerCount);

  return barometerCount;

}


template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)	//this is a recursive function which calls its self and at 2 seperate times and also calls the Merge function, and takes in as parameters an array, low index, high index, size of array and barometer count
{
	if(low < high)
	{
		int mid = (low+high)/2;

		MergesortHelper(arr, low, mid, n, counter);
		MergesortHelper(arr, mid+1, high, n, counter);
		Merge(arr, low, mid, high, n, counter);
	}
}

template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)	//this function does the merging of subarrays until it merges the full array back together, it takes in an array, low index, mid index, high index, the size of the array, and barometer count
{
	T* temp = new T[n];
	int i = low;
	int p = low;
	int k = mid+1;

	while ((k <= high) && (i <= mid))
	{
		counter += 2;
		if (arr[i] <= arr[k])											
		{
				temp[p] = arr[i];					
				i++;
		}

		else
		{
				temp[p] = arr[k];									
				k++;
		}
		p++;
	}

	if(i > mid)
	{
		for(int w = k; w <= high; w++)
		{
			temp[p] = arr[w];
			p++;
		}
	}
	else
	{
		for(int m = i; m <= mid; m++)
		{
			temp[p] = arr[m];
			p++;
		}
	}

	for(int m = low; m <= high; m++)
	{
		arr[m] = temp[m];
	}

	delete[] temp;
}

template <class T>
int ShellSort(T arr[], int n)	//this sorting alogorithm is the least efficient, the function takes in an array and the size of the array
{
	int barometerCount = 0;
	T temp;
	int gapValue = n;
	int gapSize;

	for(int i = 0; i < n; i++)
	{
		gapValue = gapValue/2;
		gapSize = n-gapValue;

		for(int j = 0; j < gapSize; j++)
		{
			if(arr[j] > arr[j+gapValue])
			{
				temp = arr[j];
				arr[j] = arr[j+gapValue];
				arr[j+gapValue] = temp;

				for(int k = j; k >= gapValue; k--)
				{
					if(arr[k] < arr[k-gapValue])
					{
						temp = arr[k];
						arr[k] = arr[k-gapValue];
						arr[k-gapValue] = temp;
					}
					barometerCount += 2;
				}
			}
			barometerCount += 2;
		}
	}

	return barometerCount;
}