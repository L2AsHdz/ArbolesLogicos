#include <stdio.h>
#include <stdlib.h>

struct nodo {
    char dato;
    struct nodo *padre;
    struct nodo *izquierda;
    struct nodo *derecha;
};

struct nodo *raiz = NULL;

void insertar(char c){
    struct nodo *nuevo;
    nuevo = malloc(sizeof(struct nodo));
    nuevo->dato = c;
    nuevo->padre = NULL;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;
    
    if (raiz == NULL) {
        raiz = nuevo;
    }else {
        struct nodo *anterior, *actual;
        anterior = NULL;
        actual = raiz;
        while(actual != NULL){
            anterior = actual;
            if (c < actual->dato) {
                actual = actual->izquierda;
            }else {
                actual = actual->derecha;
            }
        }
        
        if (c < anterior->dato) {
            nuevo->padre = anterior;
            anterior->izquierda = nuevo;
        }else {
            nuevo->padre = anterior;
            anterior->derecha = nuevo;
        }
    }
}

void eliminar(char c){
    struct nodo *actual = raiz;
    while (actual != NULL) {
        if (c == actual->dato) {
            eliminarNodo(actual);
            break;
        }else {
            if (c < actual->dato) {
                actual = actual->izquierda;
            }else {
                actual = actual->derecha;
            }
        }
    }
}

struct nodo *encontrarMinimo(struct nodo *actual){
    if (actual == NULL) {
        return NULL;
    }else if (actual->izquierda) {
        return encontrarMinimo(actual->izquierda);
    }else {
        return actual;
    }
}

struct nodo *encontrarMinimo2(struct nodo *actual){
    if (actual == NULL) {
        return NULL;
    }else if (actual->derecha) {
        return encontrarMinimo(actual->derecha);
    }else {
        return actual;
    }
}

void reemplazar(struct nodo *actual, struct nodo *newHijo){
    if (actual->padre){
        if(actual->dato == actual->padre->izquierda->dato){
            actual->padre->izquierda = newHijo;
        }else if(actual->dato == actual->padre->derecha->dato){
            actual->padre->derecha = newHijo;
        }
    }
    if (newHijo){
        newHijo->padre = actual->padre;
    }
}

void eliminarNodo(struct nodo *actual){
    struct nodo *menor;
    if (actual->derecha && actual->izquierda) {
        if(actual->derecha){
        menor = encontrarMinimo(actual->derecha);
        }else {
            menor = encontrarMinimo2(actual->izquierda);
        }
        actual->dato = menor->dato;
        eliminarNodo(menor);
    }else if(actual->izquierda){
        reemplazar(actual, actual->izquierda);
        actual = NULL;
    }else if(actual->derecha){
        reemplazar(actual, actual->derecha);
        actual = NULL;
    }else {
        reemplazar(actual, NULL);
        actual = NULL;
    }
}

void nivel(char c){
    struct nodo *reco = raiz;
    int nivel = 1;
    while (reco != NULL){
        if (c == reco->dato){
            escribirArchivoNivel(nivel);
            printf("\nEl nivel de %c es %i", reco->dato, nivel);
            break;
        }else {
            if (c>reco->dato){
                nivel++;
                reco = reco->derecha;
            }else {
                nivel++;
                reco = reco->izquierda;
            }
        }
    }
}

void peso(char c){
    struct nodo *actual = raiz;
    while (actual != NULL) {
        if (c == actual->dato) {
            int pesoIzq = recorrerIzquierda(actual->izquierda, 0);
            int pesoDer = recorrerDerecha(actual->derecha, 0);
            printf("\nse encontro el nodo %c", actual->dato);
            printf(" %i,%i", pesoIzq, pesoDer);
            escribirArchivoPeso(actual->dato,pesoIzq,pesoDer);
            break;
        }else {
            if (c > actual->dato) {
                actual = actual->derecha;
            }else {
                actual = actual->izquierda;
            }
        }
    }
}

int recorrerIzquierda(struct nodo *actual, int pesoI){
    if (actual != NULL) {
        pesoI++;
        pesoI = recorrerIzquierda(actual->izquierda, pesoI);
        pesoI = recorrerIzquierda(actual->derecha, pesoI);
    }
    return pesoI;
}

int recorrerDerecha(struct nodo *actual, int pesoD){
    if (actual != NULL) {
        pesoD++;
        pesoD = recorrerDerecha(actual->izquierda, pesoD);
        pesoD = recorrerDerecha(actual->derecha, pesoD);
    }
    return pesoD;
}

int isHoja(struct nodo *actual){
    int boolean = 0;
    if (recorrerIzquierda(actual,0) == 0 && recorrerDerecha(actual,0) == 0) {
        boolean = 1;
    }
    return boolean;
}

int isNodo1Hijo(struct nodo *actual){
    int boolean = 0;
    if (recorrerIzquierda(actual,0) >= 1 && recorrerDerecha(actual,0) == 0) {
        boolean = 1;
    }else if (recorrerIzquierda(actual,0) == 0 && recorrerDerecha(actual,0) >= 1) {
        boolean = 2;
    }
    return boolean;
}

void preOrden(struct nodo *reco){
    if (reco != NULL) {
        escribirArchivo(reco->dato);
        printf("%c", reco->dato);
        preOrden(reco->izquierda);
        preOrden(reco->derecha);
    } 
}

void inOrden(struct nodo *reco){
    if (reco != NULL) {
        inOrden(reco->izquierda);
        escribirArchivo(reco->dato);
        printf("%c", reco->dato);
        inOrden(reco->derecha);
    }
}

void postOrden(struct nodo *reco){
    if (reco != NULL) {
        postOrden(reco->izquierda);
        postOrden(reco->derecha);
        escribirArchivo(reco->dato);
        printf("%c", reco->dato);
    }
}

void preOrdenE(struct nodo *reco){
    if (reco != NULL) {
        escribirArchivoE(reco->dato);
        printf("%c", reco->dato);
        preOrdenE(reco->izquierda);
        preOrdenE(reco->derecha);
    } 
}

void inOrdenE(struct nodo *reco){
    if (reco != NULL) {
        inOrdenE(reco->izquierda);
        escribirArchivoE(reco->dato);
        printf("%c", reco->dato);
        inOrdenE(reco->derecha);
    }
}

void postOrdenE(struct nodo *reco){
    if (reco != NULL) {
        postOrdenE(reco->izquierda);
        postOrdenE(reco->derecha);
        escribirArchivoE(reco->dato);
        printf("%c", reco->dato);
    }
}

void imprimirPadres(struct nodo *actual){
    if (actual != NULL) {
        if (actual->padre != NULL) {
            printf("\nEl padre de %c es: %c", actual->dato, actual->padre->dato);
        }
        imprimirPadres(actual->izquierda);
        imprimirPadres(actual->derecha);
    }
}