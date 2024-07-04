#include "src/list.h"
#include <time.h>
#include <stdlib.h>
#define N 10


int main(int argc, char *argv[])
{
    size_t n = 0;
   if(argc == 1) 
   {
    printf("Please set the number of elements to insert: ./main <number>\n");
    return 0;
   } 
   else
        n = atoi(argv[1]);

   
    srand(time(NULL));
    List* myFirstList = list_new();
    List* mySecondList = list_new();

    printf("Testing insertion of: ");
    
    for (size_t i = 0; i < n; i++)
    {
        int number = rand() % N;
        printf("%d ", number);
        list_push_back(myFirstList, number);
        list_push_front(mySecondList, number);
    }
    printf("\n");

    list_traverse(myFirstList);
    list_reverse(mySecondList);

    list_reverse(myFirstList);  
    list_traverse(mySecondList); 

    for (size_t i = 0; i < n/2; i++)
    {
        list_pop_front(myFirstList);
        list_pop_back(mySecondList);
    }

    list_traverse(myFirstList);  
    list_reverse(mySecondList);

    int delNumber = rand() % N;

    printf("Remove key: %d\n", delNumber);

    list_remove(myFirstList, delNumber);
    list_remove(mySecondList, delNumber);
    list_traverse(myFirstList);  
    list_reverse(mySecondList);  

    return 0;
}