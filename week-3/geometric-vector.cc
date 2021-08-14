
// ========================= Start - Import Session =========================
#include <bits/stdc++.h>
#include <iostream>
#include <initializer_list>

#define assert(e) print_assert(e, #e, __FILE__, __LINE__)

// ========================== End - Import Session ==========================

// ========================= Start - Code Session =========================

using namespace std;

template <int n, typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class Vetor
{
public:
    Vetor &operator=(const T &other)
    {
        this->v.push_back(other);
        return *this;
    }
    Vetor &operator,(const T &other)
    {
        this->v.push_back(other);
        return *this;
    }
    Vetor<n, T> operator+(const Vetor<n, T> &other)
    {
        Vetor<n, T> result;
        for (int i = 0; i < n; i++)
        {
            result.v.push_back(this->v[i] + other.v[i]);
        }
        return result;
    }

    Vetor<n, T> operator*(const double other)
    {
        Vetor<n, T> result;
        for (int i = 0; i < n; i++)
        {
            result.v.push_back(this->v[i] * other);
        }
        return result;
    }

    string ToString()
    {
        string ret = "";
        for (int i = 0; i < n; i++)
        {
            string comma = ((i != n - 1) ? (", ") : (" "));
            ret += to_string(this->v[i]) + comma;
        }
        return ret;
    }

private:
    vector<T> v;
};

template <int n, typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
ostream &operator<<(ostream &os, Vetor<n, T> vetor)
{
    os << vetor.ToString() << endl;
    return os;
}

template <int n, typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
Vetor<n, T> operator*(const double other, Vetor<n, T> vetor)
{
    return vetor * other;
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
    Vetor<2, double> v;
    v = 4.5, 6.1;
}

void test2()
{
    Vetor<3, double> a, b;
    a = 0, 0, 1;
    b = 0, 1, 0;
    Vetor<3, double> v;
    v = a + b;
}

void test3()
{
    istringstream oss("6 1 0 10");
    cin.rdbuf(oss.rdbuf());

    Vetor<3, double> a, b;
    int caso = 2;
    double x = 1, y = 0, z = 0;
    cin >> caso >> x >> y >> z;
    a = x, y, z;
    b = 1, 2, 3;
    switch (caso)
    {
    case 1:
        cout << a << endl;
        break;
    case 2:

        cout << a + b << endl;
        break;
    // case 3:
    // {
    //     Vetor<3, double> c;
    //     c = a * *b;
    //     cout << c << endl;
    //     break;
    // }
    // case 4:
    //     cout << a * b << endl;
    //     break;
    case 5:
        cout << a * 3.0 << endl;
        break;
    case 6:
        cout << 2.1 * a << endl;
        break;
        // case 7:
        //     cout << a + b + a * 2.0 << endl;
        break;
    }
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
