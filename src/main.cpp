// ICS 46 Summer 2015
// Project 1
//
// This file runs the timing tests on your sorting
// algorithm implementations.  You do not need to
// edit this code.
//
#include <vector>
#include <iostream>
#include "sorting.hpp"
#include "reporting.hpp"

int main()
{
    // Feel free to edit the number of runs per test and the test sizes
    unsigned int const runs_per_test = 10;
    // Be aware that insertion sort is O(n^2) time on the random list
    // Larger test sizes may take prohibitively long to insertion sort
    std::vector<unsigned int> test_sizes = {10, 100, 1000, 10000, 100000};

    std::vector<sorter_t<int>> sorters = {insertion_sort<int>, merge_sort<int>, hybrid_sort<int>};
    std::vector<std::string> sorter_names = {"Insertion Sort", "Merge Sort", "Hybrid Sort"};

    std::vector<generator> generators = 
        {generate_random, generate_almost_sorted_1, generate_almost_sorted_2};
    std::vector<std::string> gen_names = 
        {"Uniformly Random List", "Nearly Sorted List 1", "Nearly Sorted List 2"};

    
    sorting_report(sorters, sorter_names, runs_per_test, test_sizes, generators, gen_names);
    return 0;
}

