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

    void dfsHelper(T src, T goal, map<T, bool> &visited)
    {

        visited[src] = true;

        if (src == goal)
        {
            return;
        }

        cout << src << "-> ";

        for (auto nbr : m[src])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, goal, visited);
            }
        }
    }

    void DFS(T src, T goal)
    {
        map<T, bool> visited;
        for (auto p : m)
        {
            T node = p.first;
            visited[node] = false;
        }

        dfsHelper(src, goal, visited);
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

    g.DFS('a', 'e');

    return 0;
}