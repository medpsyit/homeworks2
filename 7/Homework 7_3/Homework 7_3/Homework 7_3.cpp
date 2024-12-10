#include <iostream>
#include <fstream>

bool dfs(int** graph, int N, int vertex, int* visited)
{
    visited[vertex] = 1;
    for (int count = 0; count < N; count++)
    {
        if (graph[vertex][count] == 1)
        {
            if (visited[count] == 0)
            {
                dfs(graph, N, count, visited);
            }
            else if (vertex != graph[vertex][count])
            {
                return true;
            }
        }
    }
    return false;
}

bool is_cyclic(int** graph, int N)
{
    int* visited = new int[N] {0};
    for (int count = 0; count < N; count++)
    {
        if (visited[count] == 0)
        {
            if (dfs(graph, N, count, visited)) { return true; }
        }
    }
    return false;
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
        if (is_cyclic(graph, N))
        {
            std::cout << "В графе есть цикл!" << std::endl;
        }
        else
        {
            std::cout << "В графе циклов нет!" << std::endl;
        }
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
