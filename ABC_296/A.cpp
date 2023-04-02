#include <iostream>
#include <string>

using namespace std; 

int main()
{
    int n;
    string s;

    cin >> n;
    cin >> s;

    for(int i = 1; i < n; i++)
    {
        if(s[i] == s[i-1])
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}