#include <iostream>
#include <queue>
#include <map>

using namespace std;

int t, k, n;
char q;

priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int>> minpq;
map<int, int> cntmp;

void init()
{
    while (!maxpq.empty())
        maxpq.pop();
    while (!minpq.empty())
        minpq.pop();
    cntmp.clear();
    return;
}

void update()
{
    while (!maxpq.empty() && !cntmp[maxpq.top()])
        maxpq.pop();
    while (!minpq.empty() && !cntmp[minpq.top()])
        minpq.pop();
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> k;

        init();

        while (k--)
        {
            cin >> q >> n;
            if (q == 'I')
            {
                maxpq.push(n);
                minpq.push(n);
                cntmp[n]++;
            }
            else if (n == 1)
            {
                if (!maxpq.empty())
                {
                    cntmp[maxpq.top()]--;
                    maxpq.pop();
                }
            }
            else if (n == -1)
            {
                if (!minpq.empty())
                {
                    cntmp[minpq.top()]--;
                    minpq.pop();
                }
            }
            update();
        }

        if (maxpq.empty() || minpq.empty())
            cout << "EMPTY\n";
        else
            cout << maxpq.top() << " " << minpq.top() << "\n";
    }

    return 0;
}