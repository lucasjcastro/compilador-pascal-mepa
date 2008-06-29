#ifndef ARVORE_H_
#define ARVORE_H_
#include <string>

// Lista de compostos. Serão usados para retornar os ponteiros até a raiz da árvore,
//de um para o outro. 

// Estou cogintando também usar a própria lista de compostos pra executar a análise,
//mas ainda não concluí nada a respeito. 

// OBS.: Coloquei apenas os primeiros da lista, por hora. Essa parte é mais braço 
//do que lógica. 

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
