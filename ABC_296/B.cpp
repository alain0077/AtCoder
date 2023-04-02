#include <iostream>
#include <string>

using namespace std; 

const int N = 8;
const char row[8] = {'8', '7', '6', '5', '4', '3', '2', '1'};
const char col[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

int main()
{
    string s;
    
    for(int i = 0; i < N; i++)
    {
        cin >> s;

        for(int j = 0; j < N; j++)
        {
            if(s[j] == '*')
            { 
                cout << col[j] << row[i] << endl;
            }
        }
    }

    return 0;
}