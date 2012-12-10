#include"lz77.h"
#include <math.h> 
#include<iostream>
#include<vector>
#include <sstream>
#define ASCII 8
coder::coder(int a, int b, std::string str, bool optim){
	slovar.resize(a);
	buffer.resize(b);	
	len=0;
	for(int i=0;i<slovar.size();++i){
		slovar[i]='^';
	}
	for(int i=0;i<buffer.size();++i){
		buffer[i]='^';
	}
	buffer=add_text(buffer,str.substr(0,buffer.size()));
	val_code(str,optim);
}

void coder::val_code(std::string str, bool optim){
 	std::string tmp;
	int j=buffer.size();
	while(buffer[0]!='^' ){
			int ind=slovar.find(buffer[0]);
			if(ind==-1){
				if(!optim){
					code+="<0,0,`";code+=buffer[0];code+="`> ";
					len+=ceil(log(slovar.size())/log(2))+ceil(log(buffer.size()+1)/log(2))+ASCII;
				}else{
				 code+="<0,`";code+=buffer[0];code+="`> ";
				 len+=ceil(log(buffer.size()+1)/log(2))+ASCII;
				}
				slovar=add_text(slovar,buffer.substr(0,1));
				if (j<str.size()){
					buffer=add_text(buffer,str.substr(j,1));
				}else{
					buffer=add_text(buffer,"^");}
				j++;
				}else{
					int length=0;
	        code+="<";code+=int_to_string(ind);code+=",";
						for(int s=0;s<buffer.size();++s){
							if(ind+s<slovar.size()){
								if (buffer[s]== slovar[ind+s])length++;
									else break;
								}else break;
						}
					if(buffer[length]=='^') length--;
					code+= int_to_string(length);code+=",`";code+=buffer[length];code+="`> ";
  	      slovar=add_text(slovar,buffer.substr(0,length+1));
 							tmp.clear();
							//Тут возможно ошибка
							if(j>(int)str.size()-1){
								
								for(int k=0;k<length+1;++k){
									tmp+="^";
									j+=length+1;
								}
								}else{
								if((length+1)>(int)str.size()-j){
									tmp=str.substr(j,(int)str.size()-j); 
										for(int k=0;k<length+1-(int)str.size()+j;++k){
											tmp+="^";
										}
									 j+=length+1;
								}else {
      	      		tmp=str.substr(j,length+1);
									 j+=length+1;
								}
						}
					 len+=ceil(log(slovar.size())/log(2))+ceil(log(buffer.size()+1)/log(2))+ASCII;	 
					buffer=add_text(buffer,tmp);
					}	
					if (buffer[1]=='^'&&buffer[0]!='^') {
						 code+="<0,0,`";code+=buffer[0];code+="`> ";
							break;
					}
					std::cout<<"\n sl:  "<<slovar;
					std::cout<<" bf:  "<<buffer;

}
	
}

std::string coder::get_code(){
	return code;
}

std::string add_text(std::string a, std::string b){
		a+=b;
		a.erase(0,b.size());
		
			
	return a;
}

int coder::get_len(){
	return len;
}

int string_to_int(std::string s){
	int n;
	std::istringstream ist(s);
  ist >> n;
	return n;
}
 
std::string int_to_string(int a){
	std::string tmp;
	if(a==0) tmp="0";
	if (a<10&&a>0) tmp=(a+'0');
	if (a>10 &&a<100){ 
		std::string tmp1;
		tmp1=a/10+'0';
		int tmp2=a-(a/10)*10;
		tmp=tmp2+'0';
		tmp=tmp1+tmp;
}	
return tmp;

}

decoder::decoder(int a, int b, std::string code){
  slovar.resize(a);
    for(int i=0;i<slovar.size();++i){
    slovar[i]='^';
  }

  sub_code(code);
}

void decoder::sub_code(std::string code){
	while(code.find('<')!=-1){
		int start=code.find('<');
		int stop=code.find('>');
			std::string sub_code;
			sub_code=code.substr(start+1,stop-1-start);
			parse(sub_code);
			code.erase(start,stop-start+1);
	}
}

void decoder::parse(std::string sub_code){
std::vector<int> val;
std::string s;
  	while(sub_code.find(',')!=-1){
			int stop=sub_code.find(',');
			int start=0;
			int a= string_to_int(sub_code.substr(start,stop)) ;
			val.push_back(a);
			sub_code.erase(start,stop+1);
  }

	if(sub_code.find('`')!=-1){
		s=sub_code.substr(sub_code.find('`')+1,1);
	}
	if(val[0]==0 || val[1]==0){
     str+=s;
     slovar=add_text(slovar,s);
			}else{
		str+=slovar.substr(val[0],val[1]);
		slovar=add_text(slovar,slovar.substr(val[0],val[1]));
		str+=s;
		slovar=add_text(slovar,s);
	}
}

 std::string decoder::get_str(){
	return str;
}

