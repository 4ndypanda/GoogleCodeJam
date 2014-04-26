#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INF 1000000000

string get_switches(string flow, string required_flow)
{
  string switches = "";
  for (int i = 0; i < flow.length(); i++)
    switches += flow[i] == required_flow[i] ? "0" : "1";
  return switches;
}

int count_ones(string flow)
{
  int cnt = 0;
  for (int i = 0; i < flow.length(); i++)
    cnt += flow[i] == '1';
  return cnt;
}

char flip_bit(char b)
{
  return b == '0' ? '1' : '0';
}

string apply_switch(string switch_to_apply, string flow)
{
  string result = "";
  for (int i = 0; i < switch_to_apply.length(); i++)
    result += switch_to_apply[i] == '1' ? flip_bit(flow[i]) : flow[i];
  return result;
}

bool equal(vector<string> a, vector<string> b)
{
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < a.size(); i++)
    if (a[i] != b[i])
      return false;
  return true;
}

int solve(const vector<string>& initial_flows, const vector<string>& required_flows)
{
  vector<string> switches;
  for (int i = 0; i < initial_flows.size(); i++)
    switches.push_back(get_switches(initial_flows[0], required_flows[i]));
  
  int min_switches = INF;
  for (int i = 0; i < switches.size(); i++)
  {
    vector<string> resulting_flows;
    for (int j = 0; j < initial_flows.size(); j++)
      resulting_flows.push_back(apply_switch(switches[i], initial_flows[j]));
    if (equal(resulting_flows, required_flows))
      min_switches = min(min_switches, count_ones(switches[i]));
  }
  return min_switches == INF ? -1 : min_switches;
}

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    int N, L;
    cin >> N >> L;
    vector<string> initial_flows(N), required_flows(N);
    for (int i = 0; i < N; i++)
      cin >> initial_flows[i];
    for (int i = 0; i < N; i++)
      cin >> required_flows[i];
    int min_switches = solve(initial_flows, required_flows);
    printf("Case #%d: ", t);
    if (min_switches == -1)
      printf("NOT POSSIBLE\n");
    else
      printf("%d\n", min_switches);
  }
  return 0;
}