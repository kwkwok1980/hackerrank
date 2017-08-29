#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Cells[10][10];
int Regions[10][10];

struct Task
{
    int r;
    int i;
    int j;
};

int Solve(int N, int M, const Task& task)
{
    Regions[task.i][task.j] = task.r;
    int count = 1;
    
    std::vector<Task> tasks;
    auto CheckPoint = [&](int r, int i, int j)
    {
      if (i>=0 && i<N && j>=0 && j<M)
      {
          if (Cells[i][j] == 1)
          {
              if (Regions[i][j] == 0)
              {
                  Regions[i][j] = r;
                  Task t {r, i, j};
                  tasks.emplace_back(t);
                  ++count;
              }
          }
      }
    };
    
    tasks.emplace_back(task);
    while(tasks.empty() == false)
    {
        Task t = *tasks.begin();
        tasks.erase(tasks.begin());
        CheckPoint(t.r, t.i-1, t.j-1);
        CheckPoint(t.r, t.i-1, t.j);
        CheckPoint(t.r, t.i-1, t.j+1);
        CheckPoint(t.r, t.i, t.j-1);
        CheckPoint(t.r, t.i, t.j+1);
        CheckPoint(t.r, t.i+1, t.j-1);
        CheckPoint(t.r, t.i+1, t.j);
        CheckPoint(t.r, t.i+1, t.j+1);
    }
    
    return count;
}

int main() {
    int N,M;
    std::cin >> N;
    std::cin >> M;
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
        {
            int value;
            std::cin >> value;
            Cells[i][j] = value;
            Regions[i][j] = 0;
        }
    }
    
    int region = 1;
    int max = 0;
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<M; ++j)
        {
            if (Cells[i][j] == 1)
            {
                if (Regions[i][j] == 0)
                {
                    Task task {region++, i, j};
                    int count = Solve(N, M, task);
                    if (count > max)
                    {
                        max = count;
                    }
                }
            }
        }
    }
    
    std::cout << max << std::endl;
    
    
    return 0;
}
