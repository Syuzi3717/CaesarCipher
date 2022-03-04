#include <string>
#include "caesarcipher.h"

File::File(): shifting(3){ 
    fin.open("file.txt");
    ret.open("decode.txt");
    if(fin.is_open())
    {
        std::cout << "The file is opened" << std::endl;
    }
    else
    {
        std::cout << "Error" << std::endl;
    }
}
File::~File()
{
    fin.close();
    ret.close();
}


void File::decode()
{
    std::string res = "";
    while(!(fin.eof()))
    {
         std::string line;
        getline(fin, line);
        for(int i=0; i<line.size(); ++i)
        {
           if(line[i] >= 'a' && line[i] <= 'z')
            {
               if(line[i]+shifting>'z') line[i]-=26;
               res+=char(line[i]+shifting);
            }
            else if(line[i] >= 'A' && line[i] <= 'Z')
            {
                if(line[i]+shifting>'Z') line[i]-=26;
                res+=char(line[i]+shifting);
            } 
            else res+=char(line[i]);
        }
        ret << res<<std::endl;
        res="";
    }
}

void File::code()
{
    std::string res = "";
    while(!fin.eof())
    {
        std::string line;
        getline(fin, line);
        for(int i=0; i<line.size(); ++i)
        {
           if(line[i] >= 'a' && line[i] <= 'z')
            {
               if(line[i]-'a'<shifting) line[i]+=26;
               res+=char(line[i]-shifting);
            }
            else if(line[i] >= 'A' && line[i] <= 'Z')
            {
                if(line[i]-'A'<shifting) line[i]+=26;
                res+=char(line[i]-shifting);
            } 
            else res+=char(line[i]);
        }
        ret << res << std::endl;
        res="";
    }
}

int main()
{
    File obj;
    obj.code();
}
