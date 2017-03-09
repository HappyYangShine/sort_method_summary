#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

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
void QuickSort(T A[], int low, int high)
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


#endif // SORT_H_INCLUDED
