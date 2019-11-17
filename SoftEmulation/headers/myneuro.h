#ifndef MYNEURO_H
#define MYNEURO_H
#include <iostream>
#include <math.h>
#include <cstdlib>

#define learnRate 0.1

template <class T>
class myNeuro
{
public:
    myNeuro();

    struct nnLay{
           int in;
           int out;
           T** matrix;
           T* hidden;
           T* errors;
           int getInCount(){return in;}
           int getOutCount(){return out;}
           T **getMatrix(){return matrix;}
           void updMatrix(T *enteredVal)
           {
               for(int ou =0; ou < out; ou++)
               {

                   for(int hid =0; hid < in; hid++)
                   {
                       matrix[hid][ou].qma(learnRate * errors[ou], enteredVal[hid]);
                   }
                   matrix[in][ou].qma(learnRate, errors[ou]);
               }
           };
           void setIO(int inputs, int outputs)
           {
               in=inputs;
               out=outputs;
               hidden = (T*) malloc((out)*sizeof(T));

               matrix = (T**) malloc((in+1)*sizeof(T*));
               for(int inp =0; inp < in+1; inp++)
               {
                   matrix[inp] = (T*) malloc(out*sizeof(T));
               }
               for(int inp =0; inp < in+1; inp++)
               {
                   for(int outp =0; outp < out; outp++)
                   {
                       matrix[inp][outp] =  ( ((T)rand() / (T)RAND_MAX) - (T)0.5)* (T)pow(out,-0.5);
                   }
               }
           }
           void makeHidden(T *inputs)
           {
               for(int hid =0; hid < out; hid++)
               {
                   T tmpS = 0.0;
                   for(int inp =0; inp < in; inp++)
                   {
                       tmpS.qma(inputs[inp], matrix[inp][hid]);
                   }
                   tmpS += matrix[in][hid];
                   hidden[hid] = sigmoida(tmpS);
               }
           };
           T* getHidden()
           {
               return hidden;
           };
           void calcOutError(T *targets)
           {
               errors = (T*) malloc((out)*sizeof(T));
               for(int ou =0; ou < out; ou++)
               {
                   errors[ou].qma(targets[ou] - hidden[ou], sigmoidasDerivate(hidden[ou]));
               }
           };
           void calcHidError(T *targets,T **outWeights,int inS, int outS)
           {
               errors = (T*) malloc((inS)*sizeof(T));
               for(int hid =0; hid < inS; hid++)
               {
                   errors[hid] = 0.0;
                   for(int ou =0; ou < outS; ou++)
                   {
                       errors[hid].qma(targets[ou], outWeights[hid][ou]);
                   }
                   errors[hid] *= sigmoidasDerivate(hidden[hid]);
               }
           };
           T* getErrors()
           {
               return errors;
           };
           T sigmoida(T val)
           {
              return (1.0 / (1.0 + exp((-val).getFloat())));
           }
           T sigmoidasDerivate(T val)
           {
                return (val * (1.0 - val));
           };
    };

    void feedForwarding(bool ok);
    void backPropagate();
    void train(T *in, T *targ);
    void query(T *in);
    void printArray(T *arr,int s);

private:
    struct nnLay *list;
    int inputNeurons;
    int outputNeurons;
    int nlCount;

    T *inputs;
    T *targets;
};


template <class T>
myNeuro<T>::myNeuro()
{
    //--------многослойный
    inputNeurons = 100;
    outputNeurons =2;
    nlCount = 4;
    list = (nnLay*) malloc((nlCount)*sizeof(nnLay));

    inputs = (T*) malloc((inputNeurons)*sizeof(T));
    targets = (T*) malloc((outputNeurons)*sizeof(T));

    list[0].setIO(100,20);
    list[1].setIO(20,6);
    list[2].setIO(6,3);
    list[3].setIO(3,2);

    //--------однослойный---------
//    inputNeurons = 100;
//    outputNeurons =2;
//    nlCount = 2;
//    list = (nnLay*) malloc((nlCount)*sizeof(nnLay));

//    inputs = (T*) malloc((inputNeurons)*sizeof(T));
//    targets = (T*) malloc((outputNeurons)*sizeof(T));

//    list[0].setIO(100,10);
//    list[1].setIO(10,2);

}

template <class T>
void myNeuro<T>::feedForwarding(bool ok)
{
    list[0].makeHidden(inputs);
    for (int i =1; i<nlCount; i++)
        list[i].makeHidden(list[i-1].getHidden());

    if (!ok)
    {
        std::cout <<"Feed Forward: \n";
        for(int out =0; out < outputNeurons; out++)
        {
            std::cout <<list[nlCount-1].hidden[out] <<"\n";
        }
        return;
    }
    else
    {
       // printArray(list[3].getErrors(),list[3].getOutCount());
        backPropagate();
    }
}

template <class T>
void myNeuro<T>::backPropagate()
{
    //-------------------------------ERRORS-----CALC---------
    list[nlCount-1].calcOutError(targets);
    for (int i =nlCount-2; i>=0; i--)
        list[i].calcHidError(list[i+1].getErrors(),list[i+1].getMatrix(),
                list[i+1].getInCount(),list[i+1].getOutCount());

    //-------------------------------UPD-----WEIGHT---------
    for (int i =nlCount-1; i>0; i--)
        list[i].updMatrix(list[i-1].getHidden());
    list[0].updMatrix(inputs);
}

template <class T>
void myNeuro<T>::train(T *in, T *targ)
{
    inputs = in;
    targets = targ;
    feedForwarding(true);
}

template <class T>
void myNeuro<T>::query(T *in)
{
    inputs=in;
    feedForwarding(false);
}

template <class T>
void myNeuro<T>::printArray(T *arr, int s)
{
    std::cout <<"__\n";
    for(int inp =0; inp < s; inp++)
    {
        std::cout <<arr[inp] <<"\n";
    }
}



#endif // MYNEURO_H