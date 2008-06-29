#include <iostream>
#include <fstream>
#include <string>
#include "lexico.h"
#include "hash.h"
//#include "sintatico.h"

int main(int argc, char* argv[]){
	///TESTE DE HASH DAQUI...
    hash testoe;
    string palavra1, 
           palavra2, 
           palavra3, 
           palavra4,
           resultado;
    
    palavra1 = "teste de banco";
    palavra2 = "parametro";
    
    palavra3 = "Tudo em ordem?";
    palavra4 = "variavel";
    
    
    testoe.setHash(palavra1, palavra2);
    resultado = testoe.getCategoria(palavra1);
    
    cout << "Resultado da busca por " << palavra1 << " deu " << resultado << endl;    
    system("pause");    


    /// ATÉ AQUI.
    std::string filename = argv[1];
    
	lexico comp;
	sintatico testoe;
	
	comp.analisador_lexico(filename);
	//comp.printerror();
	//comp.printlist();
	//comp.printtype();
	testoe = new lista(comp.getLista());
	testoe.analisador_sintatico();
	
	return 0;
}
