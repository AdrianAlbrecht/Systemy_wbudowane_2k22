#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    //functions
    void dec_to_bin(int *bin, int dec, int size){
        for(int i=size-1;i>=0;i--){
            bin[i]=(dec&1);
            dec=dec>>1;
        }
    }
    int bin_to_dec(int *bin, int size){
        int number=0;
        int mno=1;
        for(int i=size-1;i>=0;i--){
            number+=bin[i]*mno;
            mno=mno<<1;
        }
        return number;
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
    //prng 1110011
    int prng(int seed,int power){
        if(seed>0){
            int john_seed=seed;
            int joseph_seed=seed;
            for(int i=0;i<power;i++){
                int oldest_bit = ((k_bit_of_number(john_seed,1)^k_bit_of_number(john_seed,2))^k_bit_of_number(john_seed,5))^k_bit_of_number(john_seed,6);
                joseph_seed=john_seed>>1;
                if(oldest_bit==1){
                    joseph_seed=joseph_seed|32;
                }
                john_seed=joseph_seed;
            }
            return joseph_seed;
        }
        return 0;
    }
    void prng_linear(int seed){
        int new_seed=seed;
        do{
            new_seed = prng(new_seed,1);
            printf("%i, ",new_seed);
        } while ( new_seed!=seed );
        printf("\n");
    }
    void prng_linear_bin(int seed){
        int size=6;
        int binar[size];
        for(int i=0;i<size;i++){
            binar[i]=0;
        }
        int new_seed=seed;
        do{
            new_seed = prng(new_seed,1);
            dec_to_bin(&binar,new_seed,size);
            for(int i=0;i<size;i++){
                printf("%i",binar[i]);
            }
            printf(", ");
        } while ( new_seed!=seed );
        printf("\n");
    }
    //main
    int size=6;
    int binar[size];
    for(int i=0;i<size;i++){
        binar[i]=0;
    }
    //Zadanie 1
    printf("=============Zadanie 1==============\n");
    dec_to_bin(&binar,25,size);
    for(int i=0;i<size;i++){
        printf("%i",binar[i]);
    }
    printf("\n");
    printf("%i\n",bin_to_dec(&binar,size));
    //Zadanie 2
    printf("=============Zadanie 2==============\n");
    printf("%i",k_bit_of_number(25,6));
    printf("%i",k_bit_of_number(25,5));
    printf("%i",k_bit_of_number(25,4));
    printf("%i",k_bit_of_number(25,3));
    printf("%i",k_bit_of_number(25,2));
    printf("%i",k_bit_of_number(25,1));
    printf("\n");
    //Zadanie 3 (IDK, czy o to chodzi³o???)
    printf("=============Zadanie 3==============\n");
    printf("2>>1: %i\n",move_by_a_bit_in_site(true,2,1));
    printf("2<<2: %i\n",move_by_a_bit_in_site(false,2,2));
    //Zadanie 4
    printf("=============Zadanie 4==============\n");
    int prng_number=prng(1,4);
    printf("%i: ",prng_number);
    dec_to_bin(&binar,prng_number,size);
    for(int i=0;i<size;i++){
        printf("%i",binar[i]);
    }
    printf("\n");

    printf("Number series of PRNG 1110011 with seed 1:\n");
    prng_linear(1);
    prng_linear_bin(1);

    return 0;
}
