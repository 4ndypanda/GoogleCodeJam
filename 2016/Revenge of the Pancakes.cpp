#include <iostream>
#include <string>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    string pancakes;
    cin >> pancakes;
    int flips = pancakes[0] == '-';
    for (int i = 1; i < pancakes.length(); i++) {
      if (pancakes[i] == '-' && pancakes[i - 1] == '+') {
        flips += 2;
      }
    }
    printf("Case #%d: %d\n", t, flips);
  }
  return 0;
}
