#include "zad01h.h"

using namespace std;

int main(int argc, char *argv[])
{
    Klasa k1; 
      Klasa k2(1, 1.5, 'b'); 
      Klasa k3(k2); 
      Klasa *wk = new Klasa; 
      wk->setInt(2); 
      wk->setFloat(1.5); 
      wk->setChar('c'); 
      cout << "Wywolanie WriteOut(KeyboardInput())" << endl; 
      WriteOut(KeyboardInput()); 
      cout << "Obiekt k1:" << endl; 
      k1.WriteAll(); 
      cout << "Obiekt k2:" << endl; 
      k2.WriteAll(); 
      cout << "Obiekt k3:" << endl; 
      k3.WriteAll(); 
      cout << "Obiekt dynamiczny wk dostep wskaznikiem:" << endl; 
      wk->WriteAll(); 
      cout << "Obiekt dynamiczny wk dostep jak do obiektu:" << endl; 
      (*wk).WriteAll(); 
      delete wk;
      return 0; 
}