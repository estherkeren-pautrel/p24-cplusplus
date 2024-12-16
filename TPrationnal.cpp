#include <iostream>
class Rational {

    // vr: c++ ne reconnaît pas la fonction operator+ que tu définis plus bas parce que les arguments sont passés const:
    // il faut que le prototype de la fonction (type de retour et liste des arguments) soit exactement le même que dans la définition
    friend Rational operator+ (const Rational& r1, const Rational& r2) ;//déclare friend - elle choisit ses amis - fonctions copines
    
    // vr: idem c++ ne reconnaît pas la fonction operator<< définie plus bas il manque le type de retour
//    friend operator<< (std::ostream& os, const Rational& r) ;
    friend std::ostream& operator<< (std::ostream& os, const Rational& r) ;
    // elle retournera une référence vers l'ostream passée en argument (et qui a été augmentée de ce que tu écris dans la fonction)
    
    private:
        int num;
        int den;
    public:
    Rational (int p = 0, int q = 1): //on doit faire une initialisation, pas une affectation!
        num(p),
        den(q){if (den == 0) {throw 1;}}
    void print () {
        std::cout << num << "/" << den << std::endl;
        }
    void print (std::ostream& os) {
        os << num << "/" << den << std::endl;
        }
    float eval() {
        return(static_cast<float>(num)/den);
        }

    };
// Rational operator+ (Rational& r1, Rational& r2){ //on veut redéfinir le + : surcharge des opérateurs pour un type
//     return Rational ((r1.num*r2.den + r2.num*r1.den)/(r1.den + r2.den));
// }

// vr: je modifie
Rational operator+ (const Rational& r1, const Rational& r2){ //on veut redéfinir le + : surcharge des opérateurs pour un type
    return Rational ((r1.num*r2.den + r2.num*r1.den), (r1.den + r2.den));
}

std::ostream& operator<< (std::ostream& os, const Rational& r) {
    os<<'[' <<r.num/r.den<<']';
    return os;
}

int main() {
    Rational r1; // renvoie 0/1
    Rational r2(15,2); 
    Rational r3(1);
    r1.print();
    std::cout << r2.eval() << std::endl;
    r3.print();
    Rational& rr1 = r1; //référence de l'objet (donc va simplement regarder l'objet)
    Rational& rr2 = r2;
    std::cout << (r3 + r2) << std::endl;
    return 0;
}






//implement a global function for equality test (a/b == c/d if a ∗ d == b ∗ c)
//implement a function to compute a floating point approximation (to_float) of your rational
//be careful with the integer division (use the explicit c++ conversion static_cast if needed)
//Rational operator+ (const Rational& r1, Rational& r2) -  &:référence // const: passer constant r1, on ne veut pas le modifier, que le lire
//operator+ passe par copie - on peut passer par références, référence c'est comme un pointeur, on est directement sur l'objet, ne fonctionne pas par copie!