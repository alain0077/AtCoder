#include <iostream>
#include <iomanip>

using namespace std; 

int main()
{
    int n;
    cin >> n;

    cout << setfill('0') << setw(2) << uppercase << hex << n; 
}