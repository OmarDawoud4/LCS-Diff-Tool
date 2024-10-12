#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcs.h"

int lcs_length(const char *str1, const char *str2, int m, int n) {
    int **dp = malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    int length = dp[m][n];

    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    
    return length;
}

void print_lcs(const char *str1, const char *str2, int m, int n) {
    int **dp = malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = malloc((n + 1) * sizeof(int));
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    int index = dp[m][n];
    char *lcs = malloc((index + 1) * sizeof(char));
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("Longest Common Subsequence: %s\n", lcs);

    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    free(lcs);
}