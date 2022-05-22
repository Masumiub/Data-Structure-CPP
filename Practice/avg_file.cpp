#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void findAvgPrice(string outputFile, string inputFile)
{
        ifstream infile;
        infile.open(inputFile);
        if(!infile){
            cout<<"File not found!"<< endl;
        }
        ofstream outfile;
        outfile.open(outputFile);
        if(!outfile){
            cout<<"File not found!"<< endl;
        }
        outfile << "NAME AVG PRICE" << endl;
        string line;
        getline(infile, line);
        while(getline(infile, line))
        {
                istringstream iss(line);
                string s;
                float num;
                float sum=0;
                float avgprice;
                iss >> s;
                for(int i=0; i<7; i++)
                {
                        iss >> num;
                        sum = sum+num;
                }
                avgprice = sum/7;
                outfile<<s<<" "<<fixed<<setprecision(2)<<avgprice<<endl;
        }

}

int main()
{

        findAvgPrice("avgstockprice.txt", "stockprice.txt");
        return 0;
}

/*
infile.close();
        outfile.close();*/
