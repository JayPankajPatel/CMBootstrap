#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX(a, b) ((a > b) ? (a : b))

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

int sort_pair_by_second(const void* pair1, const void* pair2){

  const Pair* elem1 = (const Pair*)pair1; 
  const Pair* elem2 = (const Pair*)pair2;

  if(elem1->second > elem2->second)
    return 1;
  
  if(elem1->second < elem2->second)
    return -1;

  return 0; 

}
bool check(){

  return true; 
}
ll binary_search(Pair* interval, size_t M){

  ll high = interval[M-1].second - interval[0].first + 1; 
  ll low = 0;

  while(low < high) {

    ll mid = (low + high) / 2; 
    
    if(check())
      low = mid + 1;
    
    else
      high = mid - 1;
 
    
  
  }
  
  
  return 0; 
  

}
int main(void){

  setIO("input.in", "output.out"); 
  ll N, M; 
  scanf("%lli", &N); // First is N and M where N is the number of cows
  scanf("%lli", &M); // And M is the number of Mutually Disjoint Sets given
  
  Pair* interval = malloc(sizeof(Pair) * M); 

  // Reading the intervals described as a and b in the problem

  for(size_t i = 0; i < M; i++) { 
    
    scanf("%lli", &interval[i].first); 
    scanf("%lli", &interval[i].second); 
  }







  free(interval); 


}
