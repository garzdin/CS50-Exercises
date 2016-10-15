#include <stdio.h>
#include <stdlib.h>

void sort(int values[], int n);
void merge(int values[], int A[], int n_left, int B[], int n_right);

int main(void)
{
  int values[21] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1};
  int n = sizeof(values) / sizeof(values[0]);
  sort(values, n);
  for(int i = 0; i < n; i++)
  {
    printf("%d ", values[i]);
  }
  printf("\n");
  return 0;
}

void merge(int values[], int A[], int n_left, int B[], int n_right)
{
  int i = 0, j = 0, k = 0;

  while(i < n_left && j < n_right)
  {
    if(A[i] < B[i])
    {
      values[k++] = A[i++];
    }
    else
    {
      values[k++] = B[j++];
    }
  }
  while(i < n_left)
  {
    values[k++] = A[i++];
  }
  while(j < n_right)
  {
    values[k++] = B[j++];
  }
}

void sort(int values[], int n)
{
  if(n < 2)
  {
    return;
  }

  int mid = n / 2;
  int A[mid];
  int B[n - mid];

  for(int i = 0; i < mid; i++)
  {
    A[i] = values[i];
  }
  for(int j = mid, i = 0; j < n; j++, i++)
  {
    B[i] = values[j];
  }

  sort(A, (int) (sizeof(A) / sizeof(A[0])));
  sort(B, (int) (sizeof(B) / sizeof(B[0])));
  merge(values, A, mid, B, n - mid);
}
