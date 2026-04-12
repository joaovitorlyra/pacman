
#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

MAPA m;

void liberamapa(){
    for (int i = 0; i < m.linhas; i++){
        free (m.matriz [i]);
    }
    free (m.matriz);
}

void alocamapa(){
     m.matriz = malloc(sizeof (char*) * m.linhas);
    for (int i = 0; i <m.linhas; i++){
        m.matriz[i] = malloc(sizeof(char) * (m.colunas + 1));
    }
}

void lermapa(){
    FILE* f;
    f = fopen("m.matriza.txt", "r");
    if(f == 0){
        printf("erro na leitur do mapa\n");
        exit(1);
    }
    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));
       
alocamapa();

    for (int i = 0; i < 5;i++){
        fscanf(f, "%s", m.matriz[i]);
    }
    fclose (f);
}

void imprememapa(){
    for (int i = 0; i < 5; i++){
        printf("%s\n", m.matriz[i]);
    }
}
int acabou(){
    return 0;
}

void move (char diercao){
    int x;
    int y;

for (int i = 0; i < m.linhas; i++){
    for (int j = 0; j < m.colunas; j++){
        if (m.matriz [i][j] == '@'){
            x = i;
            y = j;
            break;
        }
    }
}

switch (diercao){
    case 'a':
    m.matriz[x] [y-1] = '@';
        break;

    case 'w':
    m.matriz[x-1] [y] = '@';
        break;

    case 's':
    m.matriz [x+1] [y] = '@';
        break;

    case 'd':
    m.matriz [x] [y+1] = '@';
    break;
  }

}

int main(){

lermapa();     

do{
    imprememapa();

    char comando;
    scanf( "%c", &comando);
    move(comando);

} while (acabou());

    
    
liberamapa();

}
