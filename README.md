### scripts scritos na linguagem C
- sistemas distribuidos
- programação paralela usando MPI (varios processos ao mesmo tempo)
___

### MPI (linux)

install mpi:
```    
sudo apt install libopenmpi-dev
```
compile:

```
mpic -g -Wall -o 4-broadcast-send-recv 4-broadcast-send-recv.c
```
or
```
mpic++ -g -Wall -o 4-broadcast-send-recv 4-broadcast-send-recv.c
```
execute:
```
mpiexec -np 2 ./5-broadcast
```
or
```
mpirun --mca shmem posix --oversubscribe -np 10 ./5-broadcast
```
### OpenMP
compile:
```
gcc -g -Wall -fopenmp -o 1_hello 1_hello.c
```