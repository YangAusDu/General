This file contains three different sorting programs:
bubble_sort；

merge_sort  &

selection_sort.

whereas
mysort is a collection of the above three.




To compile the program, pls do the following steps:

1. gcc -Wall -std=c99 -c bubble_sort.c merge_sort.c selection_sort.c sorting.c util.c 

then you will get a object file for each of those.

2. gcc -Wall -std=c99  bubble_sort.o merge_sort.o selection_sort.o sorting.o util.o  -o "the name of your program".

To acquire the final program. 