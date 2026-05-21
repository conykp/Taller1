# Taller1
En el presente taller se desarrolló un intérprete de comandos simple para sistemas Linux utilizando el lenguaje de programación C.

# Proyecto: Intérprete de Comandos Simple en Linux (Shell)

# Descripción:
Este proyecto corresponde al Taller 1 de la asignatura Sistemas Operativos.
Consiste en el desarrollo de una shell simple en lenguaje C para sistemas Linux,
capaz de ejecutar comandos del sistema utilizando las llamadas al sistema
fork(), execvp() y waitpid().

Archivos del proyecto:
- mi_shell.c      : Código fuente principal.
- README.txt      : Instrucciones de compilación y ejecución.

Requisitos:
- Sistema operativo Linux o entorno compatible (WSL, Ubuntu, etc.).
- Compilador GCC.

Compilación:
gcc mi_shell.c -o mi_shell

Ejecución:
./mi_shell

Funcionalidades implementadas:
1. Muestra un prompt (mi_shell>).
2. Lee comandos ingresados por teclado.
3. Soporta múltiples argumentos.
4. Ejecuta comandos en foreground.
5. Maneja errores cuando el comando no existe.
6. Ignora líneas vacías (Enter sin comando).
7. Soporta el comando interno "exit" para terminar la shell.

# Ejemplos de uso:
mi_shell> pwd
mi_shell> ls -l
mi_shell> mkdir prueba
mi_shell> clear
mi_shell> exit

Repositorio:
[Agregar aquí la URL del repositorio una vez creado]

Autores:
- Constanza Fuentealba Millán
