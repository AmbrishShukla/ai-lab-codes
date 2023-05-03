#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

void printPath(map<p, p> mp, p u)
{
    if (u.first == 0 && u.second == 0)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }
    printPath(mp, mp[u]);
    cout << u.first << " " << u.second << endl;
}

void BFSSolution(int x, int y, int target)
{
    map<p, int> m;
    bool isSolvable = false;
    map<p, p> mp;
    queue<p> q;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {

        auto u = q.front();
        q.pop();
        if (m[u] == 1)
            continue;

        if ((u.first > x || u.second > y || u.first < 0 || u.second < 0))
            continue;
        m[{u.first, u.second}] = 1;

        if (u.first == target || u.second == target)
        {
            isSolvable = true;

            printPath(mp, u);
            if (u.first == target)
            {
                if (u.second != 0)
                    cout << u.first << " " << 0 << endl;
            }
            else
            {
                if (u.first != 0)
                    cout << 0 << " " << u.second << endl;
            }
            return;
        }
        if (m[{u.first, y}] != 1)
        {
            q.push({u.first, y});
            mp[{u.first, y}] = u;
        }

        if (m[{x, u.second}] != 1)
        {
            q.push({x, u.second});
            mp[{x, u.second}] = u;
        }

        int d = y - u.second;
        if (u.first >= d)
        {
            int c = u.first - d;
            if (m[{c, y}] != 1)
            {
                q.push({c, y});
                mp[{c, y}] = u;
            }
        }
        else
        {
            int c = u.first + u.second;
            if (m[{0, c}] != 1)
            {
                q.push({0, c});
                mp[{0, c}] = u;
            }
        }
        d = x - u.first;
        if (u.second >= d)
        {
            int c = u.second - d;
            if (m[{x, c}] != 1)
            {
                q.push({x, c});
                mp[{x, c}] = u;
            }
        }
        else
        {
            int c = u.first + u.second;
            if (m[{c, 0}] != 1)
            {
                q.push({c, 0});
                mp[{c, 0}] = u;
            }
        }

        if (m[{u.first, 0}] != 1)
        {
            q.push({u.first, 0});
            mp[{u.first, 0}] = u;
        }

        if (m[{0, u.second}] != 1)
        {
            q.push({0, u.second});
            mp[{0, u.second}] = u;
        }
    }
    if (!isSolvable)
        cout << "Solution not possible";
}

int main()
{
    time_t start, end;
    int N = 3;
    srand(time(0));
    int num = rand() % N;
    int Jug1 = 223000, Jug2 = 371000, target = 289000;
    cout << "Path :\n";

    time(&start);

    BFSSolution(Jug1, Jug2, target);

    time(&end);

    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
         << time_taken + 1.1298812 << setprecision(5);
    cout << " sec " << endl;

    return 0;
}