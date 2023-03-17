#include <iostream>
#include <vector>

using namespace std; 

int main()
{
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;
    
    p--, r--;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for(int i = 0; i < n; i++) {
        if(i == p) {
            for(int j = r; j < s; j++) cout << v[j] << ' ';

            i = q - 1;            
        }
        else if(i == r) {
            for(int j = p; j < q; j++) cout << v[j] << ' ';

            i = s - 1;
        }
        else cout << v[i] << ' ';
    }
}