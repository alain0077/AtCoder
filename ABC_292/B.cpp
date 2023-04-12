#include <iostream>
#include <map>

using namespace std; 

int main()
{
    int n, q;
    cin >> n >> q;

    map<int, int> flag;
    
    for(int i = 0; i < q; i++) 
    {
        int ev, x;
        cin >> ev >> x;

        if(ev == 1)
        {
            flag[x]++;
        }
        
        if(ev == 2)
        {
            flag[x] = 2;
        }

        if(ev == 3)
        {
            if(flag[x] != 2) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }

    return 0;
}