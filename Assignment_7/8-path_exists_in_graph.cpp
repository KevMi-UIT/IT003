#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    bool check = false;
    int v, e;
    pair<int, int> path;
    pair<int, int> target;
    pair<int, int> target2;
    vector<pair<int, int>> graph;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> path.first >> path.second;
        graph.push_back(path);
    }
    cin >> target.first >> target.second;
    target2.first = target.second;
    target2.second = target.first;
    for (auto path : graph)
    {
        if (target == path || target2 == path)
            check = true;
    }
    cout << check;
    return 0;
}
