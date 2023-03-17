#include <iostream>
#include <vector>

using namespace std; 

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    vector<bool> f(n, false);
    
    for(int i = 0; i < n; i++) 
    {
        cin >> v[i];
    }

    for(int i = 0; i < n; i++)
    { 
        if(!f[i]) f[v[i] - 1] = true;
    }

    int k = 0;

    for(int i = 0; i < n; i++)
    { 
        if(!f[i]) k++;
    }

    cout << k << endl;
    
    for(int i = 0; i < n; i++)
    { 
        if(!f[i]) cout << i + 1 << " ";
    }

    cout << endl;

    return 0;
}