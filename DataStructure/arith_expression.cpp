#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

template <class T>
class stack{
private:
	T* _base;
	T* _top;
	int size;
	int len;
public:
	stack(){
		_base = (T*)malloc(1025 * sizeof(T));
		if(!_base) exit(-1);
		len = 1024;
		_top = _base;
		size = 0;
	}

	bool empty(){
		return size == 0;
	}

	T top(){
		if(!size) return 0;
		return *(_top - 1);
	}

	T pop(){
		if(!size) return 0;
		_top--;
		size--;
		return *_top;
	}

	void push(T elem){
		if(size == len){
			len *= 2;
			T *p = (T*)realloc(_base, sizeof(T) * len);
			if(!p) exit(-1);
			free(_base);
			_base = p;
			_top = _base + size;
		}
		*_top = elem;
		_top++;
		size++;
	}

};
stack <char> OPTR;
stack <int> OPND;
bool is_digit(char ch){
	if(ch <= '9' && ch >= '0') return true;
	else return false;
}
int convert_ch(char ch){
	switch (ch)
	{
	case '#': return 0;
	case '(': return 1;
	case ')': return 2;
	case '+':
	case '-': return 3;
	case '*':
	case '/': return 4;
	default: exit(-2);
	}
}
int cmp_prior(char ch1, char ch2){
	int a = convert_ch(ch1);
	int b = convert_ch(ch2);

	if(a == 0 && b == 0 || a == 1 && b == 2) return 0;
	else if(a < b || b == 1) return 1;
	else return -1;
}
int calculate(int a, int b, char op){
	switch (op)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	default:  exit(-2);
	}
}
int main(){
	ifstream fin;
	ofstream fout;
	string name;
	cin >> name;
	fin.open("./input/" + name);
	string express;
	fin >> express;
	// express += '$';
	bool continuous_num = false;
	OPTR.push('#');
	int i = 1;
	char ch = express[1];
	while (!OPTR.empty())
	{
		if(is_digit(ch)){							// if the char is a number
			if(continuous_num){						// if the number is continuous
				int temp = OPND.pop();
				temp = temp * 10 + ch - '0';
				OPND.push(temp);
			}
			else{									// if the number is not continuous
				OPND.push(ch - '0');
			}
			ch = express[++i];
			continuous_num = true;					// set the continuous_num
		}
		else{										// if the number is a op
			continuous_num = false;					// reset the continuous_num
			int res = cmp_prior(OPTR.top(), ch); 	// compare the prior
			if(res == 1){ 							// if top smaller than input
				OPTR.push(ch);
				ch = express[++i];
			}
			else if(res == 0){						// if it is $$ or (), equal
				OPTR.pop();
				ch = express[++i];
			}
			else{									// if the top is bigger than input
				int b = OPND.pop();
				int a = OPND.pop();
				char op = OPTR.pop();
				OPND.push(calculate(a, b, op));
			}
		}
	}
	fout.open("output.txt");
	fout << OPND.top() << endl;
	fin.close();
	fout.close();
	return 0;
}