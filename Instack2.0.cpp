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
    // besoin d'un constructeur où on passe une valeur s en argument - il nous faut une troisième zone mémoire pour que le tableau reste formé même après être sorti de la fonction
    //on construit opérateur IntStack
    IntStack& operator= (const IntStack& r){
        //son tableau se fait tuer
        //on réaloue un nouveau tableau
        //en cours de création....
    }
    // constructeur de copie (si on ne le met pas il le fait par défaut, mais viollement) //i.n c'est l'argument du nb d'éléments de ma pile i
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
    // il va falloit créer un destructeur pour détruire la zone mémoire de ma pile dans la mémoire dynamique (heap)
    ~IntStack()
    { // création du destructeur
        delete[] pile;
    };
    void push(int e)
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
    int get_top() const // vr: const puisqu'elle ne modifie pas l'objet sur lequel elle est appelée
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
    int pop() // vr: pas de const puisque pop modifie la pile --n
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
    bool is_empty() const // vr: const puisqu'elle ne modifie pas l'objet sur lequel elle est appelée
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
    bool is_full() const // vr: idem
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
    // vr: définir operator<< qui appelle print
    // (donc pas besoin qu'il soit friend)
    void print() const // vr: idem (const puisqu'elle ne modifie pas this)
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
};

// 1. réaliser le code pour faire fonctionner cette pile d'entier de taille fixée à la compilation
// 2. quelles sont les méthodes qui ne modifient pas l'objet sur lequel elles sont appelées
//    faites en sorte qu'elles puissent être appelées sur un objet constant
// 3. faites la fonction qui permet d'afficher un objet de type IntStack directement avec <<<
//    std::cout << s1;
//    il faut redéfinir l'operator<< en appelant la méthode print

int main()
{
    int size;
    std::cout << "Entrez la taille de votre pile" << std::endl;
    std::cin >> size; // cin entrée standard
    IntStack s1(size);
    s1.print(); // affichera [[
    s1.push(1);
    s1.push(2);
    s1.push(3);
    IntStack j (s1);
    s1.print();                         // affichera [1 2 3 ]
    std::cout << s1.pop() << std::endl; // affichera 3
    s1.print();                         // affichera [1 2 ]
    j.push(4);
    j.print();
    return 0;
}
