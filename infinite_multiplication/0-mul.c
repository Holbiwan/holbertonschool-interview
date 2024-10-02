#include <stdio.h>    // for putchar
#include <stdlib.h>   // for calloc, free
#include <string.h>   // for strlen

void multiply(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int *result = calloc(len1 + len2, sizeof(int));
    int i, j;

    // Loop through each digit of num1 and num2
    for (i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        for (j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0');
            int temp_sum = product + result[i + j + 1] + carry;
            result[i + j + 1] = temp_sum % 10;
            carry = temp_sum / 10;
        }
        result[i + j + 1] += carry;
    }

    // Print result, skipping leading zeros
    int started = 0;
    for (i = 0; i < len1 + len2; i++) {
        if (result[i] != 0) {
            started = 1;
        }
        if (started) {
            putchar(result[i] + '0');
        }
    }
    if (!started) {
        putchar('0');  // In case the result is zero
    }
    putchar('\n');

    free(result);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Error\n");
        return (98);
    }
    multiply(argv[1], argv[2]);
    return (0);
}
