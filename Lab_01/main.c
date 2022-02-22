#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    //functions
    void dec_to_bin(char *bin, int dec, int size){
        for(int i=size-1;i>=0;i--){
            bin[i]=(dec&1)+'0';
            dec=dec>>1;
        }
    }
    int k_bit_of_number(int number, int k_bit){
        return (number>>k_bit-1)&1;
    }
    //site:=true => right
    //site:=false => left
    int move_by_a_bit_in_site(bool site, int number, int number_of_bits){
        if(site){
            return number>>number_of_bits;
        }
        return number<<number_of_bits;
    }


    //main
    int size=8;
    char binar[size];
    for(int i=0;i<size;i++){
        binar[i]='0';
    }
    //Zadanie 1
    dec_to_bin(&binar,25,size);
     for(int i=0;i<size;i++){
        printf("%c",binar[i]);
    }
    printf("\n");
    //Zadanie 2
    printf("%i",k_bit_of_number(25,5));
    printf("%i",k_bit_of_number(25,4));
    printf("%i",k_bit_of_number(25,3));
    printf("%i",k_bit_of_number(25,2));
    printf("%i",k_bit_of_number(25,1));
    printf("\n");
    //Zadanie 3 (IDK, czy o to chodzi³o???)
    printf("%i\n",move_by_a_bit_in_site(true,2,1));
    printf("%i",move_by_a_bit_in_site(false,2,2));
    return 0;
}
