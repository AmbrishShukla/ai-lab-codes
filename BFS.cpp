#include <bits/stdc++.h>
using namespace std;

template <typename T>

class graph
{
    map<T, list<T>> m;

public:
    void addEdge(T x, T y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
    }

    void bfs(T src, T goal)
    {
        map<T, bool> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << "->";
            if (node == goal)
            {
                break;
            }
            for (auto nbrs : m[node])
            {
                if (!visited[nbrs])
                {
                    q.push(nbrs);
                    visited[nbrs] = true;
                }
            }
        }
    }
};

int main()
{

    graph<char> g;
    g.addEdge('a', 'b');
    g.addEdge('a', 'c');
    g.addEdge('b', 'd');
    g.addEdge('d', 'e');
    g.addEdge('d', 'f');
    g.addEdge('e', 'g');
    g.addEdge('g', 'h');

    cout << "the path for the goal node is :" << endl;
    g.bfs('a', 'e');

    return 0;
}