## Requisitos
Instalar graphviz
* Mac: `brew install graphviz`

## Generar el archivo
* La función `output()` es la encargada de generar el archivo `grafo.vz`. Esta función se llama en el destructor de la clase `BinomialHeap`.
* Para generar el .pdf se debe ejecutar el comando `dot -Tpdf grafo.vz -o grafo.pdf` (se ejecuta al finalizar la llamada a `output()`).
* El pdf tendrá la imagen del binomial heap.
* Si el binomial heap tiene nodos con valores repetidos, se generará un gráfico incorrecto.
