#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

// ---------- MAX HEAPIFY ----------
void maxHeapify(vector<int>& a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        maxHeapify(a, n, largest);
    }
}

// ---------- MAX HEAP SORT ----------
void maxHeapSort(vector<int>& a)
{
    int n = a.size();

    // Create Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(a, n, i);

    // Sorting
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        maxHeapify(a, i, 0);
    }
}

// ---------- MIN HEAPIFY ----------
void minHeapify(vector<int>& a, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] < a[smallest])
        smallest = left;

    if (right < n && a[right] < a[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        minHeapify(a, n, smallest);
    }
}

// ---------- MIN HEAP SORT ----------
void minHeapSort(vector<int>& a)
{
    int n = a.size();

    // Create Min Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(a, n, i);

    // Sorting
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        minHeapify(a, i, 0);
    }

    // Convert descending order to ascending order
    reverse(a.begin(), a.end());
}

// ---------- MAIN ----------
int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> original(n);

    // Enter elements
    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
        cin >> original[i];

    // Make two copies
    vector<int> maxArray = original;
    vector<int> minArray = original;

    // ---------- MAX HEAP SORT ----------
    auto startMax = high_resolution_clock::now();

    maxHeapSort(maxArray);

    auto endMax = high_resolution_clock::now();

    // ---------- MIN HEAP SORT ----------
    auto startMin = high_resolution_clock::now();

    minHeapSort(minArray);

    auto endMin = high_resolution_clock::now();

    // Calculate time
    auto maxTime =
        duration_cast<microseconds>(endMax - startMax);

    auto minTime =
        duration_cast<microseconds>(endMin - startMin);

    // ---------- DISPLAY ----------
    cout << "\nMax Heap Sort Result: ";

    for (int x : maxArray)
        cout << x << " ";

    cout << "\nTime: " << maxTime.count()
         << " microseconds\n";

    cout << "\nMin Heap Sort Result: ";

    for (int x : minArray)
        cout << x << " ";

    cout << "\nTime: " << minTime.count()
         << " microseconds\n";

    return 0;
}