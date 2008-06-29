#ifndef SINTATICO_H_
#define SINTATICO_H_
#include <list>
#include "tokentype.h"
#include "hash.h"

class sintatico
{
public:
	sintatico();
	virtual ~sintatico();
	
	void loadList(std::list<tokentype> loadUp);
	void analisador_sintatico();
	
		
private:
    hash tabelaHash;    
    std::list<tokentype> *lista;
    //arvore carvalho;
    
	
};

#endif /*SINTATICO_H_*/
