//s'entraîner à gérer la nouvelle zone mémoire

int main(){
    int i = 12;
    {int* pi = new int{12}; //initialisation d'un pointeur vers un entier (qui est en mémoire dynamique) - il me renvoie l'adresse pour qu'on sache où est cette taille mémoire
    *pi = 17; 
    delete pi; //cela supprime la place dans la mémoire dynamique 
    } 
    //memory leak : fuite mémoire
    return 0;
}

//valgrind ./a.out pour avoir le résumer des fuites et de ce qu'il y a en leak 
//mémoire dynamique : heap
