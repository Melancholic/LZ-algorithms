#include"lz77.h"
#include<iostream>
int main(){
	std::string str;
	std::cout<<"\nInput string: ";
	std::cin>>str;
	int a, b;
	std::cout<<"\nInput length dictionary and buffer: ";
  std::cin>> a>>b;
	std::cout<<"\nOptimal ? (yes/no)  ";
	std::string menu;
	std::cin>>menu;
	bool opt;
		if(menu=="yes" || menu=="y") opt=true;else{
				if(menu== "no"||menu=="n") opt=false;else{
						std::cout<<"exit...";
						}
				} 
	coder Coding(a,b,str,opt);
	std::cout<<"\n"<<Coding.get_code()<<" ";
	std::cout<<"\nLength= "<<Coding.get_len()<<"\n";
	std::cout<<"\nChecking decoding: ";
	decoder Decoding(a,b,Coding.get_code());
  if(Decoding.get_str()==str) std::cout<<" TRUE"; 
		else std::cout<<" FALSE";
	std::cout<<"\ndecoding Str: "<<Decoding.get_str()<<"\n";
	return 0;
}
