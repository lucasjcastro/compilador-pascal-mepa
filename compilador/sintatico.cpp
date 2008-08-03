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
   desloca = 0;
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

string sintatico::comparaTipo(string compare){
      
   if(compare == "integer"){
      return "integer";
   }else if(compare == "char"){ 
       return "char";
   }else if(compare == "boolean"){
       return "boolean";
   }else if(compare == "real"){
       return "real";
   }else if(compare == "word"){
       return "word";
   }else if(compare == "longint"){
       return "longint";
   }else if(compare == "shortint"){
       return "shortint";
   }else if(compare == "byte"){
      return "byte";
   }else if(compare == "string"){
      return "string";
   }else{
      return "erro";
   }
};

////////////////////////////////////////////////////////////////////////////////

//  obs.: o comando "pushPop()" serve para passar para a próxima palavra 
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
            pushPop();
            carvalho.listaIdentificadores = ASlistaIdentificadores();
            if(erro){
               // [check] imprimir erro, interromper programa
            }else{
               if(roller.nome == ")"){                  
                  pushPop();                  
                  if(roller.nome == ";"){    
                     pushPop();              
                     carvalho.bloco = ASbloco();
                     if(erro){
                        // [check] imprimir erro, interromper programa
                     }else{
                        // [check] imprimir sucesso?
                     }       
                  }else{
                     // [check] imprimir erro, interromper programa
                  }
               }else{
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
   //system("pause");	
   
};

////////////////////////////////////////////////////////////////////////////////

listaIdentificadores* sintatico::ASlistaIdentificadores(){
  
  listaIdentificadores *listaTemp, *listaScroller;
  
  desloca = 1;
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

bloco* sintatico::ASbloco(){

   bloco *tempNode;

   //tempNode->rotulos = ASdeclaraRotulos();           // desnecessária
   //tempNode->defineTipos = ASdefineTipos();          // desnecessária
   tempNode->variaveis = ASdeclaraVariaveis();
   tempNode->subrotinas = ASdeclaraSubrotinas();
   //tempNode->comandoComposto = AScomandoComposto();   
   
   if(erro){
      // [check] providencias de erro serão tomadas no método que chamou este.
   }   
   return tempNode;   
};

////////////////////////////////////////////////////////////////////////////////
/*  IGNORADO - NÃO EXIGIDO NO PRESENTE TRABALHO

declaraRotulos* sintatico::ASdeclaraRotulos(){
                
   declaraRotulos *tempNode, *listaScroller;
   int aux;
   
   if(roller.nome == "label"){
      pushPop();
      if(roller.tipo == 2){                     
         // [check] Consertar linha abaixo - converter string pra int            
         //tempNode->numero = roller.nome;
         tempNode->next = listaScroller;
         pushPop();
         while (roller.nome != ","){            
            pushPop();
            if(roller.tipo == 2){
               // [check] Consertar linha abaixo - converter string pra int
               //listaScroller->numero = roller.nome;
               listaScroller = listaScroller->next;               
            }else{
               erro = 1;
               break;
            }
            pushPop();
         }
         listaScroller = NULL;
         if(roller.nome != ";"){
            erro = 1;            
         }else{
            pushPop();
         }
      }else{
         erro = 1;
      }
   }else{
      tempNode = NULL;
   }   
   
   return tempNode;                
};
*/
////////////////////////////////////////////////////////////////////////////////
/* IGNORADO - NÃO EXIGIDO NO PRESENTE TRABALHO  
                              
defineTipos* sintatico::ASdefineTipos(){
             
   defineTipos *tempNode, *listaScroller;
   
   if(roller->nome == "type"){
      pushpop();
      tempNode->defineTipo = 
      
   else{
      tempNode == NULL;
   }
   
   return tempNode;   
};   
*/
////////////////////////////////////////////////////////////////////////////////
   
declaraVariaveis* sintatico::ASdeclaraVariaveis(){
  
   declaraVariaveis *tempNode, *listaScroller;
   listaIdentificadores *listaIDScroller;   
   string holdType;      
      
   if(roller.nome == "var"){
      pushPop();
      tempNode->listaIdentificadores = ASlistaIdentificadores();
      if(erro){
         // [check] providencias de erro serão tomadas no método que chamou este.
         //break;
      }else{
         if(roller.nome == ":"){
            pushPop();
            holdType = comparaTipo(roller.nome);            
            if(holdType == "erro"){
               erro = 1;
            }else{
               tempNode->tipoIdentificadores = holdType;
            }
         }else{
            erro = 1;
         } 
         
         if(!erro){
            //alocar tipos aos identificadores na hash
            listaIDScroller = tempNode->listaIdentificadores;
            while(listaIDScroller != NULL){
               tabelaHash.setTipo(listaIDScroller->nome, holdType);
               listaIDScroller = listaIDScroller->next;
            }
            pushPop();
            if(roller.nome == ";"){
               
               // Desse ponto em diante, o programa começará a olhar por uma segunda,
               //terceira, n-ésima lista de declarações.
               pushPop();       
               tempNode->next = listaScroller;          
               while (roller.nome != "procedure" && roller.nome != "function" && roller.nome != "begin" && erro == 0){
                  listaScroller->listaIdentificadores = ASlistaIdentificadores();
                  if(erro){
                     // [check] providencias de erro serão tomadas no método que chamou este.
                      //break;
                  }else{
                     if(roller.nome == ":"){
                        pushPop();
                        if(roller.nome == "integer"){
                           listaScroller->tipoIdentificadores = "integer";
                           holdType = "integer";            
                        }else if(roller.nome == "char"){ 
                           listaScroller->tipoIdentificadores = "char";
                           holdType = "char";
                        }else if(roller.nome == "boolean"){
                           listaScroller->tipoIdentificadores = "boolean";
                           holdType = "boolean";
                        }else if(roller.nome == "real"){
                           listaScroller->tipoIdentificadores = "real";
                           holdType = "real";
                        }else if(roller.nome == "word"){
                           listaScroller->tipoIdentificadores = "word";
                           holdType = "word";
                        }else if(roller.nome == "longint"){
                           listaScroller->tipoIdentificadores = "longint";
                           holdType = "longint";
                        }else if(roller.nome == "shortint"){
                           listaScroller->tipoIdentificadores = "shortint";
                           holdType = "shortint";
                        }else if(roller.nome == "byte"){
                           listaScroller->tipoIdentificadores = "byte";
                           holdType = "byte";
                        }else if(roller.nome == "string"){
                           listaScroller->tipoIdentificadores = "string";
                           holdType = "string";
                        }else{
                           erro = 1;
                        }
                     }else{
                        erro = 1;
                     } 
                 
                     if(!erro){
                        //alocar tipos aos identificadores na hash
                        listaIDScroller = listaScroller->listaIdentificadores;
                        while(listaIDScroller != NULL){
                           tabelaHash.setTipo(listaIDScroller->nome, holdType);
                           listaIDScroller = listaIDScroller->next;
                        }
                        pushPop();
                        if(roller.nome == ";"){
                           pushPop();   
                        }else{
                           erro = 1;
                        }
                     }
                  }  
               }
            }else{
               erro = 1;
            }                       
         }                 
      }                        
   }else{
      tempNode = NULL;
   }
   listaScroller = NULL;
   
   return tempNode;
};
   
////////////////////////////////////////////////////////////////////////////////

declaraSubrotinas* sintatico::ASdeclaraSubrotinas(){
                   
   declaraSubrotinas *tempNode;
   declaraProcedimento *procScroller;
   declaraFuncao *funcScroller;
   
   tempNode->declaraProcedimento = procScroller;
   tempNode->declaraFuncao = funcScroller;
   
   nivelLexico++;
   while((roller.nome == "procedure" || roller.nome == "function") && erro == 0){
      
      // Verificação de procedimento
      if(roller.nome == "procedure"){
         pushPop();
         if(roller.tipo == 1){
            pushPop();
            
            // [check] Checar as informações necessárias para preencher a hash
            //de procedimento.
            tabelaHash.setHash(roller.nome, "procedimento");
            tabelaHash.setNivel(roller.nome, nivelLexico);
            procScroller->identificador = roller.nome;
            procScroller->parametrosFormais = ASparametrosFormais();
            if(!erro){
               if(roller.nome == ";"){
                  pushPop();
                  procScroller->bloco = ASbloco();
                  if(!erro){
                     procScroller = procScroller->next;
                  }else{
                     break;
                  }
               }else{
                  erro = 1;
                  break;
               }
            }else{
               break;
            }
         }else{
            erro = 1;
            break;
         }
      
      // Verificação de função
      }else if(roller.nome == "function"){
         pushPop();
         if(roller.tipo == 1){
            pushPop();
            
            // [check] Checar as informações necessárias para preencher a hash
            //de função.
            tabelaHash.setHash(roller.nome, "funcao");
            tabelaHash.setNivel(roller.nome, nivelLexico);
            funcScroller->identificadorFuncao = roller.nome;
            funcScroller->parametrosFormais = ASparametrosFormais();
            if(!erro){
               if(roller.nome == ":"){
                  pushPop();
                  if(roller.tipo == 1){
                     // [check] Checar as informações desse identificador bizarro
                     tabelaHash.setHash(roller.nome, "???");
                     tabelaHash.setNivel(roller.nome, nivelLexico);
                     funcScroller->identificador = roller.nome;
                     funcScroller->bloco = ASbloco();
                     if(!erro){
                        funcScroller = funcScroller->next;
                     }else{
                        break;
                     }                                 
                  }else{
                     erro = 1;
                     break;
                  }
               }else{
                  erro = 1;
                  break;
               }
            }else{
               break;
            }
         }else{
            erro = 1;
            break;
         }
      }      
   }
   nivelLexico--;
   procScroller = NULL;
   funcScroller = NULL;   
   
   return tempNode;
};

////////////////////////////////////////////////////////////////////////////////

parametrosFormais* sintatico::ASparametrosFormais(){
                   
   parametrosFormais *tempNode, *listaScroller;
   listaIdentificadores *listaIDScroller;
   int deslocamentoAux=0;
   string holdTipo;
   
   tempNode = listaScroller;
   if(roller.nome == "("){
      pushPop();
      do{
         if(roller.nome == "var"){
            pushPop();
            listaScroller->listaIdentificadores = ASlistaIdentificadores();
            if(!erro){
                      
               // Inserindo valores de deslocamento nos identificadores coletados 
               //anteriormente.                      
               listaIDScroller = listaScroller->listaIdentificadores;
               deslocamentoAux = (desloca*-1)-3;
               for(; deslocamentoAux <= -3; deslocamentoAux++){
                  tabelaHash.setDeslocamento(listaIDScroller->nome, deslocamentoAux);
                  listaIDScroller = listaIDScroller->next;
               }
               if(roller.nome == ":"){
                  pushPop();
                  
                  // [check] Checar que diabo é esse identificador 
                  //meu palpite na prática: id de variável
                  holdTipo = comparaTipo(roller.nome);
                  if(holdTipo != "erro"){                     
                     /*tabelaHash.setHash(roller.nome, "identificador");
                     tabelaHash.setNivel(roller.nome, nivel); 
                     */
                     
                     listaScroller->identificador12 = roller.nome;
                     pushPop();                
                     listaScroller = listaScroller->next;  
                  }else{
                     erro = 1;
                     break;
                  }               
               }else{
                  erro = 1;
                  break;
               }
            }else{
               break;
            }         
         }else{
            erro = 1;
         }
      }while(roller.nome == ";");
      if(roller.nome == ")"){
         pushPop();      
      }else{
         erro = 1;
      }      
   }else{
      erro = 1;
   }       
   listaScroller = NULL;                
                   
   return tempNode;   
};
   
////////////////////////////////////////////////////////////////////////////////


   
