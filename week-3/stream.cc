
// ========================= Start - Import Session =========================
#include <bits/stdc++.h>
#include <iostream>
#include <initializer_list>

#define assert(e) print_assert(e, #e, __FILE__, __LINE__)
#define veccmpeq(a, b) equal(a.begin(), a.end(), b.begin())

// ========================== End - Import Session ==========================

// ========================= Start - Code Session =========================
using namespace std;


template<class FWIt, typename F>
void func(FWIt a, const FWIt b, F f)
{
    while (a != b)
    {
        f(*a);
        ++a;
    }
}

template <typename A, typename B>
void operator|(const A& iterable, B f)
{
    auto x = begin(iterable);
    auto y = end(iterable);
    func(x, y, f);
}

// ========================== End - Code Session ==========================

// ========================= Start - Debug Session =========================

double seno(double n) { return sin(n); }
int id(int n) { return n; }
string roman(int n)
{
    map<int, string> rom = {{1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}};

    return rom[n];
}

struct FunctorSimples
{
    string operator()(int n) { return roman(n) + "!"; }
};

struct FunctorTemplate
{
    template <typename T>
    T operator()(T n) { return n + n; }
};

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v)
{
    o << "[ ";
    for (auto x : v)
        o << x << " ";

    return o << "]";
}

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



void print(int x) { cout << x << " "; }
void test10()
{
    int tab[10] =  { 1, 2, 3, 2, 3, 4, 6, 0, 1, 8 };
    vector<int> v{ 2 , 6, 8 };
    tab | []( int x ) { cout << x*x << endl; };
    tab | [ &v ]( int x ) { v.push_back( x ); };
    v | []( int x ) { cout << x*x << endl; };
    v | &print;
}

void test11()
{
}

void test12()
{
}

void test13()
{
}

void test14()
{
}

void test15()
{
}

void test16()
{
}

void test17()
{
}

void test18()
{
}

void test19()
{
}

int main()
{
    test10();
    test11();
    test12();
    test13();
    test14();
    test15();
    test16();
    test17();
    test18();
    test19();
}

// ========================== End - Debug Session ==========================
