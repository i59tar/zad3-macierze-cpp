#include "zad06main.h"

using namespace std;


int main(){
      int i; 
      Vector v1(10); 
      for (i=0; i<v1.get_size(); i++) v1[i] = i; 
      Vector v2(v1), v3; 
      v3 = v2; 
      v3[2] = 5.5; 
      cout << "v1 = " << v1 << endl << "v2 = " << v2 
     << endl << "v3 = " << v3 << endl; 
      if (v1 == v2) cout << "v1 == v2" << endl; 
      if (v1 != v3) cout << "v1 != v3" << endl; 
      v1.set_size(15); 
      v1.dodaj(34.56);
      cout << "podaj v2 = "; 
      cin >> v2; 
      cout << "v1 = " << v1 << endl << "v2 = " << v2 <<endl;
      SVector sv1(10); 
      for (i=0; i<sv1.get_size(); i++) sv1[i] = i;
	cout<<sv1<<endl;

return 0;
}

