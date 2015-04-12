#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Determine if it is possible to consume the pancakes provided within the given
 * number of minutes.
 */
bool possible(vector<int> pancakes, int minutes) {
  for (int special_min = 0; special_min < minutes; special_min++) {
    // Maximum number of pancakes that can be on a diner's plate for the given
    // number of minutes and special minutes taken.
    int max_pancakes = minutes - special_min;

    // Compute the number of special minutes required to ensure all diners'
    // plates contain at most max_pancakes.
    int special_min_required = 0;
    for (int i = 0; i < pancakes.size(); i++)
      special_min_required += (pancakes[i] - 1) / max_pancakes;
    if (special_min_required <= special_min)
      return true;
  }
  return false;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int D;
    cin >> D;

    // Upper bound on number of minutes needed to eat all pancakes.
    int max_minutes = 0;
    vector<int> pancakes;
    for (int i = 0; i < D; i++) {
      int pancake;
      cin >> pancake;
      max_minutes = max(max_minutes, pancake);
      pancakes.push_back(pancake);
    }

    // Binary search the minimum number of minutes required to eat all the
    // pancakes.
    int lower = 1, upper = max_minutes;
    while (lower < upper) {
      int mid = (lower + upper) / 2;
      possible(pancakes, mid) ? upper = mid : lower = mid + 1;
    }
    printf("Case #%d: %d\n", t, lower);
  }
  return 0;
}
