#ifndef LZ77_H
#define LZ77_H
#include<string>
class coder{
	std::string slovar;
	std::string buffer;
	std::string code;
	int len;
	void val_code(std::string str,bool optim);
public:
	coder(int a, int b, std::string str, bool optim);
	std::string get_code();
	int get_len();
};

class decoder{
  std::string slovar;
  std::string str;
	void sub_code(std::string code);
	void parse(std::string sub_code);
public:
  decoder(int a, int b, std::string code);
  std::string get_str();
};

std::string add_text(std::string a, std::string b);
std::string int_to_string(int a);

#endif
