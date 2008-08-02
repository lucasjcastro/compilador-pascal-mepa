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
      class listaIdentificadores *listaIdentificadores;
      class bloco *bloco;
};

class listaIdentificadores{
   public:
      std::string nome;
      class listaIdentificadores *next;
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

class indice{                                             // Na verdade, uma *lista* de indices, para uso em arrays. 
   public:                                                //o ponteiro presente é usado para o caso de haver mais de 
      int numero1;                                        //um índice no array. 
      int numero2;
      indice *next;    
};

class declaraVariaveis{                                   // "Parte de declarações de variáveis" 
   public:                                                //e "declarações de variáveis" foram   
      class listaIdentificadores *listaIdentificadores;   //fundidas.
      class tipo *tipoIdentificadores;
      class declaraVariaveis *next;
};

class declaraSubrotinas{
   public:
      class declaraProcedimento *declaraProcedimento;
      class declaraFuncao *declaraFuncao;
      class declaraSubrotinas *next;
};

class declaraProcedimento{
   public:
      std::string identificador;
      class parametrosFormais *parametrosFormais;
      class bloco *bloco;
};

class declaraFuncao{
   public:
      std::string identificadorFuncao;
      class parametrosFormais *parametrosFormais;
      std::string identificador;
      class bloco *bloco;
};

class parametrosFormais{
   public:
      class secaoParametrosFormais *secaoParametrosFormais;
      class parametrosFormais *next;
};
       
class secaoParametrosFormais{
   public:
      class listaIdentificadores *listaIdentificadores;
      std::string identificador12;
};

class comandoComposto{
   public:
      class comando *comando;
      class comandoComposto *next;
};

class comando{
   public:
      class numero *numero;
      class comandoSemrotulo *comandoSemrotulo;
};

class numero{                                              // Classe criada apenas para 
   public:                                                 //gerar uma lista de números.   
      int numero;
      class numero *next;
};

class comandoSemrotulo{
   public:
      class atribuicao *atribuicao;
      class chamadaProcedimento *chamadaProcedimento;
      class desvio *desvio;
      class comandoComposto *comandoComposto;
      class comandoCondicional *comandoCondicional;
      class comandoRepetitivo *comandoRepetitivo;
};

class atribuicao{
   public:
      class variavel *variavel;
      class expressao *expressao;
};

class chamadaProcedimento{
   public:
      std::string identificador;
      class listaExpressoes *listaExpressoes;
};

class desvios{
   public:
      int numero;
};

class comandoCondicional{
   public:
      class expressao *expressao;
      class comandoSemrotulo *entao;
      class comandoSemrotulo *senao;
};

class comandoRepetitivo{
   public:
      class expressao *expressao;
      class comandoSemrotulo *comandoSemrotulo;
};

class listaExpressoes{
   public:
      class expressao *expressao;
      class listaExpressoes *next;
};

class expressao{
   public:
      class expressaoSimples *primeiraSimples;
      std::string relacao;
      class expressaoSimples *segundaSimples;
};

class expressaoSimples{
   public:
      char operador;
      class termo *primeiroTermo;
      class expressaoSimples *next;
};

class termo{                                //  Originalmente a classe tem três elementos:
   public:                                  // fator, um conector (*|div|and) e outro fator.
      class fator *fator;                   // Como vários deles podem ser conectados em fila,
      std::string conector;                 // vamos considerar apenas os dois elementos presentes,
      class termo *sequencia;               // e o terceiro estará na classe "termo *sequencia". 
};

class fator{                                // O atributo 'numero' foi passado para o final para    
   public:                                  //facilitar a análise, futuramente, quanto a qual campo
      class variavel *variavel;             //está preenchido - apenas um deles por vez.
      class chamadaFuncao *chamadaFuncao;
      class expressao *expressao;
      class fator *fator;
      int numero;
};

class variavel{
   public:
      std::string identificador;
      class listaExpressao *listaExpressao;
};

class chamadaFuncao{
   public:
      std::string identificador;
      class listaExpressao *listaExpressao;
};

#endif
