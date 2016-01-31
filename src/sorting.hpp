// ICS 46 Summer 2015
// Project 1
//
// This file contains your implementations of the sorting algorithms. Do not
// change the function headers, as the functions in reporting.hpp will be
// calling these functions.
//
#ifndef __SORTING_HPP__
#define __SORTING_HPP__
#include <vector>

// =============================================================================
// Helper functions
// =============================================================================

// Swaps two values
template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Checks if a vector is sorted
template <typename T>
bool is_sorted(const std::vector<T>& vector)
{
    auto t = vector[0];
    for (auto e : vector)
    {
        if (e < t) return false;
        t = e;
    }
    return true;
}

//Print a vector
template <typename T>
void print_vector(const std::vector<T>& vector)
{
    for (T e : vector)
       std::cout << e << " ";
    std::cout << std::endl;
}

// =============================================================================
// Sorting functions
// =============================================================================

/* Insertion sort is a sorting algorithm that takes
 * at worst O(n^2) time to run. It works by creating
 * two iterators that compare two elements of the data
 * structure. If one element is out of order, those
 * two elements are swapped. This continues until the
 * data structure is finally in order. NOTE: Insertion
 * sort can be performed on structures with comparable
 * elements. Here we implement Insertion sort with a
 * template class and a vector.
 */
template <typename T>
void insertion_sort(std::vector<T>& vector)
{
    for (int i=1; i<vector.size(); i++)
    {
	// iterates through the vector starting at the second item
        T temp = vector[i];
        int j = i;
		while (j > 0 && temp < vector[j-1]) 
		{
		// iterates through the vector backwards starting at i until the item
		// at index i is less than the item at index j-1
		    swap(vector[j],vector[j-1]);
		    j--;
		}
    }
}

/* This function merges two vectors and returns a final
 * combined vector. This function is used by both the
 * merge sort algorithm and the hybrid sort algorithm.
 */
template <typename T>
std::vector<T> merge(std::vector<T>& a, std::vector<T>& b)
{
    T temp;
    std::vector<T> result(a.size()+b.size(),temp); // initializes the resultant vector to the size of both input vectors with a dummy variable in each spot
    int i = 0, j = 0, k = 0; // initiliazes the iterators
    while (i < a.size() && j < b.size())
    {
	if (a[i] < b[j])
	{
            result[k] = a[i];
	    i++;
	}
	else // if a[i] > b[j]
	{
	    result[k] = b[j];
	    j++;
	}
	k++;
    }
    while (i < a.size())
    {
    // iterates through a in case all elements of a
    // haven't been added to the final vector
	result[k] = a[i];
	i++,k++;
    }
    while (j < b.size())
    {
    // iterates through b in case all elements of b
    // haven't been added to the final vector
	result[k] = b[j];
	j++,k++;
    }
    //std::vector<T> resultant(result,result + sizeof(result) / sizeof(T));
    return result;
}
 

/* Because the default merge_sort() function is a void
 * function, I found it easier to write a separate mergeSort()
 * function which runs merge sort and returns the sorted list.
 * This function is called in merge_sort().
 */
template <typename T>
std::vector<T> mergeSort(std::vector<T> vector)
{

   if (vector.size() <= 1)
   {
      return vector;
   }
 
   std::vector<T> left, right;
   std::vector<T> result;
   
   int midpoint = (vector.size()+ 1) / 2;

   std::vector<T> first(vector.begin(), vector.begin() + midpoint);
   std::vector<T> second(vector.begin() + midpoint, vector.end());
 
   first = mergeSort(first);
   second = mergeSort(second);
   result = merge(first,second);
 
   return result;
}


/* Merge sort is a sorting algorithm that runs in O(nlog(n)) time.
 * It works by dividing the unsorted data structure into sublists,
 * each containing 1 element (recursively). After having all these
 * lists of length 1 which are technically already sorted, the
 * algorithm merges the sublists to produce new sorted sublists
 * until there is only 1 sublist remaining. This final sublist is
 * the resultant sorted list. NOTE: Merge sort can be performed
 * only on structures with comparable elements. Here we implement
 * Merge sort with a template class and a vector.
 */
template <typename T>
void merge_sort(std::vector<T>& vector)
{
    vector = mergeSort(vector);   
}


/* Because the default hybrid_sort() function is a void
 * function, I found it easier to write a separate hybridSort()
 * function which runs merge sort and returns the sorted list.
 * This function is called in hybrid_sort().
 */
template <typename T>
std::vector<T> hybridSort(std::vector<T>& vector)
{
   int k = 5;
   if (vector.size() <= k)
   {
      insertion_sort(vector);
      return vector;
   }
 
   std::vector<T> result;
   
   int midpoint = (vector.size()+ 1) / 2;

   std::vector<T> first(vector.begin(), vector.begin() + midpoint);
   std::vector<T> second(vector.begin() + midpoint, vector.end());
 
   first = hybridSort(first);
   second = hybridSort(second);
   result = merge(first, second);
 
   return result;
}

/* Hybrid sort is an algorithm that is a combination of merge sort
 * insertion sort. A constant "k" is chosen and once the size of the
 * sublists in the merge sort algorithm reach this size, insertion sort
 * is called on those sublists. Those sublists are then merged together
 * using the merge() function above. NOTE: Hybrid sort can be performed
 * only on structures with comparable elements. Here we implement
 * Hybrid sort with a template class and a vector.
 */
template <typename T>
void hybrid_sort(std::vector<T>& vector)
{
    vector = hybridSort(vector);
	
}

#endif // __SORTING_HPP__
