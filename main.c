//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

//Other files in this project
#include "core.h"


void printhelp() {
    printf("To compute values of A267263:\n");
    printf("\tRun `./program.o compute $file $number`\n");
    printf("\tThis computes from 0 to $number (inclusive) of the sequence, and stores it in $file . To retrieve this, read below\n");
    printf("\nTo read stored files:\n");
    printf("\tRun `./program.o read $file $number [$offset]`\n");
    printf("\t$offset is optional, and defaults to 0\n");
    printf("\tThis reads in starting at $offset and reads till $offset + $number (inclusive)\n");
}

int main(int argc, char *argv[]) {
    //If they don't enter enough args
    if (argc < 4) {
        printhelp();
        return 1;
    }
    //What operation? Read or Compute?
    char *operation = argv[1];
    //File to read/write
    char *file = argv[2];
    //How many to read or write
    long long int number = strtoll(argv[3], NULL, 0);
    //If we are reading, where do we start at?
    long long int offset = 0;
    if (argc >= 5) {
        offset = strtoll(argv[4], NULL, 0);
    }
    //Initialize data array, with 1 extra byte
    int8_t *data = (int8_t *)malloc(sizeof(int8_t) * (number + 2));
    //Initialize loop var
    int i;
    //Quick lowercase to catch any mistypes
    for (i = 0; operation[i]; i++) {
        operation[i] = tolower(operation[i]);
    }
    //Tell the user what they entered
    printf("Now doing operation: %s on file: %s\n", operation, file);
    //Compare it to see which operation they entered
    if (strcmp(operation, "compute") == 0) {
        //Run compute to fill data
        compute(number, data);
        //Open file with what they entered
        FILE *fp;
        fp = fopen(file, "w+");
        //Write them as bytes
        fwrite(data, sizeof(int8_t), number + 1, fp);
        //Close
        fclose(fp);
    } else if (strcmp(operation, "read") == 0) {
        //Open just for reading
        FILE *fp;
        fp = fopen(file, "r");
        //Seek the start at start position
        fseek(fp, offset, SEEK_SET);
        //Read in bytes starting at offset
        fread(data, sizeof(int8_t), number + 1, fp);
        //Tell user the format
        printf("Format is $index:$value\n");
        //Loop through and print out
        for (i = 0; i <= number; ++i) {
            //Print out with colon, and a tab between
            printf("%d:%d\t", (int)(i + offset), data[i]);
        }
        //Close
        fclose(fp);
    }
    //Print more lines
    printf("\n\n");
}
