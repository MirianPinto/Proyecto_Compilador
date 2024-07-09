Este proyecto fue realizado en 2024 en le sistema operativo ubuntu con el lenguaje de c++ y la utilización de diferentes herramientas como ser Bison, Flex, TreeCC y EasyASM, este tiene como finalidad simular un compilador del lenguaje LPP realizado por el ingeniero Ivan Deras,
realizando cada una de las capas que un compilador tiene, empezando de su análisis lexico, análisis sintactico, análisis semantico, y generación de codigo.

En cada una de las etapas se realizaron utilizando las herramientas de la siguiente manera:
1. Análisis Lexico: Flex
2. Análisis Sintactico: Bison
3. Análisis Semantico: Trecc
4. Generacián de codigo: Trecc

Para la parte final de generacion de codigo, este genera el codigo en un archivo de texto el cual luego con la herramienta de EasyASM la cual fue desarrollada por el ingeniero Ivan Deras, genera el archivo ejecutable para luego ser ejecuta por el mismo.

El resultado que da un codigo es el sigueinte:
1) Error de Sintaxis.
2) 1 - Error en semantica.
3) 0 - Codigo ejecutado correctamente.


Para poder utilizar este proyecto debes clonar el repositorio para tu IDE en wsl y en wsl utilizar los siguientes comandos para descargar las herramientas:

  	sudo apt update
  
  	sudo apt install Bison
  
  	sudo apt install Flex
  
Pra instalar TreeCC:

	git clone https://github.com/rweather/treecc

	sudo apt-get install autoconf automake libtool build-essential
  
  - Dentro de la carpeta clonada

	cd ~/treecc

	autoreconf -i

	./configure

	make

	sudo make install
