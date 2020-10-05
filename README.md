## Generar el archivo
* El main llama a la función output (la cual es llamada en el destructor), la cual crea el archivo `grafo.vz`.
* Para generar el .pdf se debe ejecutar el comando `dot -Tpdf grafo.vz -o grafo.pdf` (se ejecuta al finalizar la llamada a `output()`).
* El pdf tendrá la imagen del binomial heap.
* Si el binomial heap tiene nodos con valores repetidos, se generará un gráfico incorrecto.