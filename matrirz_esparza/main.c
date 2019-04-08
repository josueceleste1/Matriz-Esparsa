#include <stdio.h>
#include <stdlib.h>

/*
JOSUE C. DO NASCIMENTO
*/
typedef struct{
int coluna;
int valor;
}EntradaMatriz;

typedef struct{
EntradaMatriz **m;
int num_linha, num_colunas;
}MatrizEsparsa;

void inicializa_matriz();
void mostra_matriz(MatrizEsparsa me);
void desaloca_matriz();
void modifica_valor(MatrizEsparsa *p, int lin, int col, int valor);
int verifica(MatrizEsparsa *p, int lin, int col);
void ordena();
int busca_valor(MatrizEsparsa *p, int *col, int lin, int val);
int busca_coluna();
void soma(a,b);
void subt(a,b);
void insere();
void salva();

int main(){

MatrizEsparsa a;
MatrizEsparsa b;
/*
int lin, col, v;
printf("matriz A\n");
printf("digite a quantidade de linhas e colunas\n");

scanf("%d%d", &lin, &col);
inicializa_matriz(&a,lin,col);

printf("matriz B\n");
printf("digite a quantidade de linhas e colunas\n");
int lin_b, col_b, v_b;
scanf("%d%d", &lin_b, &col_b);

inicializa_matriz(&b,lin_b,col_b);
*/
system("cls");
int resp;

while(resp!=0){

printf("Menu:\n");
printf("1-Carregar uma matriz do arquivo;\n2-Visualizar uma matriz;\n");
printf("3-Modifica uma matriz, dadas as coordenadas (linha e coluna);\n4-Salvar uma matriz;\n");
printf("5-Soma entre matriz;\n6-Subtracao entre matrizes;\n7-Multiplicacao entre matrizes;\n0-Sair.\n");
scanf("%i", &resp);
if(resp == 1){
    system("cls");
    int i,j,r1;
    printf("Voce pode carregar duas matrizes do arquivo.\n");
    printf("1-Carrega a matriz A;\n2-Carrega a matriz B.\n");
    scanf("%i",&r1);

    if(r1==1){
    printf("matriz A\n");
    //MatrizEsparsa a;

    FILE *mat;
    mat = fopen("Matriz A.txt","r");
    if(mat==NULL){
        printf("Deu merda no arquivo!\n");
        system("pause");
    }
    int lin_a, col_a,aux;
    fscanf(mat,"%i%i",&lin_a,&col_a);
    //printf("lin = %i e col = %i\n", lin_x, col_x);
    inicializa_matriz(&a,lin_a,col_a);
    for(i=0;i<lin_a;i++){
        for(j=0;j<col_a;j++){
            fscanf(mat,"%i",&aux);
            modifica_valor(&a,i,j,aux);
        }
    }
        mostra_matriz(a);
    }
    if(r1==2){
        printf("matriz B:\n");
        //MatrizEsparsa b;

    FILE *mat;
    mat = fopen("Matriz B.txt","r");
    if(mat==NULL){
        printf("Deu merda no arquivo!\n");
        system("pause");
    }
    int lin_b, col_b,aux;
    fscanf(mat,"%i%i",&lin_b,&col_b);
    //printf("lin = %i e col = %i\n", lin_x, col_x);
    inicializa_matriz(&b,lin_b,col_b);
    for(i=0;i<lin_b;i++){
        for(j=0;j<col_b;j++){
            fscanf(mat,"%i",&aux);
            if(aux!=0){
            modifica_valor(&b,i,j,aux);
            }
        }
    }
        mostra_matriz(b);
    }

}
if(resp == 2){
    system("cls");
    printf("escolha:\n");
    printf("1-Mostra matriz A.\n2-Mostra matriz B.\n");
    int r2;
    scanf("%i", &r2);
    if(r2==1){
        system("cls");
        mostra_matriz(a);
    }
    if(r2==2){
        system("cls");
        mostra_matriz(b);
    }

}
if(resp == 3){
        int lin,col,v;
    system("cls");
     int r3;
     printf("Escolha uma matriz\n1-Modifica a matriz A\n2-Modifica a matriz B\n");
     scanf("%i", &r3);
     if(r3==1){
            system("cls");
     insere(&lin, &col, &v);
     modifica_valor(&a, lin, col, v);
     }
     if(r3==2){
         system("cls");
     insere(&lin, &col, &v);
     modifica_valor(&b, lin, col, v);
     }
}
if(resp == 4){
    system("cls");
    int r4;
    printf("Escolha a matriz:\n1-Matriz A;\n2-Matriz B.\n");
    scanf("%i",&r4);
    if(r4==1){
        salva(a,r4);
    }
    if(r4==2){
        salva(b,r4);
    }

}
if(resp == 5){
    system("cls");
    soma(a,b);
}
if(resp == 6){
    system("cls");
    subt(a,b);
}
if(resp == 7){
    system("cls");
    mult(a,b);

}

}
desaloca_matriz(a);
desaloca_matriz(b);
return 0;
}
void inicializa_matriz(MatrizEsparsa *p, int l, int c){
    p->num_linha = l;
    p->num_colunas = c;
    p->m=malloc(sizeof(MatrizEsparsa)*l);
    int i;
        for(i=0;i<l;i++){
            p->m[i]=NULL;
        }
}

