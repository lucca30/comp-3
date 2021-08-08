// ========================= Start - Import Session =========================
#include <bits/stdc++.h>
#include <iostream>
#define assert(e) print_assert(e, #e, __FILE__, __LINE__)

// ========================== End - Import Session ==========================

// ========================= Start - Code Session =========================
using namespace std;

class PilhaInt
{
public:
    PilhaInt(int n = 10)
    {
        atual = 0;
        tab = vector<int>();
        size = n;
    }

    PilhaInt(const PilhaInt &old)
    {
        atual = 0;
        size = old.size;
        tab = vector<int>();
        for (int i = 0; i < old.atual; i++)
        {
            empilha(old.tab[i]);
        }
    }

    ~PilhaInt()
    {
        tab.clear();
    }

    PilhaInt &operator=(const PilhaInt &other)
    {
        // self assignment check
        if (this != &other)
        {
            atual = 0;
            if (size != other.size)
            {
                size = other.size;
            }
            tab.clear();
            tab = vector<int>();

            for (int i = 0; i < other.atual; i++)
            {
                empilha(other.tab[i]);
            }
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
        if (atual == capacidade())
            redimensiona(capacidade() * 2);
        atual++;
        tab.push_back(val);
    }

    int desempilha()
    {
        int val = tab[--atual];
        tab.pop_back();
        return val;
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

    int capacidade()
    {
        return size;
    }

    void redimensiona(int n)
    {
        if (n <= size)
        {
            if (n <= atual)
            {
                atual = n;
                // Do I need to actually reduce the tab size?
            }
        }
        else
        {
            vector<int> new_tab;
            for (int i = 0; i < atual; i++)
            {
                new_tab.push_back(tab[i]);
            }
            tab.clear();
            tab = new_tab;
        }
        size = n;
    }

    // similar method used int the tests
    PilhaInt embaralha_(PilhaInt q)
    {
        int aux = q.desempilha();
        q << 32 << 9 << aux;

        return q;
    }

private:
    vector<int> tab;
    int atual;
    int size;
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

void test1()
{
    PilhaInt p1;
    p1.empilha(10);
    assert(p1.desempilha() == 10);
}

void test2()
{
    PilhaInt p2;
    p2.empilha(8);
    p2.empilha(9);
    p2.empilha(10);
    assert(p2.desempilha() == 10);
    assert(p2.desempilha() == 9);
    assert(p2.desempilha() == 8);
}

void test3()
{
    PilhaInt p3;
    p3 << 19 << 18 << 17;
    p3 << 30;
    stringstream buffer3;
    buffer3 << p3.desempilha() << "," << p3.desempilha() << ","
            << p3.desempilha() << "," << p3.desempilha() << endl;
    assert(buffer3.str() == "30,17,18,19\n");
}

void test4()
{
    PilhaInt p4;
    stringstream buffer4;
    p4 << 19 << 18 << 17 << 30;

    p4.print(buffer4);
    buffer4 << endl;
    assert(buffer4.str() == "[ 19, 18, 17, 30 ]\n");
}

void test5()
{
    PilhaInt p5;
    p5 << 19 << 18 << 17 << 30;

    stringstream ss;
    p5.print(ss);
    stringstream buffer5;

    buffer5 << "{" << ss.str() << "}" << endl;
    assert(buffer5.str() == "{[ 19, 18, 17, 30 ]}\n");
}

void test6()
{
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

void test7()
{
    PilhaInt p6;
    p6 << 19 << 18 << 17 << 30;
    PilhaInt q6(p6);
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

void test8()
{
    PilhaInt p(5);
    p << 1 << 2 << 3 << 4 << 5;
    assert(p.capacidade() == 5);
    p << 6;
    assert(p.capacidade() == 10);

    p.redimensiona(6);
    assert(p.capacidade() == 6);
    stringstream buffer;
    p.print(buffer);
    assert(buffer.str() == "[ 1, 2, 3, 4, 5, 6 ]");

    p.redimensiona(5);
    assert(p.capacidade() == 5);
    stringstream buffer2;
    p.print(buffer2);
    assert(buffer2.str() == "[ 1, 2, 3, 4, 5 ]");
}

void test9()
{
    PilhaInt a{7};
    a << 8 << 3 << 1 << 4 << 5;
    a = a;
    stringstream buffer;
    a.print(buffer);
    buffer << endl;
    assert(buffer.str() == "[ 8, 3, 1, 4, 5 ]\n");
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
}

// ========================== End - Debug Session ==========================
