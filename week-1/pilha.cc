#include <iostream>
using namespace std;
class PilhaInt
{
public:
    PilhaInt()
    {
        atual = 0;
    }
    void empilha(int valor)
    {
        tab[atual++] = valor;
    }
    int desempilha()
    {
        return tab[--atual];
    }
    void print(std::ostream &o)
    {
        o << "[ ";
        for (int i=0; i<this->atual;i++ )
        {
            o << this->tab[i];
            if(i < this->atual-1) o << ", ";
        }
        o << " ]";
    }
    const PilhaInt &operator=(const PilhaInt &p)
    {
        atual = p.atual;
        for (int i = 0; i < atual; i++)
            tab[i] = p.tab[i];
        return *this;
    }
    PilhaInt &operator<<(int valor)
    {
        empilha(valor);
        return *this;
    }

private:
    int atual;
    int tab[1000];
};

int main()
{
    PilhaInt a;
    a.empilha(1);
    a.empilha(2);
    a.empilha(3);
    a.print(cout);
    int x1 = a.desempilha();
    int x2 = a.desempilha();
    int x3 = a.desempilha();
}
