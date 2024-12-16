// Ce fichier décrit une première version très basique du "jeu du serpent".

// Le but est de vous faire réfléchir à comment réaliser ce jeu en C++.
// Aussi ne cherchez pas le code du snake sur internet (ok pour les types de la librairie standard C++ genre std::vector).
// Faites votre propre code, c'est uniquement en faisant/défaisant qu'on apprend.

// Mettez votre code dans un repo github private de nom snake.
// Si vous voulez que je regarde votre code, mettez moi collaborateur de ce repo.

// Veuillez avoir commencé ce code pour notre prochaine séance de TP (le mardi 10 décembre 2024)
// Vous pouvez bien sûr le terminer.

// Vous devez réaliser un jeu où un serpent se déplace sur un board en mangeant des pommes pour grandir.
// Si il se mange lui-même ou sort du board: c'est game-over !

// On privilégie le code, l'affichage sera fait bêtement par des std::cout.
// Ci-dessous un exemple d'affichage où un serpent de taille 3 mange une pomme sur un board de 5 x 7.
// La tête du serpent est représentée par 'O' et son corps par 'o', le reste du board est représenté par des '.'.
// La pomme est représentée par '@'.

// ./snake
// vous exécutez votre programme, vous obtenez:

// .......
// .......
// ..Ooo..
// ....@..
// .......
// what do you want to do ('q' to quit): k

//         on entre le caractère k au clavier pour dire que le serpent veut aller vers le bas.
//         on affiche ensuite le board modifié:

// .......
// .......
// ..oo...
// ..O.@..
// .......
// what do you want to do ('q' to quit): l

//         après l vous devez taper enter (entrer)
//         on veut aller vers la droite:

// .......
// .......
// ..o....
// ..oO@..
// .......
// what do you want to do ('q' to quit): l

//         Encore à droite pour mettre la tête du serpent sur la position de la pomme,
//         et ainsi manger la pomme.

// .......
// .@.....
// ..o....
// ..ooO..
// .......
// what do you want to do ('q' to quit):

//         Le serpent a mangé la pomme et a grandi d'un anneau.
//         Une pomme est apparue à un autre endroit du board.

// Les commandes sont entrées au clavier.
// Dans un premier temps, le serpent avance d'une case à chaque fois que vous entrez une commande.
// Si vous tapez:
//    - 'i' le serpent va (un coup) vers le haut
//    - 'k' le serpent va (un coup) vers le bas
//    - 'j' le serpent va (un coup) vers la gauche
//    - 'l' le serpent va (un coup) vers la droite
// Notons que le jeu s'arrête si le serpent sort du board, se marche dessus ou si on tape 'q'.

// Pour représenter ce jeu, il vous faut (par exemple):

// 1) un tableau de caractères pour représenter le board (std::vector<char>)
//      * faites un seul std::vector<char>
//      * gérez les lignes et colonnes vous-même où
//        position(i, j) est la case du tableau de taille (lignes * colonnes) à la i_ème ligne et j_ème colonne

// 2) une structure pour représenter le serpent qui grandit et qui change de position...
//      * à vous de réfléchir (il n'y a pas de solution unique idéale)
//      (vous pouvez utiliser un std::vector<???> pour stocker les positions du serpent ou une deque ou une liste chaînée...)

// 3) quelque chose pour la position de la pomme

// Pour afficher ces états successifs du jeu:
//    0) vous avez créé initialement un board de taille rows x columns de '.' (les caractères représentant le board),
//       un serpent de taille 3 et une pomme (positionnés tous les deux sur le board)
// puis:
//    1) vous ré-initialisez le board avec des '.'
//    2) vous mettez les caractères représentant le serpent dans le vecteur représentant le board
//    3) vous mettez la pomme dans le vecteur représentant le board
//    4) vous affichez le board (qui contient le serpent et la pomme)
//    5) vous attendez une commande ('i', 'k', 'j', 'l' ou 'q')
//    6) vous regardez où vous devez déplacer le serpent
//    7) si tout se passe bien, vous modifiez votre serpent qui éventuellement grandit
//    8) vous recommencez à l'étape 1

// Si la commande échoue, vous affichez un message d'erreur et vous sortez du jeu avec exit(2).

// Ci-dessous des fonctions vides pour vous montrer quelques étapes dans un code qui compile
// mais qui ne fait rien de ce qui est demandé... à vous de tout repenser et tout structurer

// Pour le compiler:
//     g++ main_snake.cpp -o snake
// Pour l'exécuter:
//     ./snake

// Exemple de code:
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // pour exit et rand

void reset_board()
{
    int rows{5};
    int columns{7};
    std::vector<char> tab(rows * columns, '.');
} // qui ré-initialise le board
void generate_apple()
{

} // qui génère une pomme
std::vector<std::pair<int, int>> snake{{2, 2}, {2, 3}, {2, 4}}; // génère le snake
void add_snake_to_board()
{
    tab[snake[0].first * columns + snake[0].second] = 'O';
    // et le corps
    for (int i = 1; i < snake.size(); i++)
    {
        tab[snake[i].first * columns + snake[i].second] = 'o';
    }
} // qui met le serpent sur le board
void add_apple_to_board(int a, int b)
{
    tab[a * columns + b] = '@';
} // qui met la pomme sur le board

