/*
 *	Author: Caleb A. Payton
 *	Quicksort algorithm
 *	
 *	Program generates a random vector of size 20 with random
 *	integers between 1 and 20, then sorts them using a 
 *	quicksort algorithm.
 */

#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>

using namespace std;

template<typename Comparable>
void insertionSort(vector<Comparable> & a, int left, int right);

template<typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right);

template<typename Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right);

template<typename Comparable>
void quicksort(vector<Comparable> & a);

/**
 * Internal insertion sort routine for subarrays
 * that is used by quicksort.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template<typename Comparable>
void insertionSort(vector<Comparable> & a, int left, int right)
{
	for (int p = left + 1; p <= right; p++)
	{
		Comparable tmp = a[p];
		int j;

		for (j = p; j > left && tmp < a[j - 1]; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

/**
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partitioning and a cutoff of 10.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template<typename Comparable>
void quicksort(vector<Comparable> & a, int left, int right)
{
	if (left + 3 <= right)
	{
		Comparable pivot = median3(a, left, right);

		// Begin partitioning
		int i = left, j = right - 1;
		for (;;)
		{
			while (a[++i] < pivot)
			{
			}
			while (pivot < a[--j])
			{
			}
			if (i < j)
				swap(a[i], a[j]);
			else
				break;
		}

		swap(a[i], a[right - 1]); // Restore pivot

		quicksort(a, left, i - 1); // Sort small elements
		quicksort(a, i + 1, right); // Sort large elements
	}
	else
		// Do an insertion sort on the subarray
		insertionSort(a, left, right);
}

/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
template<typename Comparable>
const Comparable & median3(vector<Comparable> & a, int left, int right)
{
	int center = (left + right) / 2;
	cout << "In: " << a[left] << ", " << a[center] << ", " << a[right] << endl;
	if (a[center] < a[left])
		swap(a[left], a[center]);
	if (a[right] < a[left])
		swap(a[left], a[right]);
	if (a[right] < a[center])
		swap(a[center], a[right]);

	// Place pivot at position right - 1
	swap(a[center], a[right - 1]);
	cout <<  "Out: " << a[left] << ", " << a[center] << ", " << a[right] << endl;
	return a[right - 1];
}

/**
 * Driver for quicksort algorithm.
 */
template<typename Comparable>
void quicksort(vector<Comparable> & a)
{
	quicksort(a, 0, a.size() - 1);
}

void printVector(vector<int> & h)
{
	unsigned int i;
	cout << h[0];
	for (i = 1; i < h.size(); ++i)
	{
		cout << ", " << h[i];
	} // end for
	cout << "\n" << endl;
}

int main()
{
	vector<int> h(20);

	int i;
	srand(time(NULL));
	for (i = 0; i < h.size(); ++i)
	{
		h[i] = (rand()%20) + 1;
	}

	printVector(h);
	quicksort(h);
	cout << "\n";
	printVector(h);
	return 0;
}
