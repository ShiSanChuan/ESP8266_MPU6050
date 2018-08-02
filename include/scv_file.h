#ifndef _SCV_FILE_H
#define _SCV_FILE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
template <typename _InputIter>
class sFILE
{
private:
	_InputIter * data;
	_InputIter * Max;
	_InputIter * Min;
	int Col_Size;
	int Row_size;
	std::ifstream fin;
public:
	sFILE(const std::string path);
	~sFILE(){delete []data;delete []Max;delete []Min;}
	int GetColSize(void)const{return Col_Size;}
	int GetRowSize(void)const{return Row_size;}
	_InputIter * operator[](int i)const{return &data[i*Col_Size];}
	// friend std::vector<_InputIter> 
	// _InputIter operator+()const;
};
using std::string;
template <typename _InputIter>
sFILE<_InputIter>::sFILE(const string path){
	fin.open(path);
	if(!fin){std::cout<<"Fail To Open File!"<<std::endl;exit(1);}
	Col_Size=Row_size=0;
	string line;
	std::streampos pos=fin.tellg();
	// std::cout<<fin.tellg()<<std::endl;
	while(getline(fin,line)){//get data size
		if(Row_size==0){
			std::istringstream sin(line);
			string field;
			while(getline(sin,field,','))Col_Size++;
		}
		Row_size++;
	}
	// std::cout<<fin.tellg()<<std::endl;//why the file point is -1	?????? 20180731
	// fin.seekg(pos);//move file point to head
	fin.close();
	fin.open(path);
	data=new _InputIter [Col_Size*Row_size];//alloat data size
	Max=new _InputIter [Col_Size];
	Min=new _InputIter [Col_Size];
	int i=0;
	while(getline(fin,line)){//get data input array
		std::istringstream sin(line);
		string field;
		while(getline(sin,field,',')){
			field.erase(0,field.find_first_not_of(" \t\r\n"));
			field.erase(field.find_last_not_of(" \t\r\n")+1);
			std::istringstream iss(field);
			iss>>data[i++];
		}
	}
	fin.close();
}


#endif