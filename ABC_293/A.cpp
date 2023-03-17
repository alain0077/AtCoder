#include <iostream>
#include <string>

using namespace std; 

int main()
{
    string s;

    cin >> s;

    for(int i = 1; i <= s.size() / 2; i++)
    {
        char c = s[2 * i - 2];
        s[2 * i - 2] = s[2 * i - 1];
        s[2 * i - 1] = c;
    }

    cout << s << endl;
}