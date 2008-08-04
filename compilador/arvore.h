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

// Desnecess�ria
/*class defineTipo{
   public:
      std::string identificador;
      class tipo *tipo;
};
*/

// Desnecess�ria
/*class tipo{
   public:
      std::string identificador;
};*/

// Desnecess�ria
/*class indice{                                             // Na verdade, uma *lista* de indices, para uso em arrays. 
   public:                                                //o ponteiro presente � usado para o caso de haver mais de 
      int numero1;                                        //um �ndice no array. 
      int numero2;
      indice *next;    
};
*/
class declaraVariaveis{                                   // "Parte de declara��es de vari�veis" 
   public:                                                //e "declara��es de vari�veis" foram   
      class listaIdentificadores *listaIdentificadores;   //fundidas.
      std::string tipoIdentificadores;
      class declaraVariaveis *next;
};

class declaraSubrotinas{
   public:
      class declaraProcedimento *declaraProcedimento;
      class declaraFuncao *declaraFuncao;
};

class declaraProcedimento{
   public:
      std::string identificador;
      class parametrosFormais *parametrosFormais;
      class bloco *bloco;
      class declaraProcedimento *next;
};

class declaraFuncao{
   public:
      std::string identificadorFuncao;
      class parametrosFormais *parametrosFormais;
      std::string identificador;
      class bloco *bloco;
      class declaraFuncao *next;
};

class parametrosFormais{
   public:
      class listaIdentificadores *listaIdentificadores;
      std::string identificador12;
      class parametrosFormais *next;
};

class comandoComposto{
   public:
      class comando *comando;
      class comandoComposto *next;
};

class comando{
   public:
      //class numero *numero;                              // Desnecess�rio
      class comandoSemrotulo *comandoSemrotulo;
};

class numero{                                              // Classe criada apenas para 
   public:                                                 //gerar uma lista de n�meros.   
      int numero;
      class numero *next;
};

class comandoSemrotulo{
   public:
      class atribuicao *atribuicao;
      class chamadaProcedimento *chamadaProcedimento;
      //class desvio *desvio;                              // Desnecess�rio
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
      std::string operador;
      class termo *termo;
      class expressaoSimples *next;
};

class termo{                                //  Originalmente a classe tem tr�s elementos:
   public:                                  // fator, um conector (*|div|and) e outro fator.
      class fator *fator;                   // Como v�rios deles podem ser conectados em fila,
      std::string conector;                 // vamos considerar apenas os dois elementos presentes,
      class termo *next;                    // e o terceiro estar� na classe "termo *next". 
};

class fator{                                // O atributo 'numero' foi passado para o final para    
   public:                                  //facilitar a an�lise, futuramente, quanto a qual campo
      class variavel *variavel;             //est� preenchido - apenas um deles por vez.
      class chamadaFuncao *chamadaFuncao;
      class expressao *expressao;
      class fator *fator;
      std::string negacao,      
                 numero,
                 abreChave,
                 fechaChave;      
};

class variavel{
   public:
      std::string identificador;
      class listaExpressoes *listaExpressoes;
};

class chamadaFuncao{
   public:
      std::string identificador;
      class listaExpressoes *listaExpressoes;
};

#endif
