#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int bag = 0;
    
    cin >> n;
    int treebag = 0;
    while(n >= 0)
    {
        int divFive = n % 5;
        if (divFive == 0)
        {
            bag += treebag;
            bag += n / 5;
            cout << bag;
            return 0;
        }
        else
        {
           treebag += 1;
           n -= 3;
        }
    }
    if (n < 0)
    {
        cout << -1;
    }
    else
    {
       cout << treebag;
    }
}