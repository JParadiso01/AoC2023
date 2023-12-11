#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char* sliceString(char * string, int start, int end);

int main(){
    FILE *f = fopen("day1input.txt", "r");
    char line[100];
    char ints[100];
    int intcount = 0;
    char num[3];
    int sum = 0;

    while(fgets(line, 100, f)){
        intcount = 0;
        while(line[0] != '\0'){
            if (isdigit(line[0])){
                ints[intcount] = line[0];
                intcount++;
            }
            if (strlen(line) >= 3){
                if (!strncmp("one", line, 3)){
                    ints[intcount] = '1';
                    intcount++;
                }
                if (!strncmp("two", line,3)){
                    ints[intcount] = '2';
                    intcount++;
                }
                if (!strncmp("six", line, 3)){
                    ints[intcount] = '6';
                    intcount++;
                }
            }
             if (strlen(line) >= 4){
                if (!strncmp("four", line, 4)){
                    ints[intcount] = '4';
                    intcount++;
                }
                if (!strncmp("five", line, 4)){
                    ints[intcount] = '5';
                    intcount++;
                }
                if (!strncmp("nine", line, 4)){
                    ints[intcount] = '9';
                    intcount++;
                }
            }
            if (strlen(line) >= 5){
                if (!strncmp("eight", line, 5)){
                    ints[intcount] = '8';
                    intcount++;
                }
                if (!strncmp("three", line, 5)){
                    ints[intcount] = '3';
                    intcount++;
                }
                if (!strncmp("seven", line, 5)){
                    ints[intcount] = '7';
                    intcount++;
                }
            }
            strcpy(line, sliceString(line, 1,100));
        }

        //concats the numbers
        num[0] = ints[0];
        num[1] = ints[intcount-1];
        num[2] = '\0';
        sum += atoi(num);
    }
    printf("final sum: %d", sum);
    return 0;
}


char* sliceString(char* string, int start, int end){
    //gets size of new string
    //add 2 becuase of math + null
    int size = end-start+2;
    char *newString = (char *)malloc(size * sizeof(char));
    for (int i = 0; start <= end; start++, i++){
        newString[i] = string[start];
    }
    newString[size] = '\0';
    return newString;
}