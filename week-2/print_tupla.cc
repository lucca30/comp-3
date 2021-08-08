
// ========================= Start - Import Session =========================
#include <bits/stdc++.h>
#include <iostream>
#include <initializer_list>

#define assert(e) print_assert(e, #e, __FILE__, __LINE__)

// ========================== End - Import Session ==========================

// ========================= Start - Code Session =========================
using namespace std;

class AbstractPair
{
public:
    virtual void imprime(ostream &o) = 0;
};

template <typename A, typename B>
class ImplPair : public AbstractPair
{
public:
    ImplPair(A a, B b)
    {
        this->a = a;
        this->b = b;
    }

    void imprime(ostream &o)
    {
        o << this->a << " = " << this->b << endl;
    }

private:
    A a;
    B b;
};

// template <>
// void ImplPair<int, int>::imprime(ostream &o)
// {
//     o << "here" << endl;
// }

class Pair
{
public:
    template <typename A, typename B>
    Pair(A a, B b)
    {
        p = new ImplPair<A,B>(a, b);
    }

    void imprime(ostream &o)
    {
        this->p->imprime(o);
    }

private:
    AbstractPair *p;
};

void print(ostream &o, initializer_list<Pair> lista)
{
    for (auto l : lista)
    {
        l.imprime(o);
    }
}

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
    Pair p("1", 2);
    stringstream buffer;

    print(buffer, {{"jan", 1}, {2, "fev"}, {string("pi"), 3.14}});
    assert(buffer.str() == "jan = 1\n2 = fev\npi = 3.14\n");

}

void test2()
{
}

void test3()
{
}

void test4()
{
}

void test5()
{
}

void test6()
{
}

void test7()
{
}

void test8()
{
}

void test9()
{
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
