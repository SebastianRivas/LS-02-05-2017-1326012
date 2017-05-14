NOMBRES Y APELLIDOS: JUAN SEBASTIÁN RIVAS GALLEGO
CÓDIGO: 1326012-2711
DESCRIPCIÓN: EJERCICIOS PROPUESTOS EN CLASE SOBRE MPI

mpiEx2a.c
Este ejercicio consiste en observar los procesos concurrentes que se ejecutan en un instante de tiempo, la solución del ejercicio consistió en identificar el proceso maestro (rank=0) y los procesos esclavos, el proceso maestro imprime en consola el numero de procesos en ejecución, los procesos esclavos imprimen su identificación y el numero de proceso asignado en ejecución.

mpiEx2b.c
Este ejercicio consiste en observar los procesos concurrentes que se ejecutan en un instante de tiempo, la solución del ejercicio consistió en identificar el proceso maestro (rank=0) e imprimir en consola los procesos esclavos que se encuentran en ejecución.

mpiEx3a.c
Este ejercicio consiste en observar la comunicación entre procesos concurrentes, la solución del ejercicio consistió en identificar el proceso maestro (rank=0) y los procesos esclavos (rank!=0). El proceso maestro enviá un mensaje a los procesos esclavos y queda a la espera de la respuesta de estos, los procesos esclavos reciben el mensaje enviado por el maestro y le envían un mensaje de respuesta. Todos los procesos imprimen en consola el mensaje que recibieron.

mpiEx3b.c
Este ejercicio consiste en observar la comunicación entre procesos concurrentes, la particularidad del ejercicio consiste en formar un anillo mientras se pasan los mensajes entre procesos (0→1, 1→2, 2→3, 3→4, 4→5, 5→n,…, n→0). La solución del ejercicio consistió en identificar el proceso maestro (rank=0) quien despliega el paso de mensajes entre procesos. Todos los procesos imprimen en consola el mensaje que recibieron.

mpiEx4a.c
Este ejercicio consiste en observar como los procesos concurrentes trabajan en un bloque de información que les ha sido enviado, el proceso maestro es quien enviá el bloque y recibe los resultados de los procesos esclavos para luego almacenarlo en una variable.

mpiEx4b.c
Este ejercicio consiste en observar el funcionamiento de la función MPI_Reduce. La solución del problema consistió en remplazar los bloques de código en donde los procesos realizaban operaciones con el bloque de datos y el envió del resultado al maestro por la función MPI_Reduce.

broadcast.c
Este ejercicio consiste en observar el funcionamiento de la función MPI_Bcast para el envió de información a varios procesos desde el proceso maestro.

myBcast.c
Este ejercicio consiste en implementar la función MPI_Bcast con las funciones MPI_Recv y MPI_Send.  La solución del ejercicio consistió en colocar a los procesos esclavos a la espera de un mensaje por parte del proceso maestro.
Axb.c
Este ejercicio consiste en implementar la multiplicación de una matriz A de dimensiones mxn con un vector b de dimensiones nx1. La solución del ejercicio consistió en dividir en filas la matriz A y esta filas enviarlas a los procesos esclavos, los procesos esclavos por medio de un broadcast ya contaban con el vector b para multiplicar la fila recibida por el vector, una vez finalizada la multiplicación el proceso esclavo le enviá el resultado al maestro y el maestro le enviá (si aun hay) otra fila de la matriz para que sea procesada.
NOTA: Para este ejercicio NO se cumplió con la meta de resolverlo en un 100%, se tuvieron problemas con la recepción de los datos por parte de los procesos esclavos, el maestro solo enviá 7 bloques de datos y se queda esperando a que los esclavos le responda, los esclavos responden pero el maestro no vuelve a enviar bloques de datos para procesar. Por tal motivo el ejercicio en la logica del procesamiento de datos y la particion de la matriz es funcional pero en el paso de mensajes es deficiente en su funcionamiento.
