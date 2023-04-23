#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std; 

int main()
{
    int n;
    double sum = 0;
    cin >> n;

    vector<int> x(5*n);

    for(int i = 0; i < 5 * n; i++)
    {
        cin >> x[i];   
    }

    sort(x.begin(), x.end());

    for(int i = n; i < 5*n - n; i++)
    {
        sum += x[i];
    }

    double avg = sum / (double)(3*n);

    cout << setprecision(6) << avg << endl;

    return 0;
}