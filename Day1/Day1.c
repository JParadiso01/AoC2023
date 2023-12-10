#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    FILE *f = fopen("day1input.txt", "r");
    char line[100];
    char ints[100];
    int intcount = 0;
    char num[3];
    int count = 0;

    while(fgets(line, 100, f)){
        intcount = 0;
        for(int i = 0; i < 100; i++){
            if (line[i] == '\0'){
                break;
            }
            if (isdigit(line[i])){
                ints[intcount] = line[i];
                intcount ++;
            }
        }
        num[0] = ints[0];
        num[1] = ints[intcount-1];
        num[2] = '\0';
        count += atoi(num);
    }
    printf("final count: %d", count);
    return 0;
}