#ifndef HASH_H_
#define HASH_H_
#include <iostream>
#include <map>

using namespace std;

class hashCell{
      public:
         hashCell(string id, string cat);
         
         string getIdentificador();
         string getCategoria();
         int getNivel();
         string getTipo();
         int getDeslocamento();
         int getPassagem();
         string getRotulo();
         int getN();
      
         void setNivel(int nivelValue);
         void setTipo(string tipoValue);
         void setDeslocamento(int deslocamentoValue);
         void setPassagem(int passagemValue);
         void setRotulo(string rotuloValue);
         void setN(int nValue);
                  
         hashCell *next;
                  
      private:
                  
         string identificador;
         string categoria;   //Categorias 'variavel', 'parametro' ou 'procedimento'
         int nivel;
          
         //CHECAR
         string tipo;
         int deslocamento;
         int passagem;
         string rotulo;
         int n;            

};


class hash{
      public:
         hash();
         
         int getHashNumba(string palavra);
         void setHash(string palavra, string categoria);     //1. Variável simples, 2. Parâmetro formal, 3. Procedimento  
                  
         string getCategoria(string palavra);
         int getNivel(string palavra);
         string getTipo(string palavra);
         int getDeslocamento(string palavra);
         int getPassagem(string palavra);
         string getRotulo(string palavra);
         int getN(string palavra);
         
         void setNivel(string palavra, int nivel);
         void setTipo(string palavra, string tipo);
         void setDeslocamento(string palavra, int deslocamento);
         void setPassagem(string palavra, int passagem);
         void setRotulo(string palavra, string rotulo);
         void setN(string palavra, int n);
         
         
      private:
         map<int, hashCell *>  hashTable;
         
         int HASHBIAS,
             HASHMAX;
         
};
#endif
