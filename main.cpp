#include <iostream>
#include "solution.h"

using namespace std;
using namespace sol_1245;

/*
Input: edges = [[0,1],[0,2]]
Output: 2
*/

vector<vector<int>> testFixture1()
{
  return {
      {0, 1},
      {0, 2}};
}

/*
Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
Output: 4
*/
vector<vector<int>> testFixture2()
{
  return {
      {0, 1},
      {1, 2},
      {2, 3},
      {1, 4},
      {4, 5}};
}

void test1()
{
  auto fixture = testFixture1();
  Solution sol;
  auto dia = sol.diameter(fixture);
  cout << "Test 1 - expect to see 2" << endl;
  cout << "result: " << dia << endl;
}

void test2()
{
  auto fixture = testFixture2();
  Solution sol;
  auto dia = sol.diameter(fixture);
  cout << "Test 2 - expect to see 4" << endl;
  cout << "result: " << dia << endl;
}

main()
{
  test1();
  test2();
  return 0;
}