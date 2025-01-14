// hiérarchie de classes pour stocker des objets graphiques

// deux méthodes : move qui passe de x, y à x + dx, y + dy ET calcul de la surface

#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>

float pi = 3.14;

class forme
{
protected:
    int pos_x;
    int pos_y;
    char color;

public:
    forme(int x, int y, char co) : pos_x(x), pos_y(y), color(co) {

                                          };
    void move(int dx, int dy)
    {
        pos_x = pos_x + dx;
        pos_y = pos_y + dy;
    };
    bool is_at_position(int xi, int yi)
    {
        return ((xi == pos_x) and (yi == pos_y));
    };
};

class circle : public forme
{
    int radius;

public:
    circle(int x, int y, char c, int r) : forme{x, y, c}, radius(r) {

                                                 };
    int area(circle c)
    {
        return (pi * radius * radius);
    };
};

class square : public forme
{
    int side;

public:
    square(int x, int y, char c, int s) : forme{x, y, c}, side(s) {};
    int area(square s)
    {
        return (side * side);
    };
};

class rectangle : public forme
{
    int width;
    int height;

public:
    rectangle(int x, int y, char c, int w, int h) : forme{x, y, c}, width(w), height(h) {

                                                           };
    int area(rectangle r)
    {
        return (width * height);
    };
};

forme *find_at_position(int xi, int yi, std::vector<forme *> v)
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
    circle c(3, 4, 'b', 5);
    rectangle r(2, 7, 'r', 4, 7);
    std::vector<forme *> v;
    v.push_back(&c);
    v.push_back(&r);
    forme* s = find_at_position(4, 5, v);
    s->area();
    std::cout << s << std::endl;
    std::cout << &c << std::endl;
    return 0;
};

//aller chercher objet à cette adresse (*p) 
//type adresse shape*
