#include <iostream>
#include <fstream>
#include <string>
#include "lexico.h"

int main(int argc, char* argv[]){
	std::string filename = argv[1];


	lexico comp;
	comp.analisador_lexico(filename);
	comp.printerror();
	comp.printlist();
	comp.printtype();
	return 0;
}
