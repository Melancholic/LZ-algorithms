#include"lz77.h"
#include<iostream>
int main(){
	coder a(12,4,"KOT_KOLOTIT_PLOT",1);
	std::cout<<"\n"<<a.get_code()<<" ";
	std::cout<<"\nLength= "<<a.get_len()<<"\n";
	return 0;
}
