#ifndef SINTATICO_H_
#define SINTATICO_H_
#include "tokentype.h"
#include "hash.h"

class sintatico
{
public:
	sintatico(std::list<tokentype> loadUp);
	virtual ~sintatico();
	
	void analisador_sintatico();
	
	
	
	
	
private:
    hash tabelaHash;    
    std::list<tokentype> *lista;
    //arvore carvalho;
    
	
};

#endif /*SINTATICO_H_*/
