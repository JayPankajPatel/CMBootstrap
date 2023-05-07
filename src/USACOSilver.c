#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef char* string;
typedef long long int ll;
typedef struct Pair {

  ll first;
  ll second;
} Pair;

// https://usaco.guide/general/input-output?lang=cpp
void setIO(string sin, string sout) {

  freopen(sin, "r", stdin);
  freopen(sout, "w", stdout);
}

int sort_pair_by_second(const void *pair1, const void *pair2) {

  const Pair *elem1 = (const Pair *)pair1;
  const Pair *elem2 = (const Pair *)pair2;

  if (elem1->first > elem2->first)
    return 1;

  if (elem1->first < elem2->first)
    return -1;

  return 0;
}

void sort(Pair *arr, size_t size, size_t width,
          int (*compare)(const void *, const void *)) {

  qsort((void *)arr, size, width, compare);
}

bool check(Pair *interval, ll N, ll M, ll D) {

  // setting where cows can start being placed in pos
  // i keeps track of which interval we are in
  ll pos = 0;
  int cows_placed = 0;
  int i = 0;

  while (cows_placed < N) {
    // this check is to make sure we are in an interval
    // if we aren't we set it to the next valid interval's start
    if (pos <= interval[i].first) {

      pos = interval[i].first;
    }
    // we can only place cows inside a valid interval
    // place a cow and move a the distance we are checking
    // in the binary search function
    if (((interval[i].first) <= (pos)) && ((pos) <= interval[i].second)) {
      cows_placed++;
      pos += D;

    }

    // we are outside a valid interval, we will start
    // putting cows in the next interval
    else {
      i++;
    }
    // checking if we have run out of space to place cows
    if (i >= M) {

      return false;
    }
  }

  // if we get here, all cows were placed and the inputted D
  // is a valid distance to place the cows
  return true;
}

ll binary_search(Pair *interval, ll N, ll M) {
  // setting up the min and max possible values given an input
  ll left = 0;
  ll right = interval[M - 1].second;
  ll pos_sol = 0;

  while (left <= right) {

    ll mid = left + (right - left) / 2;

    bool is_valid = check(interval, N, M, mid);
    // if this is true, we found a valid answer,
    // however we continue doing binary search
    // until we find the greatest valid answer
    // which is stored in pos_sol
    if (is_valid) {

      pos_sol = mid;
      left = mid + 1;
    }

    else {

      right = mid - 1;
    }
  }

  return pos_sol;
}

int main(void) {

  // changing stdin and stdout to respective
  // input and output files
  setIO("socdist.in", "socdist.out");
  ll N, M;

  // First line inputs are N and M where N is the number of cows
  // And M is the number of Mutually Disjoint Sets
  scanf("%lli", &N);
  scanf("%lli", &M);

  // allocating memory for intervals
  Pair *interval = malloc(sizeof(Pair) * M);

  // Reading the intervals described as a and b in the problem
  for (size_t i = 0; i < M; i++) {

    scanf("%lli", &interval[i].first);
    scanf("%lli", &interval[i].second);
  }

  // sorting in order to check D distance using binary_search
  sort(interval, M, sizeof(Pair), sort_pair_by_second);

  ll left = binary_search(interval, N, M);

  // output answer to file
  printf("%lli\n", left);

  // free memory allocated
  free(interval);
}
