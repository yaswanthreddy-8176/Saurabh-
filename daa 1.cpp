#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

// -------- Bubble Sort --------
void bubble(vector<int>& a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int x = a[j];
                a[j] = a[j + 1];
                a[j + 1] = x;
            }
        }
    }
}

// -------- Selection Sort --------
void selection(vector<int>& a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; i++)
    {
        int pos = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[pos])
                pos = j;
        }

        int x = a[i];
        a[i] = a[pos];
        a[pos] = x;
    }
}

// -------- Insertion Sort --------
void insertion(vector<int>& a)
{
    int n = a.size();

    for (int i = 1; i < n; i++)
    {
        int value = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > value)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = value;
    }
}

// -------- Merge Function --------
void mergeArray(vector<int>& a, int left, int mid, int right)
{
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (a[i] < a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(a[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(a[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++)
        a[left + k] = temp[k];
}

// -------- Merge Sort --------
void mergeSort(vector<int>& a, int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);

    mergeArray(a, left, mid, right);
}

// -------- Quick Sort --------
int divide(vector<int>& a, int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && a[i] <= pivot)
            i++;

        while (j >= low && a[j] > pivot)
            j--;

        if (i < j)
        {
            int x = a[i];
            a[i] = a[j];
            a[j] = x;
        }
    }

    a[low] = a[j];
    a[j] = pivot;

    return j;
}

void quickSort(vector<int>& a, int low, int high)
{
    if (low < high)
    {
        int p = divide(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// -------- Main Function --------
int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> data(n);

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
        cin >> data[i];

    vector<int> a;

    // Bubble Sort
    a = data;

    auto start = high_resolution_clock::now();
    bubble(a);
    auto finish = high_resolution_clock::now();

    cout << "\nBubble Sort Time: "
         << duration_cast<microseconds>(finish - start).count()
         << " microseconds";

    // Selection Sort
    a = data;

    start = high_resolution_clock::now();
    selection(a);
    finish = high_resolution_clock::now();

    cout << "\nSelection Sort Time: "
         << duration_cast<microseconds>(finish - start).count()
         << " microseconds";

    // Insertion Sort
    a = data;

    start = high_resolution_clock::now();
    insertion(a);
    finish = high_resolution_clock::now();

    cout << "\nInsertion Sort Time: "
         << duration_cast<microseconds>(finish - start).count()
         << " microseconds";

    // Merge Sort
    a = data;

    start = high_resolution_clock::now();
    mergeSort(a, 0, n - 1);
    finish = high_resolution_clock::now();

    cout << "\nMerge Sort Time: "
         << duration_cast<microseconds>(finish - start).count()
         << " microseconds";

    // Quick Sort
    a = data;

    start = high_resolution_clock::now();
    quickSort(a, 0, n - 1);
    finish = high_resolution_clock::now();

    cout << "\nQuick Sort Time: "
         << duration_cast<microseconds>(finish - start).count()
         << " microseconds\n";

    return 0;
}