#include <bits/stdc++.h>

using namespace std;

void QuickSort(vector<int>&A, int p, int r);
int Partition(vector<int>&A, int p, int r);

int main()
{
    //freopen("../temp.txt", "r", stdin);
    freopen("../in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    FILE *fp;
    clock_t start, finish;
    double elapsed_time;
    vector<int>data;
    int i, v, n;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &v);
        data.push_back(v);
    }

    start = clock();
    QuickSort(data, 0, n - 1);
    finish = clock();

    elapsed_time = (double) (finish - start) / CLOCKS_PER_SEC;

    printf("Elapsed time = %lf\n", elapsed_time);

    fp = fopen("../out.txt", "w");
    for (i = 0; i < n; i++) {
        fprintf(fp, "%d\n", data[i]);
    }
    fclose(fp);

    return 0;
}

void QuickSort(vector<int>&A, int p, int r)
{
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

int Partition(vector<int>&A, int p, int r)
{
    int i, j, x, temp;

    x = A[r];
    i = p - 1;

    for (j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[i + 1];
    A[i + 1] = A[r];
    A[r] = temp;

    return (i + 1);
}

