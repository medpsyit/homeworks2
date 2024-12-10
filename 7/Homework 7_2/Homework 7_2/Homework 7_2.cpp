#include <iostream>
#include <fstream>
#include <queue>

void bfs(int** graph, int N, int v)
{
    int vertex = v - 1;
    int* visited = new int[N] {0};
    std::queue<int> queue;
    visited[vertex] = 1;
    queue.push(vertex);
    while (!queue.empty())
    {
        vertex = queue.front();
        std::cout << vertex + 1 << " ";
        queue.pop();
        for (int count = 0; count < N; count++)
        {
            if (graph[vertex][count] == 1)
            {
                if (visited[count] == 0)
                {
                    visited[count] = 1;
                    queue.push(count);
                }
            }
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    std::ifstream in("input.txt");
    if (in.is_open())
    {
        int N{}, v{};
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
        do
        {
            std::cout << "В графе " << N << " вершин. Введите номер вершины, с которой начинается обход: ";
            std::cin >> v;
            if (v < 1 || v > N)
            {
                std::cout << "Ошибка! Такой вершины нет!" << std::endl;
            }
        } while (v < 1 || v > N);
        std::cout << "Порядок обхода вершин: ";
        bfs(graph, N, v);
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
