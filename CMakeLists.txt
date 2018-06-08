cmake_minimum_required(VERSION 3.8)
project(progra-tpi)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c validations.h validations.c fecha.c fecha.h tp_utils.c tp_utils.h indice.c indice.h lista.c lista.h cola.c cola.h nodo.h)
add_executable(progra-tpi ${SOURCE_FILES} validations.h validations.c fecha.c fecha.h indice.c indice.h tp_utils.c tp_utils.h lista.c lista.h cola.c cola.h)