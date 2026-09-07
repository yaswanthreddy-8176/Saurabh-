#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// Iterative Factorial
unsigned long long iterativeFactorial(int num)
{
    unsigned long long fact = 1;

    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive Factorial
unsigned long long recursiveFactorial(int num)
{
    if (num == 0 || num == 1)
        return 1;

    return num * recursiveFactorial(num - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Please enter a positive number.";
        return 0;
    }

    // Iterative Method
    auto start1 = high_resolution_clock::now();

    unsigned long long answer1 = iterativeFactorial(n);

    auto end1 = high_resolution_clock::now();

    auto time1 = duration_cast<nanoseconds>(end1 - start1);

    // Recursive Method
    auto start2 = high_resolution_clock::now();

    unsigned long long answer2 = recursiveFactorial(n);

    auto end2 = high_resolution_clock::now();

    auto time2 = duration_cast<nanoseconds>(end2 - start2);

    // Display Results
    cout << "\n========== RESULT ==========\n";

    cout << "Factorial of " << n << ":\n";

    cout << "\nIterative Method";
    cout << "\nResult : " << answer1;
    cout << "\nTime   : " << time1.count() << " ns";

    cout << "\n\nRecursive Method";
    cout << "\nResult : " << answer2;
    cout << "\nTime   : " << time2.count() << " ns\n";

    return 0;
}