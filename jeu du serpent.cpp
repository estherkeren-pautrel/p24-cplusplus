#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // pour exit et rand

void reset_board()
{
} // qui ré-initialise le board

int rows{5};
int columns{7};
std::vector<char> tab(rows * columns, '.');
std::vector<std::pair<int, int>> snake{{2, 2}, {2, 3}, {2, 4}};

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

void print_message(const std::string &msg) // qui affiche un message
{                                          // const (pour ne pas modifier le message dans la fonction)
                                           // &     (pour ne pas le recopier on le passe par référence)
    std::cout << msg;
}

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

void play_game()
{

    // Le caractère pour stocker la clé qui sera entrée au clavier.
    char key;
    while (true)
    {
        reset_board();            // on réinitialise le board
        add_snake_to_board(); // on ajoute le serpent au board
        add_apple_to_board(2, 1); // on ajoute la pomme au board
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
                        tab[snake[0].first * columns + (snake[0].second - 1)] = 'O';
                        snake[1] = snake[0];
                        snake.push_back({snake[snake.size() - 1].first, snake[snake.size() - 1].second + 1}); //snake.insert(0,{snake[0].first, snake[0].second - 1}); //rajoute une case à la "tête" de mon serpent - voir comment marche "insert"...
                        add_snake_to_board();
                    }
                    else {
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
                    snake[0].first = snake[0].first + 1;
                }
                else if (key == 'i')
                {
                    for (int i = 0; i < snake.size() - 1; i++)
                    {
                        snake[snake.size() - 1 - i] = snake[snake.size() - 2 - i];
                    }
                    snake[0].first = snake[0].first - 1;
                }
                else if (key == 'l')
                {
                    for (int i = 0; i < snake.size() - 1; i++)
                    {
                        snake[snake.size() - 1 - i] = snake[snake.size() - 2 - i];
                    }
                    snake[0].second = snake[0].second + 1;
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


int main ()
{             
    play_game();
    return 0;
}