void mostra_matriz(MatrizEsparsa x){
int i, j;

/*if(x==NULL){
    printf("Matriz nao carregada.\n");
}*/
for(i=0;i<x.num_linha;i++){
        for(j=0;j<x.num_colunas;j++){
            int valor=le_valor(x,i,j);
            printf("%d\t  ", valor);
            }
            printf("\n");
    }
}

void salva(MatrizEsparsa a, int op){
int i,j;
if(op==1){
FILE *matriz;
matriz = fopen("Matriz carregada.txt","w");
// fprintf(matriz, "teste");
fprintf(matriz, "Matriz A:\n");
for(i=0;i<a.num_linha;i++){
for(j=0;j<a.num_colunas;j++){
int valor=le_valor(a,i,j);
fprintf(matriz, "%d\t ", valor);
}
fprintf(matriz, "\n");
}

   fclose(matriz);
}
if(op==2){
     FILE *matriz;
matriz = fopen("Matriz carregada.txt","w");
  // fprintf(matriz, "teste");
  fprintf(matriz, "Matriz B:\n");
   for(i=0;i<a.num_linha;i++){
        for(j=0;j<a.num_colunas;j++){
            int valor=le_valor(a,i,j);
                fprintf(matriz, "%d\t  ", valor);
            }
        fprintf(matriz, "\n");
    }

   fclose(matriz);
}
if(op==3){
FILE *matriz;
matriz = fopen("Matriz carregada.txt","w");
  // fprintf(matriz, "teste");
  fprintf(matriz, "Matriz Resultante:\n");
   for(i=0;i<a.num_linha;i++){
        for(j=0;j<a.num_colunas;j++){
            int valor=le_valor(a,i,j);
                fprintf(matriz, "%d\t  ", valor);
            }
        fprintf(matriz, "\n");
    }

   fclose(matriz);
}
}

void modifica_valor(MatrizEsparsa *p, int lin, int col, int valor){
int cont=2;
// verifricar se lin é maior que num_linhas... o mesmo prar colunas...

if(p->num_linha<=lin){

    p->m=realloc(p->m, sizeof(MatrizEsparsa*)*(lin+1));
    int i;
    for(i=p->num_linha;i<lin+1;i++){
    p->m[i]=NULL;
    }
    p->num_linha = (lin+1);
}
if(p->num_colunas<=col){
p->num_colunas = (col+1);
}
/*
//essa parte faz fazer
if(valor == 0){
int i_coluna;
busca_coluna(p, &i_coluna,lin,col);
while(p->m[lin][i_coluna].coluna!=-1){
p->m[lin][i_coluna].coluna = p->m[lin][i_coluna+1].coluna;
p->m[lin][i_coluna].valor = p->m[lin][i_coluna+1].valor;
}

}*/

if(p->m[lin] == NULL){
p->m[lin] = malloc(sizeof(EntradaMatriz)*2);
p->m[lin][0].coluna = col;
p->m[lin][0].valor = valor;
p->m[lin][1].coluna = -1;
}else{
int i_coluna;
if(busca_coluna(p, &i_coluna, lin, col)==1){
printf("Valor alterado!\n");
p->m[lin][i_coluna].valor = valor;

   }else{
       int i;
       for(i=0;p->m[lin][i].coluna!=-1;i++){
            cont++;
       }
       //printf("i = %i\n", i);
        p->m[lin] == realloc(p->m[lin], sizeof(EntradaMatriz)*cont);
        p->m[lin][cont-2].coluna = col;
        p->m[lin][cont-2].valor = valor;
        p->m[lin][cont-1].coluna = -1;
        //printf("cont = %i\n", cont-2);
   }
        ordena(p, lin);
}

}
void ordena(MatrizEsparsa *p, int lin){
int i, j, aux, aux2, i_menor;
for(i=0;p->m[lin][i].coluna!=-1;i++){
i_menor=i;
for(j=i+1;p->m[lin][j].coluna!=-1;j++){
if(p->m[lin][j].coluna < p->m[lin][i_menor].coluna){
i_menor=j;
}
}

        aux = p->m[lin][i].coluna;
        p->m[lin][i].coluna = p->m[lin][i_menor].coluna;
        p->m[lin][i_menor].coluna = aux;

        aux2 = p->m[lin][i].valor;
        p->m[lin][i].valor = p->m[lin][i_menor].valor;
        p->m[lin][i_menor].valor = aux2;
    }
}
int busca_coluna(MatrizEsparsa *p, int *col, int lin, int colu){
int j;
for(j=0;p->m[lin][j].coluna!=-1;j++){
if(p->m[lin][j].coluna == colu){
// printf("coluna onde se encontra o valor: %i\n", p->m[lin][j].coluna);
*col = j;
return 1;
}
}

}

