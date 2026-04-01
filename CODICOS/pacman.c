
#include <stdio.h>
#include <stdlib.h>

char** mapa;
int linhas;
int colunas;

void liberamapa(){
    for (int i = 0; i < linhas; i++){
        free (mapa [i]);
    }
    free (mapa);
}

void alocamapa(){
     mapa = malloc(sizeof (char*) * linhas);
    for (int i = 0; i < linhas; i++){
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }
}

void lermapa(){
    FILE* f;
    f = fopen("mapa.txt", "r");
    if(f == 0){
        printf("erro na leitur do mapa\n");
        exit(1);
    }
    fscanf(f, "%d %d", &linhas, &colunas);
       
alocamapa();

    for (int i = 0; i < 5;i++){
        fscanf(f, "%s", mapa[i]);
    }
    fclose (f);
}

void imprememapa(){
    for (int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }
}
int acabou(){
    return 0;
}

void move (char diercao){
    int x;
    int y;

for (int i = 0; i < linhas; i++){
    for (int j = 0; j < colunas; j++){
        if (mapa [i][j] == '@'){
            x = i;
            y = j;
            break;
        }
    }
}

switch (diercao){
    case 'a':
    mapa[x] [y-1] = '@';
        break;

    case 'w':
    mapa[x-1] [y] = '@';
        break;

    case 's':
    mapa [x+1] [y] = '@';
        break;

    case 'd':
    mapa [x] [y+1] = '@';
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
