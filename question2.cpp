//author: Martin Gonzales

/* Idea: User binary search by recursive function to find
 * repeating element since binary search takes O(log n)
 *
 * Plan: The array is always sorted, we will keep dividing the
 * array in half until we find the repeating element. Note that
 * we will compare the element value and its index number to find 
 * out whether the repeating number is in the left or right tree.
 * This way, binary search applies. */

#include <stdio.h>

//function
int findDuplicate(int a[], int start, int end)
{
    //find the middle point
    int middle = (end + start) / 2;

    //check if the middle element is the correct mid index
    if(a[middle] == middle+1) {
        return findDuplicate(a, middle+1, end); //The repeating is at right tree
    }
    else {
        if (a[middle] == a[middle - 1]) {
            return a[middle]; //the base case, will return correct value after one/multiple recursive calls.
        }
        else {
            return findDuplicate(a,start, middle-1); //The repeating is at left tree
        }
    }
}

//driver
int main() {
    //given arrays
    int array1[] = {1, 1, 2, 3, 4, 5, 6, 7};
    int array2[] = {1, 2, 3, 4, 4, 5, 6, 7};
    int array3[] = {1, 2, 3, 4, 5, 6, 7, 7};
    //getting array size using sizeof, sizeof returns bit size
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int size3 = sizeof(array3) / sizeof(array3[0]);
    //result
    int dup1 = findDuplicate(array1, 0, size1-1);
    int dup2 = findDuplicate(array2, 0, size2-1);
    int dup3 = findDuplicate(array3, 0, size3-1);
    //output
    printf("RESULT#1 = %d\nRESULT#2 = %d\nRESULT#3 = %d\n", dup1,dup2,dup3);
    return 0;
}