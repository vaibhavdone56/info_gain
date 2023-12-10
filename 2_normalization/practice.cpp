#include<bits/stdc++.h>
using namespace std;
void calculateMinMax(ifstream &input1,double &minValue,double &maxValue)
{
    double currentValue;
    input1>>currentValue;

    while(input1){
        if(currentValue<minValue)
        {
            minValue=currentValue;
        }
        if(currentValue>maxValue)
        {
            maxValue=currentValue;
        }
        input1>>currentValue;
    }
}

void performMinMaxNormalization(ifstream &input1,ofstream &output1,double minValue,double maxValue,double newMin,double newMax)
{
    cout<<"hii i am in perform";
    double currentValue;
    input1>>currentValue;
    output1<<"Data,"<<"Normalised Data"<<endl;
    while(input1)
    {
        double normalised=((currentValue-minValue)/(maxValue-minValue))*(newMax-newMin)+newMin;
        output1<<currentValue<<","<<normalised<<endl;
        cout<<normalised<<endl;
        input1>>currentValue;
    }

    return ;
}
int main()
{
    double minValue,maxValue,newMin,newMax;
    
    minValue=INT_MAX;
    maxValue=INT_MIN;
    ifstream input1("input_MinMax.csv");
    ifstream input2("input_MinMax.csv");
    ofstream output1("output_MinMax.csv",ios::app);
    cout<<"Enter 1 for Min_max Normalisation"<<endl;
    int option;
    cin>>option;

    switch(option)
    {
        case 1: 
                if(!input1)
                {
                    cout<<"Error in opening a file";
                    exit(0);
                }
                calculateMinMax(input1,minValue,maxValue);
                cout << "Enter new minimum value: ";
                cin >> newMin;
                cout << "\nEnter new maximum value: ";
                cin >> newMax;
                performMinMaxNormalization(input2,output1,minValue, maxValue, newMin, newMax);
                break;
        default: break;
    }

    cout<<endl<<"hello world";

}