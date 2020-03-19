#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class palindrom{
       ifstream plik1;
       ofstream plik2;

  public:
        palindrom();
        ~palindrom();
       
        void isPalindrome();        
};

palindrom::palindrom(){
    plik1.open("c:\\od.txt");
    plik2.open("c:\\do.txt");
}

void palindrom::isPalindrome(){
	string line, word, join("");
	
	plik2<<"[\n";
	while(!plik1.eof()){
		getline(plik1, line);
		stringstream ss(line);
	    while(ss >> word){
	    	join += word;
		}
		
		for(int i = 0; i<join.length(); i++){
			if(join[i] >= 'a' && join[i] <= 'z'){
				join[i] -= 32;
			} else {
				join[i] -= 0;
			}
		}
	
		int back = join.length()-1;
		bool palindrome = true;
		for (int i=0; i<join.length()/2 && palindrome; i++){
			if (join[i] != join[back--]){
				palindrome = false;
			}     
		}
		
			
		
		string isTrue;
		if(palindrome){
			isTrue = "TAK";
		}else {
			isTrue = "NIE";
		}
		plik2<<"{\"string\":"<<join<<", \"palindrom\":\""<<isTrue<<"}\n";
		line = "";
		word = "";
		join = "";
	}
	plik2<<"]";
                
                
}

palindrom::~palindrom(){
    plik1.close();
    plik2.close();
}

int main() {
    palindrom p1;
    p1.isPalindrome();
    return 0;
}
