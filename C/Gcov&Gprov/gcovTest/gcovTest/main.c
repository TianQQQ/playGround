//
//  main.c
//  gcovTest
//
//  Created by Tian Qiu on 16/5/10.
//  Copyright © 2016年 Prof.Lu, it is from Prof. LU 's C book
//

// comppartition.c
// partition using alternating odd and even numbers
// two ways to implement the partition:
// 1. check before recursive calls
// 2. generate all partitions and check before printing

#include <stdio.h>
#include <stdlib.h>
void printPartition(int * arr, int length){
    int ind;
    for (ind = 0; ind < length - 1; ind ++)
    {
        printf("%d + ", arr[ind]);
    }
    printf("%d\n", arr[length - 1]);
}
// 1. generate only valid partitions
void partition1(int * arr, int ind, int left)
{
    int val;
    if (left == 0) {
        printPartition(arr, ind);
        return; }
    for(val = 1; val <= left; val ++)
    {
        int valid = 0;
        if (ind == 0) // no restriction for the first number
        {
            valid = 1;
        }
        else
        {
            valid = (arr[ind - 1] % 2) != (val % 2);
        }
        if (valid == 1)
        {
            arr[ind] = val;
            partition1(arr, ind + 1, left - val);
        }
    }
}

// 2. before printing, check whether the partition is valid
// check whether the numbers are alternating odd and even
// return 1 if valid
// return 0 if invalid


int isValid(int    * arr, int len){
    if (len <= 1) {
        return 1; }
 
    int ind;
    
















































