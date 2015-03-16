#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

void pushDown(int *a, int idx , int n) {
  int l = 2 * idx + 1, r = 2 * idx + 2;
  while (l < n) {
    int best = idx;
    if (a[best] < a[l]) best = l;
    if (r < n && a[best] < a[r]) best = r;
    if (best == idx) break;
    swap(a[idx], a[best]);
    idx = best;
    l = 2 * idx + 1;
    r = 2 * idx + 2;
  }
}

void buildHeap(int *a, int n) {
  for (int i = (n / 2) - 1; i >= 0; --i) {
    pushDown(a, i, n);
  }
}

void heapsort(int *a, int n) {
  buildHeap(a, n);
  while (n) {
    swap(a[0], a[n - 1]);
    --n;
    pushDown(a, 0, n);
  }
}
/*
int main() {
  int n, a[100005];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  heapsort(a, n);
  printf("%d", a[0]);
  for (auto i = 1; i < n; ++i) {
    printf(" %d", a[i]);
  }
  printf("\n");
}*/