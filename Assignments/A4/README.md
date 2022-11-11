*Only for CSE6010 (Gatech) Assignment 4*

Compiler: Clang

Operating System: macOS Monterey Version 12.6

<br/>

You can modify the main.c and compile your code using the command:

```
base> make
```

If there is an error, please try following command:
```
base> gcc -o airport airportmain.c sort.c flights_io.c
```

<br/>

After no errors, the compiler will generate an executable program *airport*. Run this program using the command:
```
base> ./airport input_file's name i/h/m
```
`input_file's name`: the name of file containing flight information

 `i`: insertion sort
 
 `h`: heap sort

 `m`: merge sort


<br/>

For example, if you want to sort the information in file `test_times_new.csv` by merge sort, you can use following command:
```
base> ./airport test_times_new.csv m
```

If you have no idea about sort algorithm, you can use default sort and only assign input file:
```
base> ./airport test_times_new.csv
```
The default sort algorithm is `insertion sort`.


