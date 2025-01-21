#include "intstack.h"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

int main()
{
    int size;
    std::cout << "Entrez la taille de votre pile" << std::endl;
    std::cin >> size; // cin entrée standard
    Pautrel::IntStack s1(size);
    s1.print(); // affichera [[
    s1.push(1);
    s1.push(2);
    s1.push(3);
    Pautrel::IntStack j(s1);
    s1.print();                         // affichera [1 2 3 ]
    std::cout << s1.pop() << std::endl; // affichera 3
    s1.print();                         // affichera [1 2 ]
    j.push(4);
    Pautrel::IntStack r = j;
    r.print();
    j.print();
    return 0;
}