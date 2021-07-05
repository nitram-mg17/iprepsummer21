//author: Martin Gonzales

/* Idea: Use binary search since rows and columns are sorted! We
 * are searching for n * m rows. Since binary search takes 0(logn)
 * for n, and O(logm) for m, the time complexity will be
 * O(logn + logm) or O(log(n*m));
 *
 */

#include <stdio.h>

//set value to find and matrix size
static const int row_size = 5;
static const int col_size = 5;
static const int find = 20;

//function
void search(int M[][row_size], int row_size, int col_size, int find) {
    //initialize variables
	int start = 0; //beginning element
	int end = row_size * col_size - 1; //last element
	int val, row, col, middle;
	while (start <= end) {
		middle = start + (end - start) / 2; //find the mid element for bin search
		row = middle / col_size; //update row index
		col = middle % col_size; //update column index
		val = M[row][col]; //get the value at specific index
        
        //print if found
		if (find == val) {
			printf("%d FOUND!\nCOORDS: (%d, %d)\n", find, col, row);
			return;
		}
        //else, if find is larger than calculated, go to right tree
		if (find > val) start = middle + 1;
        // if lexx, go to left tree
		else end = middle - 1;
	}
    printf("%d NOT FOUND!\n", find);
}

//driver
int main() {
    //set matrix
    int A[row_size][col_size] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9,10},
        {11, 12, 13, 14,15},
        {16, 17,18, 19, 20},
        {21, 22,23, 24, 25},};
    search(A, row_size, col_size, find);
    return 0;
}

