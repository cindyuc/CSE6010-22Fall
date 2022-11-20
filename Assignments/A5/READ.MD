*Only for CSE6010 (Gatech) Assignment 5*

Compiler: gcc

Operating System: Ubuntu x86_64 GNU/Linux


You can compile code using the command:

```
base> make
```

Then, follow the instruction that `Enter the number of threads for parallelization`.

If there is an error, please try following command:
```
base> gcc -fopenmp -o diffusion diffusion.c 
      export OMP_NUM_THREADS=?
```

Replace `?` with the number of threads you want to use in parallelizaion.

<br>

After no errors, the compiler will generate an binary file *diffusion*. Run this program using the command:
```
base> ./diffusion sizeOfArray   

or

base> ./diffusion sizeOfArray location
```

`sizeOfArray` is the size of array N.

`location` is optional, which is the location of the initially heated element. You are not required to give a location. If you don't give a location, the program will use a random value along the array representing the rod.

