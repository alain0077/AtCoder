#include <iostream>

using namespace std;

int main()
{
    string a, b, c;
    cin >> a >> b >> c;

    char now = 'a';

    while (1)
    {
        if (now == 'a') { 
            if (!a.size()) {
                cout << 'A' << endl;
                break;
            }
            now = a[0];
            a.erase(0, 1);
        }
        else if (now == 'b') {
            if (!b.size()) {
                cout << 'B' << endl;
                break;
            }
            now = b[0];
            b.erase(0, 1);
        }
        else if (now == 'c') {
            if (!c.size()) {
                cout << 'C' << endl;
                break;
            }
            now = c[0];
            c.erase(0, 1);
        }
    }
}