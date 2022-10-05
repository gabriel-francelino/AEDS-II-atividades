/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fila.h
 * Author: paulo
 *
 * Created on February 4, 2021, 4:28 PM
 */

#ifndef FILA_H
#define FILA_H

#include "lista.h"

typedef tLista tFila;

inline tFila* inicia_fila(){
    return inicia_lista();
};

inline tFila* encerra_fila(tFila* p){
    return encerra_lista(p);
};

inline void push(tFila* p, int valor){
    return insere_inicio(p, valor);
};

inline no* pop(tFila* p){
    return remove_fim(p);
};

#endif /* FILA_H */

