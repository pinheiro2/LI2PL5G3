cmake_minimum_required(VERSION 3.15)
project(projeto C)

set(CMAKE_C_STANDARD 99)

add_executable(projeto main.c Interface.c Dados.h Interface.h Logica.h Logica.c Dados.c listas_ligadas.c listas_ligadas.h)