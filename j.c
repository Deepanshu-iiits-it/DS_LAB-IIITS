/*-----------------------------------------------------------------------------------------
                                    PROGRAM-(j)

Write C programs for implementing the following sorting methods to arrange a list of 
 integers in ascending order:

	a.	Quick sort
    b.	Selection sort

-------------------------------------------------------------------------------------------
BY: DEEPANSHU MITTAL 11912056 I.T.
-------------------------------------------------------------------------------------------*/

#include<stdio.h>


void ssort(int* a, int n)       //function for selection sort
{
    for(int i=0;i<n;i++)
    {
        int p=i;
        int m=a[i];

        for(int j=i+1;j<n;j++)
        {
            if(a[j]<m)
            {
                m=a[j];
                p=j;                //finding smallest element in the rest of the left array
            
            }

        }

        int t=a[i];                 //swap a[i] with a[p]
        a[i]=a[p];
        a[p]=t;

    }

}


/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */

int partition (int *a, int l, int h) 
{ 
    int pivot = a[h];    // pivot 
    int i = (l - 1);  // Index of smaller element 
  
    for (int j = l; j <= h- 1; j++) 
    { 
                                    // If current element is smaller than the pivot 
        if (a[j] < pivot) 
        { 
            i++;                    // increment index of smaller element 

            int t=a[i];                //swap a[i] and a[j]
            a[i]=a[j];
            a[j]=a[i];
             
        } 
    
    } 

    int t=a[i+1];
    a[i + 1]=a[h];
    a[h]=t;

    return (i + 1); 

} 
  
/* The main function that implements QuickSort 
 a[] --> Array to be sorted, 
  l  --> Starting index, 
  h  --> Ending index */

void qsort(int* a, int l, int h) 
{ 
    if (l < h) 
    { 

        int pi = partition(a, l, h);     /* pi is partitioning index, arr[p] is now 
                                               at right place */
        
                                            // Separately sort elements before 
                                            // partition and after partition 
        qsort(a, l, pi - 1); 
        qsort(a, pi + 1, h); 

    } 

} 


void main()
{

    int n;              //size of the array

    printf("n enter the size of array ");
    scanf("%d",&n);

    int a[n];               // let a be the array

    printf("\n enter the elements of the array ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("\n To sort the given array using the following method enter\n1- Quick sort \n2-Selection sort ");
    
    int wish;
    scanf("%d",&wish);          //input whether to sort using selection sort or quick sort

    switch(wish)
    {
        case 1: { 
                    qsort(a,0,n);
                    printf("\n the array in ascending order : ");

                    for(int k=0;k<n;k++)
                        printf("%d ",a[k]);

                    break;
                }

        case 2: { 
                    ssort(a,n);
                    printf("\n the array in ascending order : ");

                    for(int k=0;k<n;k++)
                        printf("%d ",a[k]);

                    break;
                }

        default: printf("\n Invalid choice");

    
    }

}