#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<iostream>

using namespace std;

int partition(int *a, int from, int to) {
  int pivot = from + rand() % (to - from + 1);
  swap(a[from], a[pivot]);
  int l = from + 1, r = to, pivotCorrectIdx = from;
  while (l <= r) {
    if (a[l] > a[from]) {
	swap(a[l], a[r]);
	--r;
    }
    else {
	++l;
	pivotCorrectIdx++;
    }
  }
  swap(a[from], a[pivotCorrectIdx]);
  return pivotCorrectIdx;
}

void quicksort(int *a, int from, int to) {
  if (to > from) {
    int idx = partition(a, from, to);
    quicksort(a, from, idx - 1);
    quicksort(a, idx + 1, to);
  }
}
int main() {
  int n, a[100005];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  quicksort(a, 0, n - 1);
  printf("%d", a[0]);
  for (int i = 1; i < n; ++i) {
    printf(" %d", a[i]);
  }
  printf("\n");
}