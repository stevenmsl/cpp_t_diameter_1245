#include "solution.h"
#include <vector>
#include <list>

using namespace sol_1245;
using namespace std;

/* takeaways
   - the definition of tree diameter is the
     longest path from one leaf node to another
     leaf node

   - if you start from any random node, you can
     reach any leave nodes:
     - a non-leave node must be on one of the
       longest paths.
       - so the farthest leave node it can reach
         must be one of the two leave nodes that
         forms the longest path that it is on
       - pick one longest path and draw it as
         a backbone with other paths (longest or not)
         as branches and you can clearly see it why
         this is the case
     - a leave nodes might not be on the longest path.
       - it's best to pick one of the longest paths
         and draw if as a straight line with other
         nodes that are not on that path as branches
           0
            \
         3-2-1-4-5
       - 0 is not on the longest path, but we will
         travel through it to find either 3 or 5
         when we are looking for the farthest leaf
         node from 0

   - from the farthest leaf node you found find
     the furthest leave node from it you get
     the answer

*/

list<int> *Solution::buildTree(vector<vector<int>> edges)
{

  auto n = edges.size();
  /*
     - ok don't forget to add 1 as the number
       of nodes has one more than the number
       of edges
  */
  list<int> *tree = new list<int>[n + 1];
  for (int i = 0; i < n; i++)
  {
    /*
       - example [0,1]
       - we will create two entries
         - under tree[0] list add 1
           to represent 1 as 0's neighbor
         - we aslo need to add 0 as 1's
           neighbor
    */
    tree[edges[i][0]].push_back(edges[i][1]);
    tree[edges[i][1]].push_back(edges[i][0]);
  }
  return tree;
}

void Solution::visit(int node, int count, bool visited[], int &maxCount, list<int> *tree, int &x)
{
  visited[node] = true;
  count++;
  /* visiting neighbors */
  for (auto i = tree[node].begin(); i != tree[node].end(); i++)
  {
    /*
       - we construct the tree that records 2 is next to 3,
         and 3 is next to 2 if they are adjacent
       - if we are visiting 3 from 2, 2 has been marked
         as visited at that point. Since 3 is a leave node,
         and is not allowed to go back 2, there is nowhere
         to go, we are done exploring this path
    */
    if (!visited[*i])
    {
      /*
        - if it's the fartherest so far, record it
        - x will eventually point to a leave node
      */
      if (count >= maxCount)
      {
        maxCount = count;
        x = *i;
      }
      // dfs
      visit(*i, count, visited, maxCount, tree, x);
    }
  }
}

void Solution::dfs(int node, int n, list<int> *tree, int &maxCount, int &x)
{
  bool visited[n] = {false};
  int count = 0;
  visit(node, count, visited, maxCount, tree, x);
}

int Solution::diameter(vector<vector<int>> edges)
{
  auto tree = buildTree(edges);
  /*
     - the farthest leave can be reached
       starting from a random node
  */
  int x;
  int n = edges.size() + 1;

  int maxCount = -1;

  /*
    - start from any random node to
      find the farthest leave node
      it can reach
  */
  dfs(0, n, tree, maxCount, x);

  /*
    - from that farthest leave node
      find the farthest leave node
      it can reach
  */
  dfs(x, n, tree, maxCount, x);

  return maxCount;
}