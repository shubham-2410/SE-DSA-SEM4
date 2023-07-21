#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class adjList
{
    int vertices;
    vector<list<int> > v;

public:
    adjList(int n)
    {
        vertices = n;
        v.resize(n);
    }

    void addEdge(int x, int y)
    {
        v[x].push_back(y);
        v[y].push_back(x);
    }

    void displayList()
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << "Vertex " << i << " -> ";
            for (int x : v[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void bfs(int n)
    {
        vector<int> visited(vertices, 0);
        queue<int> q;

        q.push(n);
        visited[n] = 1;

        while (!q.empty())
        {
            int s = q.front();
            q.pop();
            cout << s << " ";
            for (int x : v[s])
            {
                if (visited[x] == 0)
                {
                    visited[x] = 1;
                    q.push(x);
                }
            }
        }
        cout << endl;
    }

    void dfs(int n)
    {
        vector<int> visited(vertices, 0);
        stack<int> st;

        st.push(n);
        visited[n] = 1;

        while (!st.empty())
        {
            int s = st.top();
            st.pop();
            cout << s << " ";

            for (int x : v[s])
            {
                if (visited[x] == 0)
                {
                    visited[x] = 1;
                    st.push(x);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    cout << "Enter number of vertices in graph : ";
    int n;
    cin >> n;

    adjList l(n);

    cout << "Enter number of edges : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << "for Edge " << i + 1 << " : \n";
        cout << "\tEnter First vertex :";
        cin >> x;
        cout << "\tEnter Second vertex :";
        cin >> y;
        l.addEdge(x, y);
    }

    l.displayList();

    cout << "\nEnter stating vertex for BFS and DFS : ";
    cin >> n;

    cout << "----------BFS------------\n";
    l.bfs(n);
    cout << "----------DFS------------\n";
    l.dfs(n);
}