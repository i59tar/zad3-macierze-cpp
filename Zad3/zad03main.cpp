#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string string_replace( string src, string const& target, string const& repl);

int main(int argc, char *argv[]){
	fstream file;
	file.open(argv[1]);
	if (!file.is_open()){
		cout<<"Blad przy otwieraniu pliku."<<endl;
		return 1;
	}
	string content ((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	string alter=string_replace(content,argv[2],argv[3]);
	cout<<argv[2]<<endl<<argv[3]<<endl;
	cout<<alter<<endl;
	string affix="_nowy.txt";
	int i;
	for(i=0;argv[1][i];i++);
	i+=6;
	char *newname=new char[i];
	for(int j=0;j<i;j++){
		if(j<i-10) newname[j]=argv[1][j];
		else newname[j]=affix[j-(i-10)];
	}
	file.close();	
	file.open(newname,std::fstream::out | std::fstream::trunc);
	cout<<newname;
	file<<alter;
	file.close();
	return 0;
}

string string_replace( string src, string const& target, string const& repl)
{
    if (target.length() == 0) {
        
        return src;
    }

    if (src.length() == 0) {
        return src;
    }

    size_t idx = 0;

    for (;;) {
        idx = src.find( target, idx);
        if (idx == string::npos)  break;

        src.replace( idx, target.length(), repl);
        idx += repl.length();
    }

    return src;
}
