/*
Program: C_Assembly_Mixed_Call (Chapter 13, Pr 5, Modified)
Description: Check if prime number with C and Assembly calling eachother
Student:     Gabriel Warkentin
Date:        05/11/2020
Class:       CSCI 241
Instructor:  Mr. Ding
*/

#include<iostream>

using namespace std;

extern "C" {
    bool isPrimeASM(int n);
    bool isPrimeC(int n);
    int intSqrt(int n);
}

int intSqrt(int n) {
    return sqrt(n);
}

bool isPrimeC(int n)
{
    bool ret = false;

    if (n >= 2)
    {
        int divisor;
        for (divisor = 2; divisor <= n / 2; divisor++)
        {
            if (n % divisor == 0)
                break;
        }

        if (divisor > n / 2)
            ret = true;
    }
    return ret;
}

int main() {
    int N = 0;
    while (true) {
        cout << "Enter an integer (-1 to exit) : ";
        cin >> N;
        if (N == -1) { break; }
        cout << "isPrimeC:    " << N << " is " << (isPrimeC(N) ? "" : "NOT ") << "prime\n";
        cout << "isPrimeASM:  " << N << " is " << (isPrimeASM(N) ? "" : "NOT ") << "prime\n";
    }
}