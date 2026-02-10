/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/

#include <stdio.h>

int main() {
    char s[100];
    scanf("%s", s);

    int left = 0, right = 0;

    // Find length
    while (s[right] != '\0') {
        right++;
    }
    right--;  // last character index

    // Two-pointer comparison
    while (left < right) {
        if (s[left] != s[right]) {
            printf("NO");
            return 0;
        }
        left++;
        right--;
    }

    printf("YES");
    return 0;
}
