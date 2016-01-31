# Sorting-Algorithms

This repo contains implementations of some classic sorting algorithms written in C++. The three sorting algorithms that are implemented are:
 * Insertion Sort
 * Merge Sort
 * Hybrid Sort (A combination of Merge and Insertion sort)
   * The idea is to have the merge sort recursion cutoff once the list size is smaller than some constant and at that point insertion sort the remaining list. This means changing the base case of merge sort to stop at a list size less than or equal to k. Once you have things working try seeing how changing k affects your run time. 

I implemented the data structure to be sorted as a templated vector from the standard library as to avoid any manual memory management issues.
