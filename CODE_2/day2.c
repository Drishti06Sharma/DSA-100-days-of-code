/*Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left
*/
#include <stdio.h>
int main() {
    int n, i, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int al[100];
    printf("Enter %d elements for array:", n);
    for (k = 0; k < n; k++)
        scanf("%d", &al[k]);
     printf("\nEnter position to delete (0-%d): ", n - 1);
    scanf("%d", &i);
    for (k = i; k < n - 1; k++)
        al[k] = al[k + 1];
    n--;
    for (k = 0; k < n; k++)
        printf("%d ", al[k]);
    return 0;
}
