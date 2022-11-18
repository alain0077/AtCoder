#include <iostream>

using namespace std; 

int func(int n)
{
    if(!n) return 1;
    else return n * func(n-1);
}

int main()
{
    int n;
    cin >> n;

    cout << func(n) << endl; 
}