#include <iostream>
class Rational {
    friend Rational operator+ (const Rational& r1, const Rational& r2) ;//déclare friend - elle choisit ses amis - fonctions copines
    //friend operator<< (std::ostream& os, const Rational& r) ;
    public:
        int num;
        int den;
    public:
    Rational (int p = 0, int q = 1): //faut faire une initialisation pour nous, pas une affectation!
        num(p),
        den(q){if (den == 0) {throw 1;}}
    void print () {
        std::cout << num << "/" << den << std::endl;
        }
    //void print (std::ostream& os) {
      //  os << num << "/" << den << std::endl;
        //}
    float eval() {
        return(static_cast<float>(num)/den);
        }
    };

//Rational operator+ (const Rational& r1, Rational& r2) -  &:référence // const: passer constant r1, on ne veut pas le modifier, que le lire

Rational operator+ (Rational& r1, Rational& r2){ //on veut redéfinir le + : surcharge des opérateurs pour un type
    return Rational ((r1.num*r2.den + r2.num*r1.den),(r1.den + r2.den));
}

//Rational compare (const Rational& r1, const Rational& r2){}

std::ostream& operator<< (std::ostream& os, const Rational& r) {
    os<<'[' <<r.num/r.den<<']';
    return os;
}

int main() {
    Rational r1; // renvoie 0/1
    Rational r2(15,2); // renvoie 1/1
    Rational r3(1);
    r1.print();
    std::cout << r2.eval() << std::endl;
    r3.print();
    Rational& rr1 = r1;
    Rational& rr2 = r2;
    std::cout << operator+ (rr1, rr2) << std::endl;
    return 0;
}


//implement a global function for equality test (a/b == c/d if a ∗ d == b ∗ c)
//implement a function to compute a floating point approximation (to_float) of your rational
//be careful with the integer division (use the explicit c++ conversion static_cast if needed)

//operator+ passe par copie - on peut passer par références, référence c'est comme un pointeur, on est directement sur l'objet, ne fonctionne pas par copie!