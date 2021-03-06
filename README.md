# Basic-Sorting-Algorithms

This is a program with eight different basic sorting algorithms, and a visualizer for how fast these algorithms perform. I filled an array with random but uniformly distributed integers from 0 to 10,000.

The UI is created with OneLoneCoder's PixelGameEngine. Check out his GitHub here https://github.com/OneLoneCoder!

Here is an image of random arrary of numbers with the numbers represented by randomly colored rectangles.
![Random](/SortingImages/random.PNG)

---
Below are the times of the different sorting algorithms and how many items they sorted. The rectangles will show that they have been properly sorted.

1. Standard Library Sort - To test as a baseline for the other sorting algorithms.
![Standard](/SortingImages/standard.PNG)

2. Bubble Sort - The slowest sort, but the fastest when the array is already sorted.
![Bubble](/SortingImages/Bubble.PNG)

3. Quick Sort - The Fastest sort with unsorted arrays, but very slow with already sorted arrays. 
![Quick](/SortingImages/quick.PNG)

4. Insertion Sort - Pretty slow but still faster than Bubble Sort, very good with sorted arrays.
![Insertion](/SortingImages/insertion.PNG)

5. Radix Sort - Very fast for unsorted random uniformly distributed integers. Not As fast with sorted numbers, but better than quick sort.
![Radix](/SortingImages/radix.PNG)

6. Selection Sort - The second slowest for unsorted arrays, but slower than bubble for sorted arrays. 
![Selection](/SortingImages/selection.PNG)

7. Merge Sort - Not as fast as quick sort with unsorted arrays but still pretty fast, however really fast for sorted arrays.
![Merge](/SortingImages/merge.PNG)

8. Heap Sort - Comprable speed to quicksort, much better speed in regards to sorted arrays. 
![Heap](/SortingImages/heap.PNG)

For this specific test, Quick Sort came out the fastest when the array was unsorted. However if you have the possibility of a sorted array, it would be best to go with Merge sort, or even Radix sort. 
