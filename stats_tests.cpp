/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Statistics Project
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */

#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

void test_sum_small_data_set();
void test_count();
void test_sum();
void test_mean();
void test_median();
void test_min();
void test_max();
void test_stdev();
void test_percentile();
void test_filter();

// Add prototypes for you test functions here.

int main()
{

  test_sum_small_data_set();
  test_count();
  test_sum();
  test_mean();
  test_median();
  test_min();
  test_max();
  test_stdev();
  test_percentile();
  test_filter();
  return 0;
}

void test_sum_small_data_set()
{
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;
}

void test_count()
{
  vector<double> v1 = {1.0, 2.0, 3.0};
  assert(count(v1) == 3);

  vector<double> v2 = {};
  assert(count(v2) == 0);
}

void test_sum()
{
  vector<double> v1 = {3.3, 5.5, 8.8, 10.0};
  assert(sum(v1) == 27.6);

  vector<double> v2 = {0.0, 5.8, 6.7};
  assert(sum(v2) == 12.5);
}

void test_mean()
{
  vector<double> v1 = {5.0, 6.0, 7.0, 8.0};
  assert(mean(v1) == 6.75);

  vector<double> v2 = {10.0, 20.0, 30.0, 40.0};
  assert(mean(v2) == 25.0);
}

void test_median()
{
  vector<double> v1 = {1.0, 2.0, 3.0, 4.0, 5.0};
  assert(median(v1) == 3.0);

  vector<double> v2 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  assert(median(v2) == 3.5);
}

void test_min()
{
  vector<double> v1 = {1.0, 3.0, 5.0, 7.0, 9.0};
  assert(min(v1) == 1.0);

  vector<double> v2 = {6.0, 2.5, 7.8, 1.3, 7.21};
  assert(min(v2) == 1.3);
}

void test_max()
{
  vector<double> v1 = {1.0, 3.0, 5.0, 7.0, 9.0};
  assert(max(v1) == 9.0);

  vector<double> v2 = {6.0, 2.5, 7.8, 1.3, 7.21};
  assert(max(v2) == 7.8);
}

void test_stdev()
{
  const double EPSILON = 1e-6;

  vector<double> v1 = {1.0, 2.0, 3.0};
  double actual = stdev(v1);
  assert(abs(actual - 1.0) < EPSILON);

  vector<double> v = {2.0, 4.0, 4.0, 4.0, 5.0, 5.0, 7.0, 9.0};
  double actual2 = stdev(v);
  double expected2 = std::sqrt(32.0 / 7.0);
  assert(abs(actual2 - expected2) < EPSILON);

  vector<double> v3 = {5.0, 5.0, 5.0, 5.0};
  double actual3 = stdev(v3);
  assert(abs(actual3 - 0.0) < EPSILON);
}

void test_percentile()
{
  vector<double> v1 = {1.0, 3.0, 5.0, 7.0, 9.0};
  assert(percentile(v1, 0.5) == 5.0);

  vector<double> v2 = {10.0, 20.0, 30.0, 40.0};
  assert(percentile(v2, 0.25) == 17.5);

  vector<double> v3 = {4.0, 1.0, 9.0, 6.0};
  assert(percentile(v3, 1.0) == 9.0);
}

void test_filter()
{
  vector<double> v = {15.5, 23.1, 7.8, 19.2, 22.6, 4.6, 1.9, 14.3, 18.0};
  vector<double> criteria = {0, 1, 0, 1, 1, 2, 2, 0, 1};
  vector<double> out = filter(v, criteria, 1);
  vector<double> expected = {23.1, 19.2, 22.6, 18.0};
  assert(out == expected);

  vector<double> v1 = {1.0, 2.0, 3.0};
  vector<double> criteria1 = {0.0, 0.0, 0.0};
  vector<double> out1 = filter(v1, criteria1, 5.0);
  assert(out1.empty());

  vector<double> v2 = {10.0, 20.0, 30.0, 40.0};
  vector<double> criteria2 = {2.0, 1.0, 2.0, 2.0};
  vector<double> out2 = filter(v2, criteria2, 2.0);
  vector<double> expected1 = {10.0, 30.0, 40.0};
  assert(out2 == expected1);
}
