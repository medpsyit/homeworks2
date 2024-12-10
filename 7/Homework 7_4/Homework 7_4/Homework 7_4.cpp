#include <iostream>
#include <fstream>

void dfs(int** graph, int N, int vertex, int* cids, int cid);

void components(int** graph, int N);

void print_info(int** graph, int N, int* cids);

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
        components(graph, N);
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

void dfs(int** graph, int N, int vertex, int* cids, int cid)
{
    cids[vertex] = cid;
    for (int count = 0; count < N; count++)
    {
        if (graph[vertex][count] == 1)
        {
            if (cids[count] == 0)
            {
                dfs(graph, N, count, cids, cid);
            }
        }
    }
}

void components(int** graph, int N)
{
    int* cids = new int[N] {0};
    int cid = 1;
    for (int count = 0; count < N; count++)
    {
        if (cids[count] == 0)
        {
            dfs(graph, N, count, cids, cid);
            cid++;
        }
    }
    print_info(graph, N, cids);
}

void print_info(int** graph, int N, int* cids)
{
    std::cout << "Принадлежность вершин компонентам связности: " << std::endl;
    for (int count = 0; count < N; count++)
    {
        std::cout << count + 1 << " - " << cids[count] << std::endl;
    }
    std::cout << "Количество компонентов связности в графе: " << cids[N - 1] << std::endl;
}