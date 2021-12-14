cmake_minimum_required(VERSION 3.20)
project(TPDEVAPP C)

set(CMAKE_C_STANDARD 11)

add_executable(TPDEVAPP main.c arbre_binaire.c arbre_binaire.h films.c films.h menu_utilisateur.c menu_utilisateur.h)
