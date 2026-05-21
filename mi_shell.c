#include <stdio.h>      // printf, fgets, perror
#include <stdlib.h>     // exit
#include <string.h>     // strtok, strcmp
#include <unistd.h>     // fork, execvp
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // waitpid

#define MAX_LINE 1024
#define MAX_ARGS 100

int main() {
    char line[MAX_LINE];      // Almacena la línea ingresada por el usuario
    char *args[MAX_ARGS];     // Almacena comando y argumentos
    pid_t pid;
    int status;

    while (1) {
        // ITEM 1: Mostrar el prompt sin usar llamadas a sistema 
        printf("mi_shell> ");
        fflush(stdout);
        // ITEM 2: Leer el comando desde el teclado, sin usar llamadas a sistema, usando fgets de la librería C

        if (fgets(line, sizeof(line), stdin) == NULL) {
            // Si se presiona Ctrl+D (EOF), termina la shell
            printf("\n");
            break;
        }

        /* =========================================================
            ITEM 5:
           Enter vacío: 
           Si el usuario solo presiona Enter, se vuelve a mostrar el prompt.
           No requiere llamadas a sistema.
           ========================================================= */
        if (strcmp(line, "\n") == 0) {
            continue;
        }

        // Eliminar el salto de línea final de la entrada
        line[strcspn(line, "\n")] = '\0';

        /* =========================================================
             ITEM 2:
            Parsear la entrada:
            Se separa el comando y sus argumentos usando strtok().
           ========================================================= */
        int argc = 0;
        char *token = strtok(line, " \t");

        while (token != NULL && argc < MAX_ARGS - 1) {
            args[argc] = token;
            argc++;
            token = strtok(NULL, " \t");
        }

        args[argc] = NULL;

        // Si por alguna razón no hay argumentos, continuar con el siguiente ciclo
        if (args[0] == NULL) {
            continue;
        }

        /* =========================================================
            ITEM 3
           Comando exit: Si el comando es "exit", la shell termina.
           No requiere llamadas a sistema.
           ========================================================= */
        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        // ITEM 6: Crear proceso concurrente con fork()
        pid = fork();

        if (pid < 0) {
            /* Error al crear el proceso */
            perror("fork");
            continue;
        }

        if (pid == 0) {
            /* =====================================================
               PROCESO HIJO
               Ejecuta el comando usando execvp()
               ===================================================== */
            execvp(args[0], args);

            /* =====================================================
               ITEM 4: Si execvp retorna, el comando no existe
               Se muestra el error correspondiente y el hijo termina.
               ===================================================== */
            perror(args[0]);
            _exit(1);
        } else {
            /* =====================================================
               PROCESO PADRE
               Espera a que el hijo termine (foreground)
               ===================================================== */
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}


