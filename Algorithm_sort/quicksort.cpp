/*!
 * This program implements the quicksort algorithm
 *
 * To compile we might use two options:
 * 1) g++ -Wall -std=c++11 quicksort.cpp -o quicksort
 * 2) g++ -Wall -std=c++11 quicksort.cpp -o quicksort -D DEBUG
 *
 * The second option print all the intermediate states of the
 * partition function, for debugging purpose.
 */

#include <iostream>     // cout, endl
#include <functional>   // std::function
#include <iomanip>      // setw, setfill

/// Displays on the screen (std::cout) the content of a range of integers.
void print( int * first_, int * last_ )
{
    std::cout << "[ ";
    while( first_ < last_ )
    {
        std::cout << *first_ << " ";
        first_++;
    }
    std::cout << "]";
}

/*!
 * Partitions the range [first;last) into regions (sub-arrays): elements less or
 * equal to the pivot, and elements greater than the pivot.
 * The function returns a pointer to the beginning of the second
 * region.
 *
 * \note
 * The pivot is always the last (valid) element of the original range.
 * Because of that, the pivot is always located at the end of the
 * first region (elements less or equal to the pivot).
 *
 * \param first_ the beginning of the range.
 * \param last_ the (past-the-)end of the range.
 *
 * \return A pointer to the beginning of the second region (greater than pivot).
 *
 * See the representation below:
 *
 *     first_                                                  last_ (past the end)
 *         |                slow                  fast         |
 *         |                   |                  |            |
 *         v                   v                  v            v
 * Array: [ elements <= pivot | elements > pivot | unprocessed ]
 *
 */
int * partition( int * first_, int * last_ )
{
    auto pivot = *(last_ - 1); //!< Last valid element.
    auto slow( first_ ); //!< Points past-the-end of the sub-array of elements <= pivot.
    auto fast( first_ ); //!< Points past-the-end of the sub-array of elements > pivot.

#ifdef DEBUG
    std::cout << ">>> Partition the array: ";
    print(first_, last_); // Print region of elements <=  pivot
    std::cout << std::endl;
#endif
    // Traverse the range.
    while( fast != last_ )
    {
        // Update the region of elements <= pivot.
        if ( *fast <= pivot )
        {
            std::swap( *fast, *slow );
            slow++; // Increase region by moving slow forward.
        }

        fast++; // Always advances.

// Activate debug mode by adding the -D DEBUG flag to the compilation line.
#ifdef DEBUG
        print(first_, slow); // Print region of elements <=  pivot
        print(slow, fast);   // Print region of elements > pivot
        print(fast, last_);  // Print region of unprocessed elements.
        std::cout << std::endl;
#endif
    }
#ifdef DEBUG
    std::cout << std::setw(50) << std::setfill('-') << "" << std::endl;
#endif

    return slow; // Return the begining of the second region.
}

/// Sorting algorithm based on partition.
void quick_sort( int * first_, int * last_ )
{
    // Base case: first == last
    if ( first_ == last_ ) return; // If we got just one element then it's sorted!

    // Partition the range.
    // ** We got the pivot in its final position! **
    auto past_the_pivot = partition( first_, last_ );

    quick_sort( first_, past_the_pivot-1 ); // Exclude the pivot
    quick_sort( past_the_pivot, last_ ); // Exclude the pivot.
}

int main( void )
{
    int A1[] = { 7, 10, 1, 3, 6, 8, 2, 9, 4, 5 };
    int A2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int A3[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    std::cout << ">>> Original array A1:\n";
    print( std::begin(A1), std::end(A1) );
    std::cout << std::endl;

    quick_sort( std::begin(A1), std::end(A1) );

    std::cout << ">>> A1 after sorting:\n";
    print( std::begin(A1), std::end(A1) );
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << ">>> Original array A2:\n";
    print( std::begin(A2), std::end(A2) );
    std::cout << std::endl;

    quick_sort( std::begin(A2), std::end(A2) );

    std::cout << ">>> A2 after sorting:\n";
    print( std::begin(A2), std::end(A2) );
    std::cout << std::endl;
    std::cout << std::endl;


    std::cout << ">>> Original array A3:\n";
    print( std::begin(A3), std::end(A3) );
    std::cout << std::endl;

    quick_sort( std::begin(A3), std::end(A3) );

    std::cout << ">>> A3 after sorting:\n";
    print( std::begin(A3), std::end(A3) );
    std::cout << std::endl;


    return EXIT_SUCCESS;
}
