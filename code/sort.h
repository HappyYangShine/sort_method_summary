#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <utility>

//
template <typename T>
void SelectionSort(T A[], int n)
{
    int smallIndex;
    T temp;

    for (int i = 0; i < n; i++)
    {
        smallIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[smallIndex])
                smallIndex = j;
        }
        temp = A[i];
        A[i] = A[smallIndex];
        A[smallIndex] = temp;
    }
}

//
template <typename T>
void BubbleSort(T A[], int n)
{
    int i, j;
    int LastIndex;
    T temp;

    i = n - 1;

    while (i > 0)
    {
        LastIndex = 0;

        for (j = 0; j < i; j++)
        {
            if (A[j + 1] < A[j])
            {
                temp = A[j + 1];
                A[j + 1] = A[j];
                A[j] = temp;
                LastIndex = j;
            }
        }
        i = LastIndex;
    }
}

//
template <typename T>
void InsertionSort(T A[], int n)
{
    int i, j;
    T temp;

    for (i = 1; i < n; i++)
    {
        j = i;
        temp = A[j];

        while (j > 0 && temp < A[j - 1])
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
}


//
template <typename T>
void Swap(T &A, T &B)
{
    T temp = B;
    B = A;
    A = temp;

}

//
template <typename T>
void QuickSort_2(T A[], int low, int high)
{
    T pivot;
    int scanUp, scanDown;
    int mid;

    if (high - low <= 0)
        return;
    else
    {
        if (high - low == 1)
        {
            if (A[high] < A[low])
                Swap(A[low], A[high]);
            return;
        }
    }

    mid = (low + high) / 2;
    pivot = A[mid];
    Swap(A[mid], A[low]);
    scanUp = low + 1;
    scanDown = high;

    do
    {
        while (scanUp <= scanDown && A[scanUp] <= pivot)
            scanUp++;
        while (pivot < A[scanDown])
            scanDown--;
        if (scanUp < scanDown)
            Swap(A[scanDown], A[scanUp]);
    }
    while (scanUp < scanDown);

    A[low] = A[scanDown];
    A[scanDown] = pivot;

    if (low < scanDown - 1)
        QuickSort(A, low, scanDown - 1);
    if (scanDown + 1 < high)
        QuickSort(A, scanDown + 1, high);
}


// 很简单的快速排序

// 返回主元（枢轴，pivot）下标，主元左边数组小于主元，主元右边数据大于主元
// low，high为最小最大下标
template <typename T>
int Partition(T A[], int low, int high)
{
    // 将数组的最后一个元素作为主元，来划分数组
    T pivot = A[high];
    // i是数组中最后一个小于主元的元素的下标
    int i = low - 1;
    // 遍历下标由low到high-1的元素
    for(int j = low; j < high; ++j)
    {
        // 如果A[j]小于主元，就将i向前移动一个位置，并交换i，j的元素
        if (A[j] < pivot)
        {
            ++i;
            std::swap(A[i], A[j]);
        }
    }
    // 经过以上循环之后，从下标low到i（包括i）的元素都小于主元，交换i+1和主元
    std::swap(A[i + 1], A[high]);

    return  i + 1;
}

// 快速排序， low，high为数据最小，最大下标
template <typename T>
void QuickSort(T A[], int low, int high)
{
    if (low < high)
    {
        int pivot_pos = Partition(A, low, high);
        QuickSort(A, low, pivot_pos - 1);
        QuickSort(A, pivot_pos + 1, high);
    }

}

#endif // SORT_H_INCLUDED
