#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Points [25][25];

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

void Walk(int n, const Step& step, const Point& point)
{
    int i,j;
    int d = Points[point.x][point.y] + 1;
    
    i = point.x + step.a;
    j = point.y + step.b;
    if (i<n && j<n && i>=0 && j>=0 && (Points[i][j] == -1 || Points[i][j] > d)) Points[i][j] = d;
    
    i = point.x + step.a;
    j = point.y - step.b;
    if (i<n && j<n && i>=0 && j>=0 && (Points[i][j] == -1 || Points[i][j] > d)) Points[i][j] = d;
    
    i = point.x - step.a;
    j = point.y + step.b;
    if (i<n && j<n && i>=0 && j>=0 && (Points[i][j] == -1 || Points[i][j] > d)) Points[i][j] = d;
    
    i = point.x - step.a;
    j = point.y - step.b;
    if (i<n && j<n && i>=0 && j>=0 && (Points[i][j] == -1 || Points[i][j] > d)) Points[i][j] = d;
        
    i = point.x + step.b;
    j = point.y + step.a;
    if (i<n && j<n && i>=0 && j>=0 && (Points[i][j] == -1 || Points[i][j] > d)) Points[i][j] = d;
    
    i = point.x + step.b;
    j = point.y - step.a;
    if (i<n && j<n && i>=0 && j>=0 && (Points[i][j] == -1 || Points[i][j] > d)) Points[i][j] = d;
    
    i = point.x - step.b;
    j = point.y + step.a;
    if (i<n && j<n && i>=0 && j>=0 && (Points[i][j] == -1 || Points[i][j] > d)) Points[i][j] = d;
    
    i = point.x - step.b;
    j = point.y - step.a;
    if (i<n && j<n && i>=0 && j>=0 && (Points[i][j] == -1 || Points[i][j] > d)) Points[i][j] = d;
}

int Fill(int n, const Step& step)
{
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            Points[i][j] = -1;
        }
    }
    
    Points[n-1][n-1] = 0;
    for (int i=n-1; i>=0; --i)
    {
        for (int j=n-1; j>=0; --j)
        {
            if (Points[i][j] != -1)
            {
                Point point {i, j};
                Walk(n, step, point);
            }
        }
    }
    return Points[0][0];
}
    

int main() 
{
    int n;
    std::cin >> n;
    for (int i=1; i<n; ++i)
    {
        for (int j=i; j<n; ++j)
        {
            Step step {i, j};
            int d = Fill(n, step);
            std::cout << i << "," << j << "," << d << std::endl;
        }
    }
    return 0;
}
