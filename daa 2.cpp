#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// Linear Search
int linearSearch(vector<int> a, int x)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == x)
            return i;
    }

    return -1;
}

// Binary Search
int binarySearch(vector<int> a, int x)
{
    int low = 0;
    int high = a.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == x)
            return mid;

        if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter sorted elements: ";

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to search: ";
    cin >> x;

    // Linear Search
    auto start1 = high_resolution_clock::now();

    int result1 = linearSearch(a, x);

    auto end1 = high_resolution_clock::now();

    // Binary Search
    auto start2 = high_resolution_clock::now();

    int result2 = binarySearch(a, x);

    auto end2 = high_resolution_clock::now();

    // Linear Search Output
    cout << "\n--- Linear Search ---\n";

    if (result1 != -1)
        cout << "Found at index: " << result1 << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time: "
         << duration_cast<microseconds>(end1 - start1).count()
         << " microseconds\n";

    // Binary Search Output
    cout << "\n--- Binary Search ---\n";

    if (result2 != -1)
        cout << "Found at index: " << result2 << endl;
    else
        cout << "Element not found" << endl;

    cout << "Time: "
         << duration_cast<microseconds>(end2 - start2).count()
         << " microseconds\n";

    return 0;
}