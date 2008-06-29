/*
 * Esta classe possui os seguintes m�todos:
 * 
 * void analisador(string); o cerne desta classe, realiza toda a l�gica de an�lise
 * 
 * int ischar(char); -> verifica se par�metro � um caractere. se for retorna 1, sen�o retorna 0
 * 
 * int isnum(char); -> verifica se par�metro � n�mero
 * 
 * int isspecialchar(char); -> verifica se par�metro � caractere especial
 * 
 * int iscomposto(char); -> verifica se caractere pode ser parte de caractere especial composto
 * 
 * int isuline(char); -> verifica se caractere � um underline
 * 
 * void addtolist(string,line); -> realiza a tarefa de armazenar o token na lista, verificando
 * se � um token v�lido e caso seja, a que tipo pertence (identificador, numero,
 * palavra reservada, simbolo especial simples, simbolo especial composto).
 * 
 * void printlist(); -> para imprimir a lista
 * 
 * void printerror(); -> para imprimir erros
 */

#ifndef LEXICO_H_
#define LEXICO_H_

#include <list>
#include "tokentype.h"

class lexico
{
public:
	lexico();
	virtual ~lexico();
	
	void analisador_lexico(std::string);
	int ischar(char);
	int isnum(char);
	int isspecchar(char);
	int iscomposto(char);
	int isinvalid(char);
	int isuline(char);
	void addtolist(std::string, int, int, int);
	void printlist();
	void printerror();
	void printtype();
	
	std::list<tokentype> getLista();
	
private:
	std::list<tokentype> lista;
};

#endif /*LEXICO_H_*/
