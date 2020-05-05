#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
void AutoTest(void);
int func(FILE* restrict);

double mass(FILE* input){
    char a[514];
    char str[514];
    int k = 0;
    int t = 0;
    int j = 0;
    int m = 0;
    double num = DBL_MAX;


    if (!input){
        printf("Error! Cannot open file !\n");
        return -1;
    }
    else{
        if (fgets(str, 514, input)==NULL){
            printf("Error! No data!\n");
            return -1;
        }
        else{
            rewind(input);
            str[0]='\0';
            while(fgets(a, 514, input)!=NULL){
                for (int i=0; i<514; i++){
                    if (a[i]=='\n'){
                        a[i]='\0';
                    }
                }
                while(a[j]!='\0'){
                    if (a[j] == '"'){
                        m = j;
                        t++;
                        j++;
                        if ((t%2) != 0){
                            while(a[j] != '"'){
                                if(isdigit(a[j])!=0 || a[m+1]=='-'){
                                    str[k]=a[j];
                                    k++;
                                    j++;
                                }
                                else{
                                    j++;
                                }
                            }

                            str[k]='\0';
                            k=0;
                            //printf ("%s", str);
                            if(str[0]!='\0'){
                                    if (atoi(str) < num){
                                    num = atoi(str);
                                    //printf ("%f", num);
                                    }
                            }
                            str[0]='\0';
                        }
                        if ((t%2) == 0){
                            j++;
                        }
                    }
                    else{
                        j++;
                    }
                }
                a[0]='\0';
                j=0;
            }
            if ((num <= DBL_MAX) && (num >= DBL_MAX)){
                printf ("No such number\n");
                    return 404;
            }
            else{
                return num;
            }
        }
    }
}

void AutoTest (void){
    FILE* test;
    double i;

    test = fopen("test.txt", "r");
    i = mass(test);
    fclose(test);
    if ((i <= 1) && (i >= 1)){
        printf ("Autotest passed...\n");
    }
    else{
        printf("AutoTest failed\n");
    }
}




int main(void){
    double res = 0;
    FILE* output_file;
    FILE* input;
    input = fopen("text.txt", "r");
    output_file = fopen("data.txt", "w");
    AutoTest();
    res = mass(input);
    fprintf(output_file,"%lf\n",res);
    printf("%lf\n",res);
    fclose(input);
    fclose(output_file);
    return 0;
}
