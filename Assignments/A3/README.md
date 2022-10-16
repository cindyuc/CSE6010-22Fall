*Only for CSE6010 (Gatech) Assignment 3*

Compiler: Clang

Operating System: macOS Monterey Version 12.6


You can modify the main.c and compile your code using the command:

```
base> make
```

If there is an error, please try following command:
```
base> gcc -o divisorgraph main.c divisorgraph.c
```

After no errors, the compiler will generate an executable program *singleLinkedList*. Run this program using the command:
```
base> ./divisorgraph NumberOfVertices d/b
```
where `d` represent Dijkstra's algorithm, `b` represents Bellman-Ford algorithm

For example, if you want to generate a graph with 500 vertices, and you want to use Dijkstra's algorithm in searching, you can use folloing command:
```
base> ./divisorgraph 500 d
```

If you have no idea about generation, you can use default arguments with follow command:
```
base> ./divisorgraph
```
The default arguments are `numbervertices = 1000`, `algorithm = Dijkstra's algorithm`


