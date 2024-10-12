# Text Comparison Utility

The program uses a dynamic programming approach to solve the LCS (Longest Common Subsequence) problem, similar to the core algorithm in GNU diff.

## Files

- **diff.c**: Main program that handles file I/O and calls LCS functions.
- **lcs.c**: Implementation of the LCS algorithm.
- **lcs.h**: Header file for LCS functions.
- **file1.txt**: Sample input file.
- **file2.txt**: Sample input file for comparison.

## How it Works

The program employs a dynamic programming approach to solve the LCS problem. It builds a table of LCS lengths for all pairs of prefixes of the two strings, then backtracks to construct the LCS itself.
