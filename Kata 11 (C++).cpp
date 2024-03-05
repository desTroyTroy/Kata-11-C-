// Kata 11 (C++).cpp : This file contains the 'main' function. Program execution begins and ends there.
// This function takes a lower and upper bound, and if a number in that range has a sum of squared divisors
// that equal a perfect square, the number and the sum of its divisors are pushed onto a vector
// as a pair.  The vector is returned after the entire range is evaluated.

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;

class SumSquaredDivisors
{
public:
    static vector<pair<long long, long long>> listSquared(long long m, long long n);
};

vector<pair<long long, long long>> SumSquaredDivisors::listSquared(long long m, long long n) {
    // Upper & lower bounds
    long long lower = m;
    long long upper = n;
    // Declare vector of pairs variable
    vector<pair<long long, long long>> squared;
    // Declare pairs variable
    pair<long long, long long> sq;

    // Iterate through the range from "m" to "n"
    for (long long i = lower; i <= upper; i++) {
        // Temporary container for divisors of number "i" in range m through n
        set<long long> divisors;
        // Automatically insert 1 and the number itself as divisors
        divisors.insert(1);
        divisors.insert(i*i);
     
        // Range of divisors to check is from 2 to square root of number "i"
        long long highestDiv = floor(sqrt(i));
        for (long long j = 2; j <= highestDiv; j++) {
            // If number "j" divides evenly into number "i", it's a divisor
            if (i % j == 0) {
                // Insert pair of divisors squared
                divisors.insert(j*j);
                divisors.insert(pow(i / j, 2));
            }
        }
        // Sum of the squares of the divisors
        long long sum = accumulate(divisors.begin(), divisors.end(), 0);

        // Checks if sum is a perfect square, only then does it record
        // the sum of the squares of the divisors of the current number.
        if(!remainder((double)sum, sqrt(sum))) {
            // Assign pair first & second value, then push onto vector
            sq.first = i;
            sq.second = sum;
            squared.push_back(sq);
        }
    }
    return squared;
}


int main()
{
    vector<pair<long long, long long>> ls = SumSquaredDivisors::listSquared(5801, 9973);
    for (auto i : ls)
        cout << "{" << i.first << ", " << i.second << "}" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

