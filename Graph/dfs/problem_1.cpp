#include <cstdio>
#include <vector>
#include <list>

struct vertex
{
    std::vector<int> arr { };
    int idx { 0 };
};

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    std::vector<vertex> graph(n + 1); // + 1 is because vertices start from 1
    std::vector<bool> isVisited(n + 1, false);
    
    // read the graph
    for (int i = 0, u, v; i < m; ++i)
    {
        scanf("%d %d", &u, &v);
        graph[u].arr.push_back(v);
        graph[v].arr.push_back(u);
    }
    
    // traverse all the vertices starting from the vertex v
    int v;
    scanf("%d", &v);
    std::list<int> stack(1, v);
    std::vector<int> result;
    
    // mark root vertex as visited
    isVisited[v] = true;
    while (stack.size())
    {
        auto v = stack.back();
        result.push_back(v);
        
        // take vertex from the stack and check if there is an edge
        // with a vertex that has not been visited yet
        // if yes, push it in the stack and do the same
        // else, if there are no unvisited vertices, in the stack we will have the same
        // vertex at the end of the cycle, that means this vertex has been traversed
        // completely and can be poped from the stack
        
        auto&& u = graph[v];
        while (u.idx < u.arr.size())
        {
            if (!isVisited[u.arr[u.idx]])
            {
                stack.push_back(u.arr[u.idx]);
                isVisited[stack.back()] = true;
                ++u.idx;
                break;
            }
            else
                ++u.idx;
        }
        
        if (stack.back() == v)
            stack.pop_back();
    }
    
    // print result
    printf("%lld\n", result.size());
    for (auto v : result)
        printf("%d ", v);
    
    return 0;
}

// 2-method

#include <bits/stdc++.h>
using namespace std;
long long n, i, j, us[111],  l, r, m, z, d;
char a[111][111];
vector<long long> g[101010], ans;
void dfs(long long from)
{
    us[from] = 1;
    for(int i = 0;i < g[from].size();i++) {
        int to = g[from][i];
        if(us[to] == 0) {
            ans.push_back(to);
            dfs(to);
            ans.push_back(from);
        }
    }

}
int main(){
    cin >> n >> m;
    for(i = 1; i <= m; ++i)
    {
        cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l);
    }
    cin>>z;
ans.push_back(z);
    dfs(z);
    cout<<ans.size()<<'\n';
    for(i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';


}