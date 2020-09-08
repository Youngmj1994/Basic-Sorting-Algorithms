#include "olcPixelGameEngine.h"
#include "bubble_sort.h"
#include "in_place_quick_sort.h"
#include "insertion_sort.h"
#include "radix_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"

#include <random>
#include <chrono>
#include <fstream>
#include <iterator>
#include <string>

const int NUMBER_OF_ITEMS_TO_BE_SORTED = 10000;

enum sorts
{
    STANDARD_LIBRARY_SORT = 0,
    BUBBLE_SORT,
    IN_PLACE_QUICK_SORT,
    INSERTION_SORT,
    RADIX_SORT,
    SELECTION_SORT,
    K_WAYS_MERGE_SORT,
    HEAP_SORT
    
};

class SortVisualizer : public olc::PixelGameEngine
{
public:
    SortVisualizer()
    {
        sAppName = "Sorts";
    }

public:

    void create_numbers(int numbersForArray, std::vector<int> &numberarray)
    {
        auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        auto mt_rand = std::bind(std::uniform_int_distribution<int>(1, 10000), std::mt19937(seed));
        numberarray.clear();
        for (int i = 0; i < numbersForArray; i++)
        {
            numberarray.push_back(mt_rand());
        }
    }

    void draw_random_rectangles(int negativeX = 0, int rectangleYModifier = 0)
    {
        Clear(olc::BLUE);
        for (int i = numberarray.size()-1; i > 0; i--) {
            DrawRect({ i,(numberarray[i]) }, { 4,100 + rectangleYModifier }, { uint8_t(rand() % 255),uint8_t(rand() % 255),uint8_t(rand() % 255) });
        }
    }

    void draw_sorted_rectangles(int drawMode, int timeCount)
    {
        Clear(olc::BLUE);
        draw_random_rectangles(2850, 100);
        switch (drawMode)
        {
        case STANDARD_LIBRARY_SORT:
            
            DrawString({ 450,32 }, "Standard Library Sort", olc::YELLOW, 2);
            break;
        case BUBBLE_SORT:
            
            DrawString({ 450,32 }, "Bubble Sort", olc::YELLOW, 2);
            break;
        case IN_PLACE_QUICK_SORT:
            
            DrawString({ 450,32 }, "Quick Sort In Place", olc::YELLOW, 2);
            break;
        case INSERTION_SORT:
            
            DrawString({ 450,32 }, "Insertion Sort", olc::YELLOW, 2);
            break;
        case RADIX_SORT:
            
            DrawString({ 450,32 }, "Radix Sort", olc::YELLOW, 2);
            break;
        case SELECTION_SORT:
            
            DrawString({ 450,32 }, "Selection Sort", olc::YELLOW, 2);
            break;
        case K_WAYS_MERGE_SORT:
            
            DrawString({ 450,32 }, "Merge Sort", olc::YELLOW, 2);
            break;
        case HEAP_SORT:

            DrawString({ 450,32 }, "Heap Sort", olc::YELLOW, 2);
            break;
        default:
            break;
        }
        DrawString({ 300,0 }, std::to_string(timeCount) + " Microseconds To Sort", olc::YELLOW, 2);
        DrawString({ 450,16 }, std::to_string(NUMBER_OF_ITEMS_TO_BE_SORTED) + " Items Sorted", olc::YELLOW, 2);
    }

    void sort_helper(int sortSelect)
    {
        bubble_sort bubble;
        in_place_quick_sort quick_sort;
        insertion_sort insertion;
        radix_sort radix;
        selection_sort selection;
        merge_sort merge_;
        heap_sort heap_;

        auto start = std::chrono::high_resolution_clock::now();

        switch (sortSelect)
        {
        case STANDARD_LIBRARY_SORT:
            std::sort(numberarray.begin(), numberarray.end());
            break;
        case BUBBLE_SORT:
            bubble.sort(numberarray);
            break;
        case IN_PLACE_QUICK_SORT:
            quick_sort.sort(numberarray, 0,numberarray.size()-1);
            break;
        case INSERTION_SORT:
            insertion.sort(numberarray);
            break;
        case RADIX_SORT:
            radix.sort(numberarray);
            break;
        case SELECTION_SORT:
            selection.sort(numberarray);
            break;
        case K_WAYS_MERGE_SORT:
            merge_.sort(numberarray, 0, numberarray.size()-1);
            break;
        case HEAP_SORT:
            heap_.sort(numberarray);
            break;
        default:
            break;
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        draw_sorted_rectangles(sortSelect, duration.count());
    }

    bool OnUserCreate() override
    {
        create_numbers(NUMBER_OF_ITEMS_TO_BE_SORTED, numberarray);
        Clear(olc::BLUE);
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {
        
       if (GetMouse(0).bPressed) {
           std::random_shuffle(numberarray.begin(), numberarray.end());
           draw_random_rectangles();
       }

       if (GetKey(olc::K1).bPressed)
       {
           mode = 0;
           sort_helper(mode);
       }
       if (GetKey(olc::K2).bPressed)
       {
           mode = 1;
           sort_helper(mode);
       }
       if (GetKey(olc::K3).bPressed)
       {
           mode = 2;
           sort_helper(mode);
       }
       if (GetKey(olc::K4).bPressed)
       {
           mode = 3;
           sort_helper(mode);
       }
       if (GetKey(olc::K5).bPressed)
       {
           mode = 4;
           sort_helper(mode);
       }
       if (GetKey(olc::K6).bPressed)
       {
           mode = 5;
           sort_helper(mode);
       }
       if (GetKey(olc::K7).bPressed)
       {
           mode = 6;
           sort_helper(mode);
       }
       if (GetKey(olc::K8).bPressed)
       {
           mode = 7;
           sort_helper(mode);
       }
       if (GetKey(olc::K9).bPressed)
       {
           mode = 8;
           sort_helper(mode);
       }
       if (GetKey(olc::K0).bPressed)
       {
           mode = 9;
           sort_helper(mode);
       }

        return true;
    }

    int mode = 0;
    std::vector<int> numberarray;
protected:

};

//1.bubble sort
//2.selection sort
//3.insertion sort
//4.in-place quick sort
//5.bucket sort
//6.radix sort
//7.k-way merge sort
int main()
{
    SortVisualizer sv;
    if (sv.Construct(800, 720, 1, 1))
        sv.Start();

    return 0;
}