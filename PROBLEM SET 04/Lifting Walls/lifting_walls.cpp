#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
    
    Point()
    {
        x = 0;
        y = 0;
    }
    
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    
    double distance_to(Point that)
    {
        double x = static_cast<double>(this->x - that.x);
        double y = static_cast<double>(this->y - that.y);
        return sqrt(( x * x ) + ( y * y ));
    }
};

struct Wall
{
    double x, y;
    
    Wall(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    
    double distance_to(Point p) // skip sqrt for performance
    {
        double _x = x - static_cast<double>(p.x);
        double _y = y - static_cast<double>(p.y);
        return (_x * _x) + (_y * _y);
    }
};

int number_of_cranes(vector<Wall> walls, vector<Point> cranes, int reach);
void calc_mid_walls(vector<Wall> &v, int l, int w);
bool wall_reachable(Wall wall, Point crane, int reach);

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    
    int l, w, n, r;
    cin >> l >> w >> n >> r;
    
    vector<Wall> walls;
    vector<Point> cranes;
    
    calc_mid_walls(walls, l, w);
    
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        cranes.push_back(Point(x, y));
    }
    
    int result = number_of_cranes(walls, cranes, r);
    
    if (result == -1)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        cout << result << endl;
    }
    return 0;
}

int number_of_cranes(vector<Wall> walls, vector<Point> cranes, int reach)
{
    int count = 0;
    
    for (size_t i = 0; i < cranes.size(); i++)
    {
        count = 0;
        for (size_t w = 0; w < walls.size(); w++)
        {
            if (wall_reachable(walls[w], cranes[i], reach))
            {
                count++;
            }
        }
        if (count == 4)
        {
            return 1;
        }
    }
    
    for (size_t i = 0; i < cranes.size(); i++)
    {
        for(size_t j = i + 1; j < cranes.size(); j++)
        {
            count = 0;
            for (size_t w = 0; w < walls.size(); w++)
            {
                if (wall_reachable(walls[w], cranes[i], reach) ||
                    wall_reachable(walls[w], cranes[j], reach))
                {
                    count++;
                }
            }
            if (count == 4)
            {
                return 2;
            }
        }
    }
    
    for (size_t i = 0; i < cranes.size(); i++)
    {
        for(size_t j = i + 1; j < cranes.size(); j++)
        {
            for(size_t k = j + 1; k < cranes.size(); k++)
            {
                count = 0;
                for (size_t w = 0; w < walls.size(); w++)
                {
                    if (wall_reachable(walls[w], cranes[i], reach) ||
                        wall_reachable(walls[w], cranes[j], reach) ||
                        wall_reachable(walls[w], cranes[k], reach))
                    {
                        count++;
                    }
                }
                if (count == 4)
                {
                    return 3;
                }
            }
        }
    }
    
    for (size_t i = 0; i < cranes.size(); i++)
    {
        for(size_t j = i + 1; j < cranes.size(); j++)
        {
            for(size_t k = j + 1; k < cranes.size(); k++)
            {
                for (size_t l = k + 1; l < cranes.size(); l++)
                {
                    count = 0;
                    for (size_t w = 0; w < walls.size(); w++)
                    {
                        if (wall_reachable(walls[w], cranes[i], reach) ||
                            wall_reachable(walls[w], cranes[j], reach) ||
                            wall_reachable(walls[w], cranes[k], reach) ||
                            wall_reachable(walls[w], cranes[l], reach))
                        {
                            count++;
                        }	
                    }
                    if (count == 4) 
                    {
                        return 4;
                    }
                }
            }
        }
    }
    return -1;
}

bool wall_reachable(Wall wall, Point crane, int reach)
{
    return wall.distance_to(crane) <= static_cast<double>(reach * reach);
}

void calc_mid_walls(vector<Wall> &v, int l, int w)
{
    v.push_back(Wall( (-l / 2.0), 0 ));
    v.push_back(Wall( (l / 2.0), 0 ));
    v.push_back(Wall( 0, (-w / 2.0) ));
    v.push_back(Wall( 0, (w / 2.0) ));
}