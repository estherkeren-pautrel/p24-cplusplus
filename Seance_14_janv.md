//Séance du 14 janvier:

//on peut mettre des bouts de programme dans des fichiers
//Compilation séparée
//Main est le point d'entrée pour c++ pour faire un exécutable

//Si j'ai un area.cpp :
double pi = 3.14;
double area(double radius){
    return pi * radius * radius;
}

//on fait g++ -c area.cpp
//C++ va générer un exécutable, area.o (objet)
//on peut faire un autre fichier avec 
int main (){
    area(4.7);
}
//si on compile ça en main.cpp il va dire que area n'est ni définie, ni déclarée
//Donc dans le main je dois lui dire qu'il existe une fonction area qui prend un /type et renvoie un /type
double area(double);
int main (){
    area(4.7);
}

//-c il compile uniquement
//on dit aussi de faire l'édition de lien (linker), que ce soit un assembleur 
//g++ main.o area.o (ça ça veut dire link-les ensemble)
//il aura dans l'exécutable en segment de texte 
double area(double);
//double pi = 3.14; //mais au link des deux fichiers, c++ voudra que un des deux!!
//donc new synthaxe:
extern double pi; //il existera un jour une variable pi
int main (){
    area(4.7);
    pi;
}

//header déclarations
//on a un fichier .h de déclaration, d'en-tête
//area.h
double area(double);
extern double(pi);
//but: personne ne sait comment on a implémenté area
//ensuite dans le fichier avec le main, on met #include "area.h"

//static devant pi dans area.cpp c'est local au fichier
Problème les .h quand on les inclue dans meme unité de compilation.... 
#pragma once dans le fichier intstack.h (on ne doit l'inclure qu'une seule fois car défini un type)

On peut encore séparer de code la de la classe IntStack prise comme .h : on défini un nouveau type avec définition d'une méthode pop
On peut décider veut pas que gens voient méthode pop
on peut mettre dans public de la classe IntStack - déclare qu'il existera une méthode pop : int pop();

Donc on va définir méthode pop autre part :
int IntStackk::pop{
    //def de la methode
}
Les définitions on les aura dans un autre fichier IntStack.cpp (le fichier de base s'appelera intstack.h)
au début de ce fichier.cpp on met 
#include "instack.h"
de intstack.cpp on peut faire un exécutable intstack.o

Si on def dans la classe les méthodes sont inlines - ie infos passées au compilateur (mais quand pas défini dans la classe, coute cher en temps/mémoire?)

Si on veut cacher des choses on met dans un .cpp et on le compile, personne ne peut décortiquer le .o
Par contre les constructeurs ont des adresses

Si on veut définir les méthodes dans le fichier.h :
Pour pas en faire des fonctions globales, on met 
inline int intstack::pop(){};
inline int intstack::~intstack(){};
et ça c'est des fichiers.hpp ont le header et toutes les infos dedans (on peut aussi les appeler .h)