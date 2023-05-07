#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a > b) ? (a : b))

typedef char *string;
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

  ll pos = interval[0].first;
  int cows_placed = 0;
  int i = 0;

  while (cows_placed < N) {

    if (pos <= interval[i].first) {

      pos = interval[i].first;
    }

    if (((interval[i].first) <= (pos)) && ((pos) <= interval[i].second)) {
      cows_placed++;
      pos += D;

    }

    else {
      i++;
    }

    if(i >= M) {

        return false; 
    }
  }

  return true;
}
ll binary_search(Pair *interval, ll N, ll M) {

  ll left = 0;
  ll right = interval[M - 1].second;
  ll pos_sol = 0;

  while (left <= right) {

    ll mid = left + (right - left) / 2;

    bool is_valid = check(interval, N, M, mid);

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

  setIO("socdist.in", "socdist.out"); // changing stdin and stdout to respective
                                      // input and output files
  ll N, M;
  scanf("%lli", &N); // First is N and M where N is the number of cows
  scanf("%lli", &M); // And M is the number of Mutually Disjoint Sets given

  Pair *interval = malloc(sizeof(Pair) * M);

  // Reading the intervals described as a and b in the problem

  for (size_t i = 0; i < M; i++) {

    scanf("%lli", &interval[i].first);
    scanf("%lli", &interval[i].second);
  }

  sort(interval, M, sizeof(Pair), sort_pair_by_second);

  ll left = binary_search(interval, N, M);

  printf("%lli\n", left);

  free(interval);
}
