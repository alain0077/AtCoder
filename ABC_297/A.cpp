#include <iostream>

using namespace std; 

int main()
{
    int n, d;
    int t1, t2;

    cin >> n >> d;

    cin >> t1;

    for(int i = 1; i < n; i++)
    {
        cin >> t2;

        if(t2 - t1 <= d)
        {
            cout << t2 << endl;
            return 0;
        }

        t1 = t2;
    }

    cout << -1 << endl;

    return 0;
}