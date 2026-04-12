struct mapa{
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

void liberamapa (MAPA* m);
void alocamapa(MAPA* m);
void lermapa(MAPA* m);
void imprememapa(MAPA* m);
