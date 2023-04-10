#include <iostream>
#include <string>

using namespace std; 

int main()
{
    int h, w;
    cin >> h >> w;

    for(int i = 0; i < h; i++)
    {
        string s;        
        cin >> s;

        for(int j = 0; j < w - 1; j++)
        {
            if(s[j] == 'T' && s[j+1] == 'T')
            {
                s[j] = 'P'; s[j+1] = 'C';
            }
        }

        cout << s << endl;
    }

    return 0;
}