#include <iostream>
#include <fstream>
#include <list>

void dfs(int** graph, int N, int vertex, int* visited, std::list<int>& order)
{
    visited[vertex] = 1;
    for (int count = 0; count < N; count++)
    {
        if (graph[vertex][count] == 1)
        {
            if (visited[count] == 0)
            {
                dfs(graph, N, count, visited, order);
            }
        }
    }
    order.emplace_front(vertex + 1);
}

void top_sort(int** graph, int N)
{
    std::list<int> order;
    int* visited = new int[N] {0};
    for (int count = 0; count < N; count++)
    {
        if (visited[count] == 0)
        {
            dfs(graph, N, count, visited, order);
        }
    }
    for (int n : order)
    {
        std::cout << n << " ";
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    std::ifstream in("input.txt");
    if (in.is_open())
    {
        int N{};
        in >> N;
        int** graph = new int* [N];
        for (int count1 = 0; count1 < N; count1++)
        {
            graph[count1] = new int[N];
        }
        for (int count1 = 0; count1 < N; count1++)
        {
            for (int count2 = 0; count2 < N; count2++)
            {
                in >> graph[count1][count2];
            }
        }
        std::cout << "Топологический порядок вершин: ";
        top_sort(graph, N);
        for (int count1 = 0; count1 < N; count1++)
        {
            delete[] graph[count1];
        }
        delete[] graph;
    }
    else { std::cout << "Не удалось открыть файл input.txt!\n"; }
    in.close();
    return 0;
}
