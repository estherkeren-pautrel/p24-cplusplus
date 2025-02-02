//on ne compile jamais un hpp : il n'y a pas de main dans hpp!!


#include <iostream>
#include <stdexcept>
#include <cstdlib> //exit et abort sont dans cette librairie (exit : terminaison normale du code) (abort : on tue le process de manière violente)

// grosse mémoire : heap le tas - C++ gère la pile d'exécution
// on demande un morceau de mémoire (dans heap) avec new et on le tue avec delete

class IntStack
{ // class c'est private par défaut
    int n;
    int size;
    int *pile;
    // pile[0] - va sur le premier élément du tableau
    // delete [] pile;

public:
    IntStack(const IntStack &r) : n{r.n}, size{r.size}
    {
        pile = new int[size];
        for (int i = 0; i < n; i++)
        {
            pile[i] = r.pile[i];
        }
    };
    IntStack(int s) : n{0}, size{s}
    {
        if (size <= 0)
        {
            exit(EXIT_FAILURE);
        };
        pile = new int[size];
    };
    IntStack& operator=(const IntStack &r);
    ~IntStack();
    void push(int e);
    int get_top() const ;
    int pop() ;
    bool is_empty() const ;
    bool is_full() const ;
    void print() const ;
};

inline IntStack& IntStack :: operator=(const IntStack &r)
    {
        if (this != &r)
        {
            size = r.size;
            delete[] pile;        // on efface l'ancien tableau
            pile = new int[size]; // on réaloue un nouveau tableau
            for (int i = 0; i < n; ++i)
            {
                pile[i] = r.pile[i];
            }
        }
        return *this;
    }

inline IntStack :: ~IntStack()
    { // création du destructeur
        delete[] pile;
    }

inline void IntStack :: push(int e)
    {
        // if (is_full() == 1)
        if (is_full())
        {
            // exit; (attention cela n'exite pas du tout le programme)
            exit(EXIT_FAILURE);
        };
        pile[n] = e;
        ++n;
        // cette fonction ajoute l'entier e dans la pile
        // votre code ici
    }

inline int IntStack :: get_top() const // vr: const puisqu'elle ne modifie pas l'objet sur lequel elle est appelée
    // on veut pouvoir l'appeler sur des objets constants
    // naturellement pour que cela fonctionne il faut que toutes les autres méthodes utilisées
    // (comme is_empty) soient aussi const...
    {
        // if (is_empty() == 1)
        if (is_empty())
        {
            // exit;
            exit(EXIT_FAILURE);
        };
        return pile[n - 1];
        // cette fonction retourne le dernier entier empilé
        // votre code ici
    }

inline int IntStack :: pop() // vr: pas de const puisque pop modifie la pile --n
    {
        if (is_empty())
        {
            // exit;
            exit(EXIT_FAILURE);
        };
        --n;
        return pile[n];
        // cette fonction retourne le dernier entier empilé
        // et supprime cet entier de la pile
        // votre code ici
    }

inline  bool IntStack :: is_empty() const // vr: const puisqu'elle ne modifie pas l'objet sur lequel elle est appelée
    // on veut pouvoir l'appeler sur des objets constants
    {
        return n == 0;
        // if (n == 0)
        // {
        //     return 1;
        // }; // cette fonction teste si la pile est vide
        // // votre code ici
        // return 0;
    }

inline  bool IntStack :: is_full() const // vr: idem
    {
        return n == size;
        // if (n == SIZE)
        // {
        //     return 1;
        // };
        // cette fonction teste si la pile est pleine
        // il y a SIZE entiers dans la pile
        // votre code ici
        return 0;
    }

inline void IntStack :: print() const // vr: idem (const puisqu'elle ne modifie pas this)
    {
        std::cout << "[";
        for (int i = 0; i < n; i++)
        {
            std::cout << pile[i] << " "; // vr: mettre des espaces
        };
        std::cout << "[" << std::endl;
        // cette fonction affiche la pile, par exemple
        // [1 2 3 [ pour dire que 3 entiers sont dans la pile
        // le dernier empilé est 3
        // votre code ici
    }

