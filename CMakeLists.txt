## Indique qu'elle version de cmake minimale est utilisée.
cmake_minimum_required (VERSION 3.16.3)

## Specifie le nom du projet et le langage de programmation du projet
project(Lab3 CXX)

## Force le standard 
set(CMAKE_CXX_STANDARD 17)

# Autorise les tests automatisés
enable_testing()

## Indique les options de compilations pour le projet
## -pg : donne la possibilité de faire du profiling
## -Wall : affiche les warnings
set(CMAKE_CXX_FLAGS "-Wall")

## Définir la localisation des entêtes.
## include_directories sera propager à l'ensemble du projet
include_directories(${CMAKE_SOURCE_DIR}/include)

## Mise en place d'une librairie de test
include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(Catch2)


## Parcours les sous répertoires contenant les définitions (.cxx)
## On commence par créer une bibliothèque
add_subdirectory(src)

## On créée les tests pour la bibliothèque.
## Ces tests sont unitaires ou fonctionnels
add_subdirectory(test)

## On implémente une démo, un programme de vérification.
add_subdirectory(demo)
