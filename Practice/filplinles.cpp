#include<iostream>
#include<fstream>
using namespace std;
bool flip_lines(string in_file7, string out_file8)
{
    ifstream fin;
    fin.open(in_file7.c_str());
    if(!fin)
    {
        return EXIT_FAILURE;
        fin.close();
    }
    ofstream fout;
    fout.open(out_file8.c_str());
    if(!fout)
    {
        return EXIT_FAILURE;
        fout.close();
    }

    string temp1, temp2;

while(getline(fin, temp1))
{
     //Handle even number of lines
     if(getline(fin, temp2))
     {
         for(int i=0;temp2[i]!='\0';i++ ){
            if(temp2[i]>='a' && temp2[i]<='z'){
                temp2[i]=temp2[i]-32;
            }

         }
          fout << temp2 << endl;
          fout << temp1 << endl;
     }
     //Handle odd number of lines
     else
     {
          fout << temp1;
     }
}
    return true;
}

int main()
{
    string in_file7 = "file7.txt";
    string out_file8 = "file8.txt";
    bool result = flip_lines(in_file7,out_file8);

    cout << "\nresult EXPECTED true; ACTUALLY it was " << result <<endl;
    cout << "\nEXPECTED file contents are: " << endl;

   cout << "did gyre and gimble in the wabe.\nTwas brillig and the slithy toves\n"
        << "and the mome raths outgrabe.\nAll mimsey were the borogroves,\n"
        << "\"Beware the Jabberwock, my son,\n\nBeware the JubJub bird and shun\n"
        << "the jaws that bite, the claws that catch,\nthe frumious bandersnatch.\"\n";
    cout << "\nACTUAL file contents are:" <<endl;

    system("cmd /c type file8.txt");

    return 0;
}
