#include <iostream>
#include "sort.h"

using namespace std;

int main()
{
    int AA[] = {2, 5, 9, 1, 10, 8, 9};

//    SelectionSort(AA, sizeof(AA) / sizeof(AA[0]));
//    for (auto it : AA)
//        cout << it << " ";
//    cout << endl;

//    BubbleSort(AA, sizeof(AA) / sizeof(AA[0]));
//    for (auto it : AA)
//        cout << it << " ";
//    cout << endl;

//    InsertionSort(AA, sizeof(AA) / sizeof(AA[0]));
//    for (auto it : AA)
//        cout << it << " ";
//    cout << endl;

    QuickSort(AA, 0, sizeof(AA) / sizeof(AA[0]) - 1);
    for (auto it : AA)
        cout << it << " ";
    cout << endl;

    return 0;
}
