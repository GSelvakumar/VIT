// openmp program for minimum spanning tree using kruskal's algorithm

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX 1000000

int n, e;

struct edge
{
    int u, v, w;
} edges[MAX];

int parent[MAX];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void union1(int x, int y)
{
    parent[x] = y;
}

int comp(const void *a, const void *b)
{
    struct edge *x = (struct edge *)a;
    struct edge *y = (struct edge *)b;
    return x->w - y->w;
}

int main()
{
    int i, j, k, u, v, w, x, y, cost = 0;
    double start, end;
    printf("Enter the number of nodes and edges : ");
    scanf("%d %d", &n, &e);
    printf("Enter the edges and their weights : ");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    start = omp_get_wtime();
    qsort(edges, e, sizeof(edges[0]), comp);
    for (i = 0; i < n; i++)
        parent[i] = i;
    for (i = 0; i < e; i++)
    {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        x = find(u);
        y = find(v);
        if (x != y)
        {
            cost += w;
            union1(x, y);
        }
    }
    end = omp_get_wtime();
    printf("The cost of the minimum spanning tree is : %d ", cost);
    printf(" Time taken : %lf", end - start);
    return 0;
}
