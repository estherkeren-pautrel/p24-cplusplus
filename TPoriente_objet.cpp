// hiérarchie de classes pour stocker des objets graphiques

// deux méthodes : move qui passe de x, y à x + dx, y + dy ET calcul de la surface
//; à la fin des expressions pas à la fin des méthodes, sauf à la fin du {} de la classe

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

                                          }; //constructeur dit où ranger x, où ranger y, où ranger color (on peut mettre x(x))
    void move(int dx, int dy)
    {
        pos_x = pos_x + dx;
        pos_y = pos_y + dy;
    };
    virtual int area() = 0; //méthode abstraite - quand on ne sait pas donnner l'implémentation (va avec le virtual) : mtn on ne peut plus jamais créer un objet de type shape - car il y a une méthode non définie
    //création d'une classe abstraite
    bool is_at_position(int xi, int yi)
    {
        return ((xi == pos_x) and (yi == pos_y));
    };
};

class circle : public forme //on dérive la classe en public
{
    int radius;
public:
    circle(int x, int y, char c, int r) : forme{x, y, c}, radius(r) {

                                                 };
    int area()
    {
        return (pi * radius * radius);
    };
};

class square : public forme
{
    int side;

public:
    square(int x, int y, char c, int s) : forme{x, y, c}, side(s) {};
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
    rectangle(int x, int y, char c, int w, int h) : forme{x, y, c}, width(w), height(h) {

                                                           };
    int area()
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
    std::cout << "Pas de forme trouvée à cette position." << std::endl;
    exit(EXIT_FAILURE);
};

int main()
{
    circle c(3, 4, 'b', 5);
    rectangle r(2, 7, 'r', 4, 7);
    std::vector<forme *> v;
    v.push_back(&c);
    v.push_back(&r);
    v[0]->move(10,10);
    //c.move(10,10); (fonctionne)
    forme* s = find_at_position(2, 7, v);
    s->area(); //(faut mettre area comme constructeur dans shape et faut dire que c'est à liaison dynamique, ie c'est sur le type exact de l'objet)
    std::cout << s->area() << std::endl;
    std::cout << r.area() << std::endl;
    return 0;
};

//aller chercher objet à cette adresse (*p) 
//type adresse shape*
//virtual faut que le type doit exact, ie que ce soit le même type entre les deux méthodes dans la classe parent et la classe héritée 
//overriding de mettre area dans shape
