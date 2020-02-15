#include<stdio.h>
#define my_s(type) (char*)(&type+1)-(char*)(&type)
struct test{
    int dub;
    double num;
    char name;



    ///truct test another;
};
void main(){
    struct test *myTest;
    struct test mytt;
    struct test myt[2];
    int myt0 = myt;
    int myt1 = myt+1;
    char ty;


    printf(" %d\n",myt1-myt0);
    printf("int size %d \n", sizeof(int));
    printf("int size %d \n", sizeof(double* ));
    printf("char size %d \n", sizeof(char*));
    printf("MY_S mytt size %d \n", my_s(mytt));


    printf("myt %d \n",sizeof(struct test));
    printf("*myTest %d \n",sizeof(myTest));


    ///printf("Without size of operator %d", mysize);
    int size = (char *)(&mytt+1) - (char *)(&mytt);
    unsigned int siz = (char *)(&myt+1) - (char *)(&myt);
    printf("size of operator %d\n", siz);
    printf(" hufi %d",sizeof(siz));

}
