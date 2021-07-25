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
        this->atual = 0;
        for (int i=0;i<other.atual;i++)
        {
            this->empilha(other.tab[i]);
        }
        return *this;
    }

    PilhaInt &operator<<(const int &other)
    {
        this->empilha(other);
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

    void print(ostream &output_stream)
    {
        output_stream << "[ ";
        for (int i = 0; i < atual; i++)
        {
            output_stream << tab[i] << ((i != atual - 1) ? (", ") : (" "));
        }
        output_stream << "]";
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
    // ########################
    PilhaInt p1;
    p1.empilha(10);
    assert(p1.desempilha() == 10);

    // ########################
    PilhaInt p2;
    p2.empilha(8);
    p2.empilha(9);
    p2.empilha(10);
    assert(p2.desempilha() == 10);
    assert(p2.desempilha() == 9);
    assert(p2.desempilha() == 8);

    // ########################
    PilhaInt p3;
    p3 << 19 << 18 << 17;
    p3 << 30;
    stringstream buffer3;
    buffer3 << p3.desempilha() << "," << p3.desempilha() << ","
            << p3.desempilha() << "," << p3.desempilha() << endl;
    assert(buffer3.str() == "30,17,18,19\n");

    // #########################
    PilhaInt p4;
    stringstream buffer4;
    p4 << 19 << 18 << 17 << 30;

    p4.print(buffer4);
    buffer4 << endl;
    assert(buffer4.str() == "[ 19, 18, 17, 30 ]\n");

    // #########################
    PilhaInt p5;
    p5 << 19 << 18 << 17 << 30;

    stringstream ss;
    p5.print(ss);
    stringstream buffer5;

    buffer5 << "{" << ss.str() << "}" << endl;
    assert(buffer5.str() == "{[ 19, 18, 17, 30 ]}\n");

    // ##########################
    PilhaInt p6, q6;
    q6 << 2;
    p6 << 19 << 18 << 17 << 30;
    q6 = p6;
    p6.desempilha();
    q6 << 7;
    stringstream ssp, ssq;
    p6.print(ssp);
    q6.print(ssq);

    stringstream buffer6;
    buffer6 << "q = " << ssq.str() << "\n"
            << "p = " << ssp.str() << endl;
    assert(buffer6.str() == "q = [ 19, 18, 17, 30, 7 ]\np = [ 19, 18, 17 ]\n");
}

// ========================== End - Debug Session ==========================
