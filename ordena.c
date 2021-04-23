//novo ordena



//novoOrdena

//linha de comando: ./nomedoPrograma -metodo listadeNumeros
//metodos disponiveis:
//-q ou -Q (metodo Quick Sort)
//-m ou -M (metodo Merge Sort)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Erro caso tenha problema na alocacao de memoria

void Erro(int *lista)
{
    if (lista == NULL)
    {
        printf("Erro de alocaçao de memória");
        exit(-1);
    }
}


//          Printa lista

void PrintaLista(int *lista, int tamanho)
{
    
    for(int i=0; i<tamanho;i++)
    {
        printf("%d\n", lista[i]);
    }

}


//          FUNÇAO DE TROCA

void troca(int *a, int *b) //problemas com ponteiros //NAO TO CONSEGUINDO TROCAR OS ITENS DE POSICAO NA LISTA
{
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
    return;
}


//      PARTICAO DO QUICK SORT

int Meio(int *listaTemp, int menorI, int maiorI) //coloca o pivot no lugar dele //vou assumir o pivo como sendo sempre o maior indice da particao
{
    
    int i = menorI -1;

    for(int j = menorI; j<= maiorI-1; j++)
    {
        if(listaTemp[j]<=listaTemp[maiorI])
        {
            i++; 
            troca(&listaTemp[i], &listaTemp[j]);
        }
    }
    troca(&listaTemp[i+1], &listaTemp[maiorI]);
    return(i+1); 
}



//  QUICK SORT

void QuickSort(int *lista, int menorI, int maiorI) //recebe o vetor, os menores e maiores Index
{   
    if(menorI < maiorI)
    {
        int meio = Meio(lista, menorI, maiorI);
        QuickSort(lista, menorI, meio-1);   //lado esquerdo do pivot
        QuickSort(lista, meio+1, maiorI);   //lado direito do pivot
    }
    return;
}




//  MERGE

void Merge(int *Lista, int inicio, int meio, int fim)
{
    int *listaTemporaria; int aux1, aux2, fimAux1, fimAux2, tamanho;  
    tamanho = fim - inicio +1; // admitindo que o inicio pode ser o indice 0 somamos 1;
    aux1 = inicio; aux2 = meio+1; //aux1: indice de inicio da primeira divisao //aux2: indice de inicio da segunda divisao
    fimAux1 = 0; fimAux2 = 0; //validadores de fim das partes divididas
    listaTemporaria = (int *) malloc(tamanho*sizeof(int)); //Lista temporaria com o tamanho do vetor a ser ordenado
    
    
    Erro(listaTemporaria); //caso tenha problema na alocacao de memoria

    
    for(int i=0; i<tamanho; i++)
    {
        if(!fimAux1 && !fimAux2)
        {
            if(Lista[aux1]< Lista[aux2])
                listaTemporaria[i] = Lista[aux1++];
            else 
                listaTemporaria[i]= Lista[aux2++];
            
            
            if(aux1 > meio)
                fimAux1 = 1;
            if(aux2 > fim)
                fimAux2 = 1;
        }
        else 
        {
            if (!fimAux1)
                listaTemporaria[i] = Lista[aux1++];
            else 
                listaTemporaria[i] = Lista[aux2++];
        }
    }
    for(int j=0 , k = inicio; j<tamanho; j++, k++)
    {
        Lista[k]= listaTemporaria[j];
    }
    free(listaTemporaria);
    return;
}



//  MERGE SORT

void MergeSort(int *Lista, int inicio, int fim)
{
    int meio = (fim+inicio)/2;
    if(inicio < fim){
        MergeSort(Lista, inicio, meio);
        MergeSort(Lista, meio+1, fim);
        Merge(Lista, inicio, meio, fim);
    }
    return;

}


//  Algoritmo N dois

void Ndois(int *lista, int tamanho)
{
    for(int i=0; i<tamanho; i++)
    {
        for(int j= 0;j< tamanho; j++)
        {
            if(lista[i]<lista[j])
            {
                troca(&lista[i], &lista[j]);
            }
        }
    }
}


