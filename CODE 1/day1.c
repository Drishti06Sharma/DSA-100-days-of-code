/*Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right
*/
#include <stdio.h>
int main() {
    int n, i, j, k;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int al[100];
    printf("Enter %d elements for array:", n);
    for (k = 0; k < n; k++)
        scanf("%d", &al[k]);
    printf("Enter a position 0-%d : ", n);
    scanf("%d", &i);
    printf("Enter the number to add at position %d: ", i);
    scanf("%d", &j);
    for (k = n; k > i; k--)
        al[k] = al[k - 1];
    al[i] = j;
    n++;
    for (k = 0; k < n; k++)
        printf("%d ", al[k]);
    return 0;
}