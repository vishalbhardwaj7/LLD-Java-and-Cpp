#include<bits/stdc++.h>
using namespace std;

// make a file system to print directory names/ file name
class FileSystem{
public:
    virtual void ls(){}
};

class File:public FileSystem{
    string fileName;
public:
    File(string name){
        fileName=name;
    }
    void ls(){
        cout<<"File Name: "<<fileName<<" ";
    }
};
class Directory:public FileSystem{
    string dirName;
    vector<FileSystem*> objs;
public:
    Directory(string name){
        dirName=name;
    }
    void add(FileSystem* obj){
        objs.push_back(obj);
    }
    void ls(){
        cout<<endl<<"Directory Name: "<<dirName<<" ";
        for(auto obj:objs){
            obj->ls();
        }
    }
};

int main(){
    Directory * movieDir = new Directory("Movies");
    File * gadar = new File("Gadar 2");
    movieDir->add(gadar);
    Directory * comedyDir = new Directory("Comedy Movies");
    File * hulchul = new File ("Hulchul");
    comedyDir->add(hulchul);
    movieDir->add(comedyDir);

    movieDir->ls();
}