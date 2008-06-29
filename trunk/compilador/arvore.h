#ifndef ARVORE_H_
#define ARVORE_H_
#include <string>

// Lista de compostos. Ser�o usados para retornar os ponteiros at� a raiz da �rvore,
//de um para o outro. 

// Estou cogintando tamb�m usar a pr�pria lista de compostos pra executar a an�lise,
//mas ainda n�o conclu� nada a respeito. 

// OBS.: Coloquei apenas os primeiros da lista, por hora. Essa parte � mais bra�o 
//do que l�gica. 

class raiz{
   public:
      std::string nomePrograma;
      class listaIdentificadores *listaIdentifica;
      class bloco *bloco;
};

class listaIdentificadores{
   public:
      std::string nome;
      listaIdentificadores *next;
};

class bloco{
   public:
      class declaraRotulos *rotulos;
      class defineTipos *defineTipos;
      class declaraVariaveis *variaveis;
      class declaraSubrotinas *subrotinas;
      class comandoComposto *comandoComposto;
};

class declaraRotulos{
   public:
      int numero;
      declaraRotulos *next;
};

class defineTipos{
   public:
      class defineTipo *defineTipo;
      class defineTipos *next;
};

class defineTipo{
   public:
      std::string identificador;
      class tipo *tipo;
};

class tipo{
   public:
      std::string identificador;
      class indice *indice;
      class tipo *tipoArray;
};

class indice{
   public:
      int numero1;
      int numero2;
};
      



#endif
