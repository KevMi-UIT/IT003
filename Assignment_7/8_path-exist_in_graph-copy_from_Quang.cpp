#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void EnterEdgeList(vector<pair<int, int>> &edgeList, int soDinh, int soCanh)
{
    int u, v;
    for (int i = 0; i < soCanh; i++)
    {
        cin >> u >> v;
        edgeList.push_back({u, v});
    }
}

vector<int> AList[1000];
bool visited[1000] = {0};
void ELToAdjacencyList(vector<pair<int, int>> edgeList, int soDinh, int soCanh)
{
    for (int i = 0; i < soCanh; i++)
    {
        AList[edgeList[i].first].push_back(edgeList[i].second);
        AList[edgeList[i].second].push_back(edgeList[i].first);
    }
}

void DFS(int u)
{
    visited[u] = true;
    for (int i = 0; i < AList[u].size(); i++)
    {
        int v = AList[u][i];
        if (visited[v] == false)
        {
            DFS(v);
        }
    }
}

int CheckPathExisted(vector<pair<int, int>> edgeList, const int soDinh, const int soCanh)
{
    int a, b;
    cin >> a >> b;
    ELToAdjacencyList(edgeList, soDinh, soCanh);
    DFS(a);
    if (visited[a] && visited[b])
        return 1;
    return 0;
}

int main()
{
    int soDinh, soCanh;
    cin >> soDinh >> soCanh;
    vector<pair<int, int>> edgeList;
    EnterEdgeList(edgeList, soDinh, soCanh);
    cout << CheckPathExisted(edgeList, soDinh, soCanh);
}
