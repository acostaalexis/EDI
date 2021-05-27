#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Struct 
typedef struct {
    char* alias;
    char* exp;
}  AliExp;

// Prototipo
void terminal(void);
char* separa(char* cadena, char c);
AliExp* alias_expresion(char* cadena);

int main(){
    // Limpiamos la terminal 
    system("clear");
    
    printf("Bienvenido A La Terminal\n");
    terminal();

    return 0;
}


/**
 * separa(): Char* -> Char -> Char*
 * la funcion separar el puntero char (Char*) desde su inicio
 * hasta la primera iteracion del caractar (Char) y 
 * y lo retorna
 * Ejemplos:
 * separa("hola ,", ',') == "hola"
 * separa("hola mundo", ' ') == "hola"
 * separa("imprimir exp" , ' ') == "imprimir"
 * separa("alias = 12", '=') == "alias"
*/

char* separa(char* cadena, char c){
    char* alias = malloc(sizeof(char));
    assert(alias != NULL);

    int longitud = strlen(cadena);
    int i = 0;
    while(cadena[i] != c && i < longitud){
        if(cadena[i] != ' ') {
            alias[i] = cadena[i];
        }
        i++;
        /* Esto es para guarar en resp->alias el Alias*/
    }
    return alias;
}



/**
 * terminal(): Void -> void
 * la funcion inicia una terminal interactiva con el usuario
*/

void terminal(){
    char* nuevo = malloc(sizeof(char));
    assert(nuevo != NULL);
    char* principio = "";

    while(strcmp(nuevo,"salir")){
        printf(">> ");
        gets(nuevo);
        char* principio = separa(nuevo,' '); // nos devuelve el primer string

        if( !strcmp(principio,"imprimir") ){
            printf("\nImprimir Expresion\n");
        } else if( !strcmp(principio,"evaluar") ){
            printf("\nEvaluar Expresion\n");
        } else {
            // evaluaremos si es o no una expresion invalida y si 
            // no lo es agregaremos las funciones para trabajarla
        }
    }
}


/**
 * alias_expresion(): Char* -> AliExp*
 *  dada una Cadena (Char*) la funcion
 * separa su alias de su expresion
 * alias_expresion("valor = cargar 12") == {"valor", "12"};
 * alias_expresion("exp1 = cargar 3 2 -") ==  {"exp1", "3 2 -"};
 * alias_expresion("1exp = cargar 3 + 4") ==  NULL
*/

AliExp* alias_expresion(char* cadena){
    AliExp* nuevo = malloc(sizeof(AliExp));
    nuevo->alias = separa(cadena, '=');
    
}