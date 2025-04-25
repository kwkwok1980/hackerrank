#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>

struct Point
{
    int x;
    int y;
};

struct Step
{
    int a;
    int b;
};

struct Task
{
    int x;
    int y;
};

int Points [25][25];
int Results [25][25];
std::deque<Task> Tasks;

inline void Update(int n, int d, int i, int j)
{
    if (i<n && j<n && i>=0 && j>=0)
    {
        if (Points[i][j] == -1 || Points[i][j] > d)
        {
            Points[i][j] = d;
            Tasks.push_back(Task{i,j});
        }
    }
}

void Walk(int n, const Step& step, const Point& point)
{
    int i,j;
    int d = Points[point.x][point.y] + 1;

    i = point.x + step.a;
    j = point.y + step.b;
    Update(n,d,i,j);

    i = point.x + step.a;
    j = point.y - step.b;
    Update(n,d,i,j);

    i = point.x - step.a;
    j = point.y + step.b;
    Update(n,d,i,j);

    i = point.x - step.a;
    j = point.y - step.b;
    Update(n,d,i,j);

    i = point.x + step.b;
    j = point.y + step.a;
    Update(n,d,i,j);

    i = point.x + step.b;
    j = point.y - step.a;
    Update(n,d,i,j);

    i = point.x - step.b;
    j = point.y + step.a;
    Update(n,d,i,j);

    i = point.x - step.b;
    j = point.y - step.a;
    Update(n,d,i,j);
}

int Fill(int n, const Step& step)
{
    for (int i=0; i<n; ++i)
    {
        memset(Points[i], -1, sizeof(int)*n);
    }    
    
    Points[0][0] = 0;
    Tasks.emplace_back(Task{0,0});
    while(!Tasks.empty())
    {
        const Task& task = Tasks.front();
        Walk(n, step, Point{task.x, task.y});
        Tasks.pop_front();
    }
    return Points[n-1][n-1]; 
}


int main()
{
    int n,i,j;
    std::cin >> n;
    
    for (int i=1; i<n; ++i)
    {
        for (int j=i; j<n; ++j)
        {
            Step step {i, j};
            int d = Fill(n, step);
            Results[i][j] = d;
            Results[j][i] = d;
        }
    }
    
    for (int i=1; i<n; ++i)
    {
        for (int j=1; j<n; ++j)
        {
            if (j < n-1)
            {
                std::cout << Results[i][j] << " ";       
            }
            else
            {
                std::cout << Results[i][j] << std::endl;       
            }
        }
    }
    
    
    return 0;
}
