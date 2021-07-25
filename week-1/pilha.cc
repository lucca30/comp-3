// ========================= Start - Code Session =========================
#include <bits/stdc++.h>
#include <iostream>
#define assert(e) print_assert(e, #e, __FILE__, __LINE__)

// ========================== End - Code Session ==========================

// ========================= Start - Code Session =========================
#define MAX_PILHA 10
using namespace std;

class PilhaInt
{
public:
    PilhaInt()
    {
        atual = 0;
        for (int i = 0; i < MAX_PILHA; i++)
        {
            tab[i] = 0;
        }
    }

    PilhaInt &operator=(const PilhaInt &other)
    {
        return *this;
    }

    void empilha(int val)
    {
        tab[atual++] = val;
    }

    int desempilha()
    {
        return tab[--atual];
    }

    void print(ostream &output_stream, const char *msg)
    {
    }

private:
    int tab[MAX_PILHA];
    int atual;
};

// ========================== End - Code Session ==========================

// ========================= Start - Debug Session =========================

void print_assert(int success, const char *expression, const char *file, int line)
{
    if (success)
    {
        cout << "Passed!!" << endl;
    }
    else
    {
        cout << "Expression " << expression << " failed at " << line << " line." << endl;
    }
}

int main()
{
    PilhaInt p1;
    p1.empilha(10);
    assert(p1.desempilha() == 10);

    PilhaInt p2;
    p2.empilha(8);
    p2.empilha(9);
    p2.empilha(10);
    assert(p2.desempilha() == 10);
    assert(p2.desempilha() == 9);
    assert(p2.desempilha() == 8);

}

// ========================== End - Debug Session ==========================
