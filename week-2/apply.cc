
// ========================= Start - Import Session =========================
#include <bits/stdc++.h>
#include <iostream>
#include <initializer_list>

#define assert(e) print_assert(e, #e, __FILE__, __LINE__)
#define veccmpeq(a, b) equal(a.begin(), a.end(), b.begin())

// ========================== End - Import Session ==========================

// ========================= Start - Code Session =========================
using namespace std;

template <typename A, typename B, typename C>
vector<B> apply(vector<A> iterable, B (*f)(C))
{
    vector<B> v;
    for (auto x : iterable)
    {
        v.push_back(f((C)x));
    }
    return v;
}

template <typename A, typename B, typename C>
vector<B> apply(A arr[], B (*f)(C))
{
    // i wasn't able to identify the size of an unsized array
    int size = 5;

    vector<B> v;
    for (int i=0;i<size;i++)
    {
        v.push_back(f((C)arr[i]));
    }
    return v;
}


template <typename A, typename F>
auto apply(initializer_list<A> iterable, F f)
{
    // gets the type of first produced item. A smart way to get B type
    vector<decltype(f(*iterable.begin()))> v;
    for (auto x : iterable)
    {
        v.push_back(f(x));
    }
    return v;
}

template <typename A, typename F>
auto apply(vector<A, allocator<A>> iterable, F f)
{
    // gets the type of first produced item. A smart way to get B type
    vector<decltype(f(*iterable.begin()))> v;
    for (auto x : iterable)
    {
        v.push_back(f(x));
    }
    return v;
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

int pwr(int a) { return a * a; }
void test1()
{
    vector<int> v{1, 2, 3, 4};
    vector<int> expected{1, 4, 9, 16};
    assert(veccmpeq(expected, apply(v, pwr)));
}

void test2()
{
    vector<int> v{1, 2, 3, 4, 5};
    vector<int> expected{1, 2, 3, 4, 5};
    vector<int> r = ::apply(v, id);
    assert(veccmpeq(expected, r));
}

void test3()
{
    vector<int> v{1, 2, 3, 4, 5};
    vector<double> expected{seno(1), seno(2), seno(3), seno(4), seno(5)};
    vector<double> r = ::apply(v, seno);
    assert(veccmpeq(expected, r));
}

void test4()
{
    auto v = {1, 2, 3, 4, 5};
    auto expected = {1.1, 4.1, 9.1, 16.1, 25.1};
    auto r = ::apply(v, [](auto n) -> double
                     { return n * n + 0.1; });
    assert(veccmpeq(expected, r));
}

void test5()
{
    auto v = vector{vector{1, 3}, {4, 15}, {3, 10}};
    auto expected = {-2, 1, -1};
    auto r = ::apply(v, [](auto lin)
                     { return lin[0] * lin[0] - lin[1]; });
    assert(veccmpeq(expected, r));
}

void test6()
{
    auto a = {1, 2}, b = {3, 4};
    stringstream buffer;
    buffer << ::apply(a, [b](auto x)
                      { return ::apply(b, [x](auto y)
                                       { return vector{x, y}; }); });
    assert(buffer.str() == "[ [ [ 1 3 ] [ 1 4 ] ] [ [ 2 3 ] [ 2 4 ] ] ]");
}

void test7()
{
    stringstream buffer;
    buffer << ::apply(vector{1, 2, 3}, FunctorSimples());
    assert(buffer.str() == "[ I! II! III! ]");
}

void test8()
{
    int v[] = {1, 2, 3, 4, 5};
    vector<int> expected{1, 2, 3, 4, 5};
    vector<int> r = ::apply(v, id);
    assert(veccmpeq(expected, r));
}

void test9()
{
    int v[] = {1, 2, 3, 4, 5};
    vector<string> expected{"I", "II", "III", "IV", "V"};
    vector<string> r = ::apply(v, roman);
    assert(veccmpeq(expected, r));

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
