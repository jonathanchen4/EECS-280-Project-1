// stats.cpp
#include "stats.hpp"
#include <cassert>
#include <vector>
#include <algorithm> // sort
#include <cmath>     // sqrt, modf

using namespace std;

int count(vector<double> v)
{
  return v.size();
}

double sum(vector<double> v)
{
  double total = 0.0;
  for (double x : v)
  {
    total += x;
  }
  return total;
}

double mean(vector<double> v)
{
  if (v.empty())
  {
    return 0.0;
  }
  return sum(v) / count(v);
}

double median(vector<double> v)
{
  vector<double> s = v;
  sort(s.begin(), s.end());
  int n = s.size();

  if (n % 2 == 0)
  {
    return (s[(n / 2) - 1] + s[count(v) / 2]) / 2;
  }
  else
  {
    return s[n / 2];
  }
}

double min(vector<double> v)
{
  vector<double> s = v;
  sort(s.begin(), s.end());
  return s[0];
}

double max(vector<double> v)
{
  int n = v.size();
  vector<double> s = v;
  sort(s.begin(), s.end());
  return s[n - 1];
}

double stdev(vector<double> v)
{
  double x_bar = mean(v);
  double sum = 0.0;

  for (double x : v)
  {
    double sub = x - x_bar;
    sum += sub * sub;
  }

  return sqrt(sum / (v.size() - 1));
}

double percentile(vector<double> v, double p)
{
  sort(v.begin(), v.end());

  int n = static_cast<int>(v.size());
  double rank = p * (n - 1) + 1;
  double k_d = 0.0;
  double d = modf(rank, &k_d);
  int k = static_cast<int>(k_d);

  if (k == n)
  {
    return v[n - 1];
  }

  return v[k - 1] + d * (v[k] - v[k - 1]);
}

vector<double> filter(vector<double> v,
                      vector<double> criteria,
                      double target)
{
  vector<double> result;

  for (int i = 0; i < v.size(); i++)
  {
    if (criteria[i] == target)
    {
      result.push_back(v[i]);
    }
  }
  return result;
}
