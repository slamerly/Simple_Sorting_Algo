#include <iostream>
#include <vector>
#include <time.h>

// Find the position of the smallest element after startPosition
// else return startPosition
int positionOfSmallestElementAfter(std::vector<int>& ref, int startPosition)
{
    int min = ref[startPosition];
    int minPos = startPosition;
    for (int i = startPosition; i < ref.size(); i++)
    {
        if (min > ref[i])
        {
            min = ref[i];
            minPos = i;
        }
    }

    return minPos;
}


void selectionSort(std::vector<int>& ref)
{
    int currentSelection = 0;
    int minPos = 0;
    int saveSwapValue = 0;

    while (currentSelection < ref.size())
    {
        minPos = positionOfSmallestElementAfter(ref, currentSelection);
        if (minPos != currentSelection)
        {
            saveSwapValue = ref[currentSelection];
            ref[currentSelection] = ref[minPos];
            ref[minPos] = saveSwapValue;
        }
        currentSelection++;
    }
}

// Display the list
void printVector(std::vector<int> ref)
{
    for (auto element : ref)
    {
        std::cout << element << ", ";
    }
    std::cout << std::endl;
}


int main()
{
    // Initialization
    srand(time(NULL));
    std::vector<int> list;
    for (int i = 0; i < 8; i++)
    {
        list.push_back(rand() % 100 + 1);
    }

    std::cout << "Initial list: " << std::endl;
    printVector(list);
    std::cout << std::endl;

    // Sort
    selectionSort(list);

    std::cout << "Sorted list: " << std::endl;
    printVector(list);
}
