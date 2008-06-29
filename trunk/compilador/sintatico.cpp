#include <iostream>
#include <list>
#include "sintatico.h"
#include "tokentype.h"

using namespace std;

sintatico::sintatico()
{
};

sintatico::~sintatico()
{                      
};

void sintatico::loadList(std::list<tokentype> loadUp){
   lista = &loadUp;
};


void sintatico::analisador_sintatico(){
      
   std::cout << "Under construction. Keep out, MO-FOS!" << std::endl << std::endl;
   system("pause");	
   
};
