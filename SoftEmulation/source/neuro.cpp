#include "Float32.h"
#include "Float64.h"
#include "SoftFloat16.h"
#include "SoftFloat32.h"
#include "SoftFloat64.h"
#include "SoftQuire32.h"
#include "SoftQuire16.h"
#include "SoftQuire8.h"
#include "SoftPosit/softposit_cpp.h"
#include "myneuro.h"

typedef SoftQuire32 TYPE;

int main(int argc, char *argv[])
{
    myNeuro<TYPE> *bb = new myNeuro<TYPE>();

     //----------------------------------INPUTS----GENERATOR-------------
        TYPE *abc = new TYPE[100];
            for(int i=0; i<100;i++)
            {
            abc[i] =(i%98)*0.01+0.01;
            }

        TYPE *cba = new TYPE[100];
            for(int i=0; i<100;i++)
            {
            cba[i] =((100 - i)%98)*0.01+0.01;
            }

    //---------------------------------TARGETS----GENERATOR-------------
        TYPE *tar1 = new TYPE[2];
        tar1[0] =0.01;
        tar1[1] =0.99;
        TYPE *tar2 = new TYPE[2];
        tar2[0] =0.99;
        tar2[1] =0.01;

    //--------------------------------NN---------WORKING---------------
        bb->query(abc);
        std::cout <<"_________________________________\n";
        bb->query(cba);

        int i=0;
        while(i<10000)
        {
            bb->train(abc,tar1);
            bb->train(cba,tar2);
            i++;
            if (i%1000 == 0)
                std::cout << i/100 << "%\n";
        }

        std::cout <<"___________________RESULT_____________\n";
        bb->query(abc);
        std::cout <<"______\n";
        bb->query(cba);


        std::cout <<"_______________THE____END_______________\n";

    return 0;
}