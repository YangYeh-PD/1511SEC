# 1511SEC
## Catalog
Here is the project to implement <b>(15,11) <a href = "https://en.wikipedia.org/wiki/Hamming_code">Hamming Code </a></b> (Single Error Correction).  
For the given Sender and Receiver data,
```
Sender
0 0 1 0 
1 1 1 0 
0 0 1 0 
1 1 1 0 
Receiver
0 1 0 0 
1 1 1 0 
1 0 1 1 
1 1 1 0 
```
We can get the error bit and modify it immediately.
```
The error bit is at
row : 2
col : 3
Receiver (After Correction)
0 1 0 0 
1 1 1 0 
1 0 1 0 
1 1 1 0 
```

## Running Commands
We using `make` to create the execution file, then we put `data.txt` into `1511SEC.exe` to get results.

```
> make
g++ -c 1511SEC.cpp Data.h
g++ -c Data.cpp Data.h
g++ -o 1511SEC 1511SEC.o Data.o
> ./1511SEC < Data.txt
The error bit is at
row : 2
col : 3
Receiver (After Correction)
0 0 1 0 
1 1 1 0 
1 0 1 0 
1 1 1 0 

```