void draw_board()
{ // qui affiche le board
    // bien sûr c'est n'importe quoi cette fonction qui affiche des '.' sur 5 lignes et 7 colonnes...
    // Il faut repenser tout le programme pour afficher le board que vous avez créé en début de partie (de la taille désirée)
    // et dans lequel vous aurez mis le serpent et la pomme.
    // Vous pouvez supprimer ou rajouter des fonctions et surtout faire des classes.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << tab[i * columns + j];
        }
        std::cout << std::endl;
    }
}
void print_message(const std::string &msg) // qui affiche un message
{                                   l       // const (pour ne pas modifier le message dans la fonction)
                                           // &     (pour ne pas le recopier on le passe par référence)
    std::cout << msg;
}

// la fonction play_game() qui gère le jeu serait alors une boucle sans fin dans le genre :
void play_game()
{

    // Supposons qu'on dispose d'un board de rows lignes et columns colonnes (ici resp. 5 et 7).
    //                         d'un serpent de taille 3 et d'une pomme

    // Le jeu est alors une boucle sans fin qui:
    //   - attend que le joueur tape sur une touche
    //   - fait l'action demandée
    //   - et recommence ou échoue.

    // Le caractère pour stocker la clé qui sera entrée au clavier.
    char key;
    while (true)
    {
        reset_board();            // on réinitialise le board
        add_snake_to_board();     // on ajoute le serpent au board
        add_apple_to_board(3, 5); // on ajoute la pomme au board
        draw_board();             // on affiche le board
        print_message("what do you want to do ('q' to quit):");

        std::cin >> key; // on attend que l'utilisateur entre un caractère au clavier
        if (key)
        {
            if ((key == 'i') or (key == 'k') or (key == 'j') or (key == 'l'))
            {
                if (key == 'j')
                {
                    if (tab[snake[0].first * columns + (snake[0].second - 1)] == '@') // si ma nouvelle tête est à la place de la pomme
                    {
                        snake.push_front({snake[0].first, snake[0].second - 1}); //rajoute une case à la "tête" de mon serpent
                        add_snake_to_board;
                    }
                    else (){
                        for (int i = 0; i < snake.size() - 1; i++)
                        {
                            snake[snake.size() - 1 - i] = snake[snake.size() - 2 - i];
                        }
                        snake[0].second = snake[0].second - 1;
                        add_snake_to_board();
                    }
                }
                else if (key == 'k')
                {
                    for (int i = 0; i < snake.size() - 1; i++)
                    {
                        snake[snake.size() - 1 - i] = snake[snake.size() - 2 - i];
                    }
                    snake[0].first = snake[0].first + 1
                }
                else if (key == 'i')
                {
                    for (int i = 0; i < snake.size() - 1; i++)
                    {
                        snake[snake.size() - 1 - i] = snake[snake.size() - 2 - i];
                    }
                    snake[0].first = snake[0].first - 1
                }
                else if (key == 'l')
                {
                    for (int i = 0; i < snake.size() - 1; i++)
                    {
                        snake[snake.size() - 1 - i] = snake[snake.size() - 2 - i];
                    }
                    snake[0].second = snake[0].second + 1
                }
            }
            else if (key == 'q')
            {
                print_message("bye bye !\n");
                exit(0); // l'utilisateur demande à quitter le jeu (ou on peut juste écrire return)
            }
            // sinon une clé inconnue a été entrée: on ne fait rien...

            // mais on pourrait ajouter des fonctionnalités par exemple:
            // si l'utilisateur tape 's', vous pouvez sauver l'état du jeu dans un fichier pour le reprendre plus tard
            // et passer le fichier en argument à votre programme pour reprendre le jeu
        }
    }
}

int simple_random(int n) // simple random generation of a integer between 0 and n
{
    return rand() % n;
}

int main(int argc, char **argv)
{
    // exemple où on génère un nombre aléatoire entre 0 et 35
    // (par exemple cela vous donne une case sur un board de 5 lignes 7 colonnes pour y placer une pomme
    //  si il n'y a pas de bout de serpent à cet endroit...)
    std::cout << simple_random(35) << std::endl;

    // Il manque tous les objets (le board, le serpent, la pomme).
    // Dans un premier temps, vous pouvez utiliser des variables globales pour stocker ces objets
    //                        que vous manipulez alors directement dans des fonctions
    // dans un second temps, vous devez proposer une structure de classes
    play_game();
    return 0;
}

// Si vous avez bien avancé, écrivez moi afin que je vous donne le code où le serpent bouge tout-seul dans une direction donnée.
// Et vous changez la direction du serpent uniquement quand c'est utile.