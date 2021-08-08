#include <iostream>
#include <string.h>
using namespace std;
template <typename T> 
 T Max( T a,  T b ) {
  cout << "here1" << endl;
  return a > b ? a : b;
}

template <>
const char* Max( const char* a, const char* b ) {
  cout << "here2" << endl;
  return strcmp( a, b ) > 0 ? a : b;
}

int main() {
  
  
  // Dedução automática
  cout << Max( 1.4, 1.6 ) << endl; 
  
  // Instanciação explícita
  cout << Max<double>( 1.4, 1 ) << endl;
  
  // Agora funciona corretamente
  cout << Max( "Alfa", "Beta" ) << endl;
}
