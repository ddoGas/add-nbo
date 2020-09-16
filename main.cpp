#include <stdio.h>
#include <stdint.h>
//#include <netinet/in.h>
#include "my_htonl.h"

int main(int argc, char* argv[]){
    FILE *fp1, *fp2;
    uint32_t n1, n2, sum;

    if(argc != 3){
        printf("syntax: ./add-nbo <file1> <file2>\n");
        return -1;
    }

    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");

    fread(&n1, 4, 1, fp1);
    fread(&n2, 4, 1, fp2);

    n1 = my_htonl(n1);
	n2 = my_htonl(n2);
	sum = n1 + n2;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, sum, sum);

	fclose(fp1);
	fclose(fp2);
}