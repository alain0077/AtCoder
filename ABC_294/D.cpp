#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main()
{
    int n, q, call = 0;
    cin >> n >> q;

    vector<bool> called(n, false);

    for(int i = 0; i < q; i++)
    {
        int event;
        cin >> event;

        if(event == 1) {
            continue;
        }
        else if(event == 2)
        {
            int x;
            cin >> x;
            called[x-1] = true;
        }
        else
        {
            while(called[call]) call++;
            cout << call + 1 << endl;
        }
    }

    return 0;
}