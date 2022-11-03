#include <deque>
#include <iostream>
#include <stdlib.h>
using namespace std;
#define QUEUE_SIZE 5
#define POLICY 'F'

// typedef struct qlog {
//   int address;
//   bool hit;
// };
deque<int> q;
int replaceQ(int needle) {
  int replaced = 0;
  std::deque<int>::iterator it = q.begin();
  if (q.size() < QUEUE_SIZE) {
    q.push_back(needle);
    return -1;
  } else {
    if (POLICY == 'F') {
      replaced = q.front();
      q.pop_front();
      q.push_back(needle);
    } else if (POLICY == 'R') {
      srand((unsigned)time(NULL));

      // Get a random number
      int random = rand() % q.size();
      replaced = q[random];
      // printf("SIZE = %d V = %d ", q.size(), q[random]);
      q.erase(q.begin() + random);
      // q.pop_front();
      // std::deque<int>::iterator it = ;
      q.insert(q.begin(), random, needle);
    }

    return replaced;
    // replace
  }
}
int accessQ(int needle) {
  deque<int>::iterator it;
  bool found = false;
  for (it = q.begin(); it != q.end(); ++it) {
    if (*it == needle) {
      found = true;
      return 0;
    }
  }

  if (!found) {
    // printf("X");
    return replaceQ(needle);

    // replace
  }
  return 0;
}

int main() {
  deque<int> q;
  int noHits = 0;

  int addresses[] = {2, 2, 3, 1, 4, 2, 4, 3, 3, 4, 2, 5};
  int len = sizeof(addresses) / sizeof(int);
  int currentAddress;
  for (int i = 0; i < len; i++) {
    currentAddress = addresses[i];

    int res = accessQ(currentAddress);

    if (res == 0) {
      noHits++;
    }
    printf("Access: %3d  - %6s , Replaced: %d , HITS: %d, MISS: %d \n",
           currentAddress, res == 0 ? "HIT" : "MISS", res, noHits,
           len - noHits);
  }

  printf("FINALSTATS hits %d   misses %d   hitrate %.2f \n", noHits,
         len - noHits,
         (100.0 * float(noHits)) / (float(noHits) + float(len - noHits)));

  // printf("%d-%s", len, POLICY);
  return 0;
}