/*
 * Esta classe possui os seguintes m�todos:
 * 
 * analisadorSintatico(); o cerne desta classe, realiza toda a l�gica de an�lise
 * 
 * void pushPop(); -> atribui o valor mais � esquerda da lista do l�xico � vari�vel 'roller' da class,
 * em seguida exclui este valor da lista 
 *
 * void loadList(std::list<tokentype> loadUp); -> carrega a lista do l�xico
 * 
 *
 * // Daqui em diante, as fun��es visam a an�lise de blocos espec�ficos do c�digo, 
 *    retornando ponteiros da sub�rvore montada. 
 *
 *
 * listaIdentificadores* ASlistaIdentificadores(); -> An�lise sint�tica de lista de identificadores
 * 
 * bloco* ASbloco(); -> An�lise sint�tica de bloco
 * 
 * int isuline(char); -> 
 * 
 * void addtolist(string,line); -> 
 * 
 * 
 * 
 * void printlist(); -> 
 * 
 * void printerror(); -> 
 */
 
 
#ifndef SINTATICO_H_
#define SINTATICO_H_
#include <list>
#include "tokentype.h"
#include "hash.h"
#include "arvore.h"

class sintatico
{
public:
	sintatico();
	virtual ~sintatico();
	
	void pushPop();                          
	void loadList(std::list<tokentype> loadUp);
	void analisador_sintatico();
	
	listaIdentificadores* ASlistaIdentificadores();
	bloco* ASbloco();
	
		
private:
    hash tabelaHash;    
    std::list<tokentype> *lista;
    raiz carvalho;
    
    int nivelLexico,      // Vari�vel guardando o n�vel l�xico
        erro;             // Vari�vel setada quando qualquer erro for encontrado no programa, encerrando sua execu��o   
	tokentype roller;     // tokentype que receber� o token mais � esquerda na lista para an�lise
};

#endif /*SINTATICO_H_*/
