#include <iostream>
#include <fstream>
#include <string>
#include "lexico.h"
#include "hash.h"
#include "sintatico.h"
#include "arvore.h"

int main(int argc, char* argv[]){

    std::string filename = argv[1];
    
	lexico comp;
	sintatico run;
	
	comp.analisador_lexico(filename);
	//comp.printerror();
	//comp.printlist();
	//comp.printtype();
	run.loadList(comp.getLista());
	run.analisador_sintatico();
	
	return 0;
}
