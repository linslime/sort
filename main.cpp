#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<assert.h>
#include<math.h>
#define f 10000
void Sort(int* q, int n);
void BubbleSort(int* q, int n);
void SelectSort(int* q, int n);
void InsertionSort(int* q, int n);
void MergeSort(int* q, int n);
void MergeSort_(int* A, int low, int high, int* Aux);
void Merge(int* A, int low, int m, int high, int* Aux);
void QuickSort(int* q, int n);
void QuickSort_(int* A, int low, int high);
int QuickPass(int* A, int low, int high);
void CounterSort(int* q, int n);
void CounterSort_(int* A, int n, int* iCountA, int maxKey, int* sortedA);
void BucketSort(int* q, int n);
void BucketSort_(int* q, int n);
void RadixSort(int* q, int n);
void RadixSort_(int* q, int n);
void check(int* q, int n);
void swap(int* a, int* b);
void print(int* q, int n);
struct Node* NewNode();
void Insert(struct Node* la, int x);
int a[f], b[1000], c[10000], d[100000], e[1000000];
int s[100000000];
int p[100000000];
struct Node
{
    int data;
    struct Node* next;
};
struct Node* la[32768];
int main()
{
    int i;
    for (i = 0; i < f; i++)
        a[i] = rand();
    for (i = 0; i < f / 10; i++)
        la[i] = NewNode();
    /*  for(i=0; i<1000; i++)
          a[i]=rand()%10000+1;
      for(i=0; i<10000; i++)
          a[i]=rand()%100000+1;
      for(i=0; i<100000; i++)
          a[i]=rand()%1000000+1;
      for(i=0; i<1000000; i++)
          a[i]=rand()%10000000+1;*/
          //print(a,f);
    Sort(a, f);
    /*Sort(b,1000);
    Sort(c,10000);
    Sort(d,100000);
    Sort(e,1000000);*/
    return 0;
}
void Sort(int* q, int n)
{
    printf("为%d个数排序\n\n", n);
    BubbleSort(q, n);
    SelectSort(q, n);
    InsertionSort(q, n);
    MergeSort(q, n);
    QuickSort(q, n);
    CounterSort(q, n);
    BucketSort(q, n);
    RadixSort(q, n);
}
void BubbleSort(int* q, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        p[i] = q[i];
    clock_t start, finish;
    start = clock();
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (p[j] > p[j + 1])
                swap(&p[j], &p[j + 1]);
    finish = clock();
    printf("BubbleSort\n");
    //print(p,n);
    check(p, n);
    printf("该排序耗时%.3fs\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
}
void SelectSort(int* q, int n)
{
    int min, i, j;
    for (i = 0; i < n; i++)
        p[i] = q[i];
    clock_t start, finish;
    start = clock();
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (p[min] > p[j])
                min = j;
        swap(&p[i], &p[min]);
    }
    finish = clock();
    printf("SelectSort\n");
    //print(p,n);
    check(p, n);
    printf("该排序耗时%.3fs\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
}
void InsertionSort(int* q, int n)
{
    int i, j, x;
    for (i = 0; i < n; i++)
        p[i] = q[i];
    clock_t start, finish;
    start = clock();
    for (i = 1; i < n; i++)
    {
        j = i;
        while (p[j] < p[j - 1] && j>0)
        {
            swap(&p[j], &p[j - 1]);
            j--;
        }
    }
    finish = clock();
    printf("InsertionSort\n");
    //print(p,n);
    check(p, n);
    printf("该排序耗时%.3fs\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
}
void MergeSort(int* q, int n)
{
    int i;
    for (i = 0; i < n; i++)
        p[i] = q[i];
    clock_t start, finish;
    start = clock();
    MergeSort_(p, 0, n - 1, s);
    finish = clock();
    printf("MergeSort\n");
    //print(s,n);
    check(s, n);
    printf("该排序耗时%.3fs\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return;
}
void QuickSort(int* q, int n)
{
    int i;
    for (i = 0; i < n; i++)
        p[i] = q[i];
    clock_t start, finish;
    start = clock();
    QuickSort_(p, 0, n - 1);
    finish = clock();
    printf("QuickSort\n");
    //print(p,n);
    check(p, n);
    printf("该排序耗时%.3fs\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return;
}
void CounterSort(int* q, int n)
{
    clock_t start, finish;
    start = clock();
    CounterSort_(q, n, s, 32767, p);
    finish = clock();
    printf("CounterSort\n");
    //print(p,n);
    check(p, n);
    printf("该排序耗时%.3fs\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return;
}
void BucketSort(int* q, int n)
{
    clock_t start, finish;
    start = clock();
    BucketSort_1(q, n);
    finish = clock();
    printf("BucketSort\n");
    //print(p,n);
    check(p, n);
    printf("该排序耗时%.3fs\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return;
}
void RadixSort(int* q, int n)
{
    clock_t start, finish;
    start = clock();
    printf("RadixSort\n");
    RadixSort_(q, n);
    finish = clock();

    //print(p,n);
    check(p, n);
    printf("该排序耗时%.3fs\n\n", (double)(finish - start) / CLOCKS_PER_SEC);
    return;
}
void check(int* p, int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
        if (p[i] > p[i + 1])
            break;
    if (i == n - 1)
        printf("该排序没问题\n");
    else
        printf("该排序有问题\n");
}
void swap(int* a, int* b)
{
    int t;
    t = *b;
    *b = *a;
    *a = t;
}
void print(int* p, int n)
{
    int i, j = 0;
    for (i = 0; i < n; i++)
    {
        printf("%10d", p[i]);
        j++;
        if (j == 10)
        {
            printf("\n");
            j = 0;
        }
    }
}
void MergeSort_(int* A, int low, int high, int* Aux)
{
    int i, m;
    if (low >= high)
        return;
    m = (low + high) / 2;
    MergeSort_(A, low, m, Aux);
    MergeSort_(A, m + 1, high, Aux);
    Merge(A, low, m, high, Aux);
    for (i = low; i <= high; ++i)
        A[i] = Aux[i];
}
void Merge(int* A, int low, int m, int high, int* Aux)
{
    int k, j, i;
    i = low;
    j = m + 1;
    k = i;
    while (i <= m && j <= high)
    {
        if (A[i] <= A[j])
            Aux[k++] = A[i++];
        else
            Aux[k++] = A[j++];
    }
    while (i <= m)
        Aux[k++] = A[i++];
    while (j <= high)
        Aux[k++] = A[j++];
}
void QuickSort_(int* A, int low, int high)
{
    int pivot;
    if (low >= high)
        return;
    pivot = QuickPass(A, low, high);
    QuickSort_(A, low, pivot - 1);
    QuickSort_(A, pivot + 1, high);
}
int QuickPass(int* A, int low, int high)
{
    int x = A[low];
    while (low < high)
    {
        while (low < high && x <= A[high])
            --high;
        if (low == high)
            break;
        A[low++] = A[high];
        while (low < high && x >= A[low])
            ++low;
        if (low == high)
            break;
        A[high--] = A[low];
    }
    A[low] = x;
    return low;
}
void CounterSort_(int* A, int n, int* iCountA, int maxKey, int* sortedA)
{
    int key, iStartPos, iNextPos, i;
    for (key = 0; key <= maxKey; ++key)
        iCountA[key] = 0;
    for (i = 0; i < n; i++)
        ++iCountA[A[i]];
    iStartPos = 0;
    for (key = 0; key <= maxKey; ++key)
    {
        iNextPos = iStartPos + iCountA[key];
        iCountA[key] = iStartPos;
        iStartPos = iNextPos;
    }
    assert(iStartPos == n);
    for (i = 0; i < n; ++i)
        sortedA[iCountA[A[i]]++] = A[i];
}
void BucketSort_(int* q, int n)
{
    int i, x, j = 0;
    for (i = 0; i < n; i++)
    {
        x = q[i] / 256;
        Insert(la[x], q[i]);
    }
    la[j] = la[j]->next;
    for (i = 0; i < n; i++)
    {
        if (la[j]->next == 0)
        {
            //Clear(la[j]);
            j++;
            la[j] = la[j]->next;
        }
        p[i] = la[j]->data;
    }
}
struct Node* NewNode()
{
    struct Node* p;
    p = (struct Node*)malloc(sizeof(struct Node));
    if (p == 0)
    {
        printf("Error:out of memory\n");
        exit(-1);
    }
    return p;
}
void Insert(struct Node* la, int x)
{
    struct Node* q = NewNode();
    q->data = x;
    struct Node* p = la;
    while (p->next && x > p->next->data)
        p = p->next;
    q->next = p->next;
    p->next = q;
}
void BucketSort_1(int* q, int n)
{
    int i, j = 0;
    for (i = 0; i < n; i++)
        ++s[(q[i])];
    for (i = 0; i < n; i++)
    {
        while (s[j] == 0)
        {
            j++;
        }
        p[i] = j;
        s[j]--;
    }
}
void Clear(struct Node* la)
{
    struct Node* p = la->next;
    while (p != 0)
    {
        struct Node* q = p;
        p = p->next;
        free(q);
    }
    la->next = 0;
}
/*void RadixSort_(int *q,int n)
{
    int i,j=0,x;
    for(x=1; x<=5; ++x)
    {
        for(i=0; i<n; i++)
        {
            lb[x-1][((int)(q[i]/pow(10,x-1)))%10]->data=q[i];
            lb[x-1][((int)(q[i]/pow(10,x-1)))%10]=lb[x-1][((int)(q[i]/pow(10,x-1)))%10]->next;
        }
        for(i=0; i<n; i++)
        {
            if(lb[x-1][j]->next==0)
            {
                //Clear(lb[x-1][j]);
                j++;
                lb[x-1][j]=lb[x-1][j]->next;
            }
            p[i]=lb[x-1][j]->data;
        }
    }
}*/
void RadixSort_(int* q, int n)
{
    int* re, i, pos, j;
    re = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        re[i] = q[i];
    }
    int* radix[10];
    for (i = 0; i < 10; i++)
    {
        radix[i] = (int*)malloc(sizeof(int) * (n + 1));
        radix[i][0] = 0;
    }
    for (pos = 1; pos <= 5; pos++)
    {
        for (i = 0; i < n; i++)
        {
            int num = Getpos(re[i], pos);
            int index = ++radix[num][0];
            radix[num][index] = re[i];
        }
        for (i = 0, j = 0; i < 10; i++)
        {
            for (int k = 1; k <= radix[i][0]; k++)
            {
                re[j++] = radix[i][k];

            }
            radix[i][0] = 0;
        }
    }
    for (i = 0; i < 10; i++)
    {
        free(radix[i]);
    }
    for (i = 0; i < n; i++)
    {
        p[i] = re[i];
    }
    return;
}
int Getpos(int num, int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
    {
        temp *= 10;
    }
    return (num / temp) % 10;
}
