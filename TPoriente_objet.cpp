// hiérarchie de classes pour stocker des objets graphiques

// deux méthodes : move qui passe de x, y à x + dx, y + dy ET calcul de la surface

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>

float pi = 3.14;

class forme
{private:
    int x;
    int y;
    std::string color;

public:
    void move(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
    };
    bool is_at_position(int xi, int yi) {
        return ((xi == x) and (yi == y));
    };
};

class circle : public forme 
{
    int radius;

public:
    int area()
    {
        return (pi * radius * radius);
    };
};

class square : public forme 
{
    int side;

public:
    int area()
    {
        return (side * side);
    };
};

class rectangle : public forme
{
    int width;
    int height;

public:
    int area()
    {
        return (width * height);
    };
};

forme* find_at_position(int xi, int yi, std::vector<forme*> v)
{
    for (auto &e : v)
    {
        if (e->is_at_position(xi, yi))
        {
            return e;
        };
    };
    return 0;
};

int main()
{
    circle c{3, 4, 'b', 5};
    rectangle r{2, 7, 'r', 4, 7};
    std::vector<forme *> v;
    v.push_back(&c);
    v.push_back(&r);
    forme *s = find_at_position(2, 3, v);
    s->area();
    std::cout << s;
    return 0;
};
