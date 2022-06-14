cmake_minimum_required(VERSION 3.21)
project(TP2022 C)

set(CMAKE_C_STANDARD 99)

add_executable(TP2022 main.c
        matdin.c matdin.h
        utils.c utils.h
        jogo.c jogo.h
        jogoC.c jogoC.h
        resultados.c resultados.h
        listaligada.c listaligada.h
        )
