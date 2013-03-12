#include "misc.hh"

int main(int argc, char **argv)
{
	set<string, CIStringCompare> nsset;  
	nsset.insert("ns.example.com");
	nsset.insert("abc");
	nsset.insert("");
	for(set<string, CIStringCompare>::const_iterator i=nsset.begin();i!=nsset.end();++i) {
		cout<<"["<<*i<<"]"<<endl;
	}
}