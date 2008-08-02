#include <iostream>
#include <list>
#include "sintatico.h"
#include "tokentype.h"
#include "arvore.h"

using namespace std;

sintatico::sintatico()
{
   nivelLexico = 0;
   erro = 0;
};

////////////////////////////////////////////////////////////////////////////////

sintatico::~sintatico()
{                      
};

////////////////////////////////////////////////////////////////////////////////

void sintatico::loadList(std::list<tokentype> loadUp){
   lista = &loadUp;
};

////////////////////////////////////////////////////////////////////////////////

void sintatico::pushPop(){  
  roller = lista->front();  
  lista->pop_front();
};

////////////////////////////////////////////////////////////////////////////////

//  obs.: o comando "pushPop()" servem para passar para a próxima palavra 
// da lista recebida do léxico.

void sintatico::analisador_sintatico(){

   pushPop();   
   if(roller.nome == "program"){
      pushPop();      
      if(roller.tipo == 1){
         // [check] Analisar se essa linha é necessária, e completar a configuração hash:
         tabelaHash.setHash(roller.nome, "procedimento");
                  
         pushPop();
         if(roller.nome == "("){
            carvalho.listaIdentificadores = ASlistaIdentificadores();
            if(erro){
               // [check] imprimir erro, interromper programa
            }else{                  
               pushPop();
               if(roller.nome == ")"){                  
                  pushPop();                  
                  if(roller.nome == ";"){                  
                     carvalho.listaIdentificadores = ASbloco();
                     if(erro){
                        // [check] imprimir erro, interromper programa
                     }else{
                        // [check] imprimir sucesso?
                     }       
                  }else{
                     // [check] imprimir erro, interromper programa
                  }
               }else
                  // [check] imprimir erro, interromper programa
               }
            }
         }else{
            // [check] imprimir erro, interromper programa
         }                 
      }else{
         // [check] imprimir erro, interromper programa
      }                
   }else{
      // [check] imprimir erro, interromper programa
   }
      
   std::cout << "Under construction. Keep out, MO-FOS!" << std::endl << std::endl;
   system("pause");	
   
};

////////////////////////////////////////////////////////////////////////////////

listaIdentificadores* sintatico::ASlistaIdentificadores(){
  
  listaIdentificadores *listaTemp, *listaScroller;
  int desloca = 0;
    
  pushPop();
  if(roller.tipo == 1){
     // Configurando a entrada hash
     tabelaHash.setHash(roller.nome, "variavel");  
     tabelaHash.setNivel(roller.nome, nivelLexico);
     tabelaHash.setDeslocamento(roller.nome, desloca);
     
     // Configurando entrada da subárvore
     listaTemp->nome = roller.nome;
     listaTemp->next = listaScroller;
          
     pushPop();     
     while(roller.nome != ","){
        pushPop();
        desloca++;
        
        if(roller.tipo == 1){
           tabelaHash.setHash(roller.nome, "variavel");  
           tabelaHash.setNivel(roller.nome, nivelLexico);
           tabelaHash.setDeslocamento(roller.nome, desloca);
                      
           listaScroller->nome = roller.nome;
           listaScroller = listaScroller->next;
           
           pushPop();
        }else{
           erro = 1;
           break;
        }
     }
     listaScroller = NULL;
  }else{
     erro = 1;
  }
     
  return listaTemp;
}; 

////////////////////////////////////////////////////////////////////////////////

bloco* ASbloco(){

   bloco *tempNode;

   pushPop();
   tempNode->rotulos = ASdeclaraRotulos();
   tempNode->defineTipos = ASdefineTipos();
   tempNode->variaveis = ASdeclaraVariaveis();
   tempNode->subrotinas = ASdeclaraSubrotinas();
   tempNode->comandoComposto = AScomandoComposto();   
   if(erro){
      // [check] providencias de erro serão tomadas no método que chamou este.
   }   
   return tempNode;   
};

