void liberamapa(MAPA* m){
    for (int i = 0; i < m->linhas; i++){
        free (m->matriz [i]);
    }
    free (m->matriz);
}

void alocamapa(MAPA* m){
     m->matriz = malloc(sizeof (char*) * m->linhas);
    for (int i = 0; i <m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

void lermapa(MAPA* m){
    FILE* f;
    f = fopen("m->matriza.txt", "r");
    if(f == 0){
        printf("erro na leitur do mapa\n");
        exit(1);
    }
    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));
       
alocamapa(MAPA* m);

    for (int i = 0; i < 5;i++){
        fscanf(f, "%s", m->matriz[i]);
    }
    fclose (f);
}

void imprememapa(MAPA* m){
    for (int i = 0; i < 5; i++){
        printf("%s\n", m->matriz[i]);
    }
}