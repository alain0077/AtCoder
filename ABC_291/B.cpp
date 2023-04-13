#include <iostream>
#include <map>

using namespace std; 

int main()
{
    int n, sum = 0;
    cin >> n;

    for(int i = 0; i < 5 * n; i++)
    {
        int x;
        cin >> x;

        if(i >= n && i <= 5*n - n) sum += x;
    }

    cout << sum 

    return 0;
}