

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <list>
using namespace std;
namespace sol_1245
{
    class Solution
    {
    private:
        list<int> *buildTree(vector<vector<int>> edges);
        void dfs(int node, int n, list<int> *tree, int &maxCount, int &x);
        void visit(int node, int count, bool visited[], int &maxCount, list<int> *tree, int &x);

    public:
        int diameter(vector<vector<int>> edges);
    };
}
#endif