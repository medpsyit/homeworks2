#include <iostream>
#include <fstream>

void print_graph(int** graph, int N)
{
    std::cout << "Текстовый вид орграфа: " << std::endl;
    for (int row = 0; row < N; row++)
    {
        std::cout << row + 1 << ": ";
        int v = 0;
        for (int col = 0; col < N; col++)
        {
            if (graph[row][col] == 1)
            {
                v++;
                std::cout << col + 1 << " ";
            }
        }
        if (v == 0)
        {
            std::cout << "нет";
        }
        std::cout << std::endl;
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
        print_graph(graph, N);
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