int main(int argc, char** arg)
{


    char q[]= "-q";//identifica se usaremos o metodo Quick sort
    
    char m[]= "-m";//identifica se usaremos o metodo Merge sort








    
    //ALGORITMO N^2            -----------------    FUNCIONANDO     -------------------------



    if (argc == 1){                               

    

        int numero;
        char entrada[2];


        int tamanho=0; //   CONTADOR DE NUMEROS ALOCADOS
        int *listafinal; //     LISTA FINAL SEM DESPERDICIO DE MEMORIA


        int *lista = (int *) malloc(sizeof(int)*10);  // LISTA INICIAL QUE SERA REALOCADA DINAMICAMENTE 
        Erro(lista); //caso tenha problema na alocacao de memoria
        int tamanholista = 10;
        
        

         //PRIMEIRA ENTRADA
        while(1)
        {
            int k = scanf("%s", entrada);
            if(k == EOF)break;
            else if(tamanho == tamanholista)
            {
                lista = realloc(lista, tamanho*10*sizeof(int));     //     REALOCANDO DINAMICAMENTE A LISTA PARA EVITAR GASTO EXCESSIVO DE MEMORIA
                
                Erro(lista); //caso tenha problema na alocacao de memoria
                tamanholista = tamanho*10;  //  TAMANHO DA LISTA
                

                numero = atoi(entrada);
                lista[tamanho++]= numero;

            }
            else
            {
                numero = atoi(entrada);
                lista[tamanho++]= numero;

            }
        }
        listafinal = (int *) malloc(tamanho*sizeof(int)); //LISTA SEM DESPERDICIO DE MEMORIA //A SE ORDENAR
        Erro(listafinal); //caso tenha problema na alocacao de memoria

        for(int i=0;i<tamanho;i++)
        {
            listafinal[i]=lista[i];
        }
        free(lista);

        Ndois(listafinal, tamanho);          //organizando
        PrintaLista(listafinal, tamanho);
        free(listafinal);
        
        
    }

    else if (strcmp(arg[1], m) && strcmp(arg[1], q)){                               



        int numero;
        char entrada[2];


        int tamanho=0; //   CONTADOR DE NUMEROS ALOCADOS
        int *listafinal; //     LISTA FINAL SEM DESPERDICIO DE MEMORIA


        int *lista = (int *) malloc(sizeof(int)*10);  // LISTA INICIAL QUE SERA REALOCADA DINAMICAMENTE 
        Erro(lista); //caso tenha problema na alocacao de memoria
        int tamanholista = 10;        

         //PRIMEIRA ENTRADA
        while(1)
        {
            int k = scanf("%s", entrada);
            if(k == EOF)break;
            else if(tamanho == tamanholista)
            {
                lista = realloc(lista, tamanho*10*sizeof(int));     //     REALOCANDO DINAMICAMENTE A LISTA PARA EVITAR GASTO EXCESSIVO DE MEMORIA
                
                Erro(lista); //caso tenha problema na alocacao de memoria
                tamanholista = tamanho*10;  //  TAMANHO DA LISTA
                

                numero = atoi(entrada);
                lista[tamanho++]= numero;

            }
            else
            {
                numero = atoi(entrada);
                lista[tamanho++]= numero;

            }
        }
        listafinal = (int *) malloc(tamanho*sizeof(int)); //LISTA SEM DESPERDICIO DE MEMORIA //A SE ORDENAR
        Erro(listafinal); //caso tenha problema na alocacao de memoria

        for(int i=0;i<tamanho;i++)
        {
            listafinal[i]=lista[i];
        }
        free(lista);

        Ndois(listafinal, tamanho);          //organizando
        PrintaLista(listafinal, tamanho);
        free(listafinal);
        
        
    }

















    //MERGE SORT                    ----------------    FUNCIONANDO     -------------------------

    
    else if (!strcmp(arg[1], m)) //chama o Merge se a entrada tiver sido -m ou -M
    {     

    
        

        int numero;
        char entrada[2];


        int tamanho=0; //   CONTADOR DE NUMEROS ALOCADOS
        int *listafinal; //     LISTA FINAL SEM DESPERDICIO DE MEMORIA


        int *lista = (int *) malloc(sizeof(int)*10);  // LISTA INICIAL QUE SERA REALOCADA DINAMICAMENTE 
        Erro(lista); //caso tenha problema na alocacao de memoria
        int tamanholista = 10;
              
         //PRIMEIRA ENTRADA
        while(1)
        {
            int k = scanf("%s", entrada);
            if(k == EOF)break;
            else if(tamanho == tamanholista)
            {
                lista = realloc(lista, tamanho*10*sizeof(int));     //     REALOCANDO DINAMICAMENTE A LISTA PARA EVITAR GASTO EXCESSIVO DE MEMORIA
                
                Erro(lista); //caso tenha problema na alocacao de memoria
                tamanholista = tamanho*10;  //  TAMANHO DA LISTA
                

                numero = atoi(entrada);
                lista[tamanho++]= numero;

            }
            else
            {
                numero = atoi(entrada);
                lista[tamanho++]= numero;

            }
        }
        listafinal = (int *) malloc(tamanho*sizeof(int)); //LISTA SEM DESPERDICIO DE MEMORIA //A SE ORDENAR
        Erro(listafinal); //caso tenha problema na alocacao de memoria

        for(int i=0;i<tamanho;i++)
        {
            listafinal[i]=lista[i];
        }
        free(lista);

        MergeSort(listafinal, 0, tamanho-1);          //organizando
        PrintaLista(listafinal, tamanho);
        free(listafinal);
    
    }






















    //QUICK SORT                    ----------------    FUNCIONANDO     -------------------------




    else if(!strcmp (arg[1], q)) //chama o Quick se a entrada tiver sido -q ou -Q
    { 
        
        

        int numero;
        char entrada[2];


        int tamanho=0; //   CONTADOR DE NUMEROS ALOCADOS
        int *listafinal; //     LISTA FINAL SEM DESPERDICIO DE MEMORIA


        int *lista = (int *) malloc(sizeof(int)*10);  // LISTA INICIAL QUE SERA REALOCADA DINAMICAMENTE 
        Erro(lista); //caso tenha problema na alocacao de memoria
        int tamanholista = 10;

         //PRIMEIRA ENTRADA
        while(1)
        {
            int k = scanf("%s", entrada);
            if(k == EOF)break;
            else if(tamanho == tamanholista)
            {
                lista = realloc(lista, tamanho*10*sizeof(int));     //     REALOCANDO DINAMICAMENTE A LISTA PARA EVITAR GASTO EXCESSIVO DE MEMORIA
                
                Erro(lista); //caso tenha problema na alocacao de memoria
                tamanholista = tamanho*10;  //  TAMANHO DA LISTA
                

                numero = atoi(entrada);
                lista[tamanho++]= numero;

            }
            else
            {
                numero = atoi(entrada);
                lista[tamanho++]= numero;

            }
        }
        listafinal = (int *) malloc(tamanho*sizeof(int)); //LISTA SEM DESPERDICIO DE MEMORIA //A SE ORDENAR
        Erro(listafinal); //caso tenha problema na alocacao de memoria

        for(int i=0;i<tamanho;i++)
        {
            listafinal[i]=lista[i];
        }
        free(lista);

        QuickSort(listafinal, 0, tamanho-1);          //organizando
        PrintaLista(listafinal, tamanho);
        free(listafinal);

    }


    
    return 0;
}