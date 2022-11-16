//
// Created by yrash on 31/10/2022.
//

#define BOOL char
#define TRUE 1
#define FALSE 0
#define ABS(x) ((x * 2 + 1) % 2) * x
#define MAX(a, b) 0.5 * (a + b) + 0.5 * ABS((a - b)) // keep in mind the value is return as float
#define MIN(a, b) 0.5 * (a + b) - 0.5 * ABS((a - b)) // keep in mind the value is return as float
#define IS_ODD(x) (x % 2)
#define IS_EVEN(x) !IS_ODD(x)
#define SUM_TWO_NUMBERS(a, b) a + b
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define EIGHT 8
#define TEN 10