#include <iostream>
#include <sstream>
#include <string>

using namespace std; 

int main()
{
    int n;
    string s;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> s;

        if(s == "and" || s == "not" || s == "that" || s == "the" || s == "you")
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    
    return 0;
}