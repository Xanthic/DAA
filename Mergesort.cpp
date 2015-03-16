#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<iostream>

void merge(int *a, int from, int mid, int to) {
  int ptr = from;
  int *b = new int[mid - from];
  int *c = new int[to - mid];
  for (int i = 0; i < mid - from; ++i) {
    b[i] = a[from + i];
  }
  for (int i = 0; i < to - mid; ++i) {
    c[i] = a[mid + i];
  }
  int k = 0, j = 0;
  while (k < mid - from && j < to - mid) {
    if (b[k] < c[j]) a[ptr] = b[k++];
    else {
	a[ptr] = c[j++];
    }
    ++ptr;
  }
  while (k < mid - from) a[ptr++] = b[k++];
  while (j < to - mid) a[ptr++] = c[j++];
  delete[] b;
  delete[] c;
}
void mergesort(int *a,int from, int to) {
  if (to - from <= 1) return;
  int mid = (from + to) / 2;
  mergesort(a, from, mid);
  mergesort(a, mid, to);
  merge(a, from, mid, to);
}
/*
int main() {
  int n, a[2000002];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  mergesort(a, 0, n);
  printf("%lld\n", inv);
}
*/