void insere(int *lin, int *col, int *val){
int l, c, v;
printf("digite as coordenadas para modificar\n");
scanf("%d%d", &l, &c);
printf("digite o valor para modificar\n");
scanf("%d", &v);
*lin=l;
*col=c;
*val=v;

}

int le_valor(MatrizEsparsa me, int i, int j){
if(i>=me.num_linha || j>=me.num_colunas){
return 0;
}
if(me.m[i] == NULL){
return 0;
}
int idx = busca(me.m[i], j);
if(idx == -1){
return 0;
}
else{
return me.m[i][idx].valor;
}

}

int busca(EntradaMatriz *v, int col){
int i;
for(i=0;v[i].coluna!=-1;i++){
if(v[i].coluna==col){
return i;
}
}
return -1;
}
void soma(MatrizEsparsa a, MatrizEsparsa b){
printf("soma:\n");
MatrizEsparsa c;
int i, j;
if(a.num_colunas && a.num_linha != b.num_colunas && b.num_linha){
printf("Erro a matriz tem dimensoes diferentes!\n");
return 0;
}
int lin = a.num_linha;
int col = a.num_colunas;

inicializa_matriz(&c,lin,col);

for(i=0;i<lin;i++){
    for(j=0;j<col;j++){
        int x = le_valor(a,i,j)+le_valor(b,i,j);
        if(x!=0){
        modifica_valor(&c,i,j,x);
        }
    }
}
mostra_matriz(c);
int r;
printf("Deseja salvar a matriz?\n1-Sim.\n2-Nao\n");
scanf("%i",&r);
if(r==1){
    salva(c,1);
}
}

void subt(MatrizEsparsa a, MatrizEsparsa b){
printf("subtracao:\n");
MatrizEsparsa c;
int i, j;
if(a.num_colunas && a.num_linha != b.num_colunas && b.num_linha){
printf("Erro, as matrizes tem dimensoes diferentes!\n");
return 0;
}
int lin = a.num_linha;
int col = a.num_colunas;

inicializa_matriz(&c,lin,col);

for(i=0;i<lin;i++){
    for(j=0;j<col;j++){
        int x = le_valor(a,i,j)-le_valor(b,i,j);
        if(x!=0){
        modifica_valor(&c,i,j,x);
        }
    }
}
mostra_matriz(c);
int r;
printf("Deseja salvar a matriz?\n1-Sim.\n2-Nao\n");
scanf("%i",&r);
if(r==1){
    salva(c,2);
}
}

void mult(MatrizEsparsa a, MatrizEsparsa b){
printf("Multiplicacao:\n");
MatrizEsparsa c;
int i, j, k;
if(a.num_linha != b.num_colunas){
printf("Erro, quantidade de linha de A e diferentwe da quantidade de colunas de B!\n");
return 0;
}
int lin = a.num_linha;
int col = b.num_colunas;
inicializa_matriz(&c,lin,col);

for(i=0;i<lin;i++){
    for(j=0;j<col;j++){
                int x = (le_valor(a,i,j)+le_valor(b,i,j)*le_valor(a,i,j)+le_valor(a,i,j));
                if(x!=0){
                modifica_valor(&c,i,j,x);
                }
    }
}
mostra_matriz(c);
int r;
printf("Deseja salvar a matriz?\n1-Sim.\n2-Nao\n");
scanf("%i",&r);
if(r==1){
    salva(c,3);
}
}
desaloca_matriz(MatrizEsparsa a){
int i, j;

for(i=0;i<a.num_linha;i++){
    for(j=0;j<a.num_colunas;j++){
        free(a.m[i][j].coluna);
    }
}
free(&a);
}
