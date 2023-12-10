#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> performEquiFreq(vector<int>data,int bins)
{
    int n=data.size();
    int f=n/bins;
    vector<vector<int>>res;
    for(int i=0;i<bins;i++){
        vector<int>bin;
        for(int j=i*f;j<(i+1)*f;j++)
        {
            if(j>=n)
            {
                break;
            }
            bin.push_back(data[j]);
        }
        res.push_back(bin);
    }
    return res;
}
vector<int>readCSV(string fileName){
    ifstream input(fileName);
    vector<int>data;

    string line,value;

    while(getline(input,line))
    {
        stringstream ss(line);
        while(getline(ss,value,','))
        {
            data.push_back(stoi(value));
        }
    }


    input.close();
    return data;

}  
void writeCSV(string fileName,vector<vector<int>>&res1)
{
   ofstream output(fileName);

   for(int i=0;i<res1.size();i++)
   {
    output<<"Bin"<<i+1<<":";
     for(int j=0;j<res1[i].size();j++)
     {
        output<<res1[i][j]<<",";
     }
     output<<endl;
   }

   output.close();

   
}
int main(){
     vector<int>input=readCSV("input.csv");
     int bins;
     cout<<"Enter Number of bins"<<endl;
     cin>>bins;

     int option ;
     cin>>option;

     cout<<"Enter 1 for Binning with Equifreq and 2 for Equi-width"<<endl;

     cin>>option;
     
      if(option==1){
              if(!input.size()){
                cout<<"Error file opening ";
                exit(0);
              }
              vector<vector<int>>res1=performEquiFreq(input,bins);
              writeCSV("output_equifreq.csv",res1);
     }
     else 
         return 0;

     
}