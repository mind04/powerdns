#include "misc.hh"
#include <utility>

typedef pair<string, uint16_t> typedns_t;

int main(int argc, char **argv)
{
	set<string, CIStringCompare> nsset;  
	nsset.insert("ns.example.com");
	nsset.insert("abc");
	nsset.insert("");
	for(set<string, CIStringCompare>::const_iterator i=nsset.begin();i!=nsset.end();++i) {
		cout<<"["<<*i<<"]"<<endl;
	}

	set<typedns_t, CIStringPairCompare> nsset2;  
	nsset2.insert(make_pair("ns.example.com", 1));
	nsset2.insert(make_pair("abc", 1));
	nsset2.insert(make_pair("", 1));
	nsset2.insert(make_pair("abc", 2));
	nsset2.insert(make_pair("ns.example.com", 0));
	for(set<typedns_t, CIStringPairCompare>::const_iterator i=nsset2.begin();i!=nsset2.end();++i) {
		cout<<"["<<i->first<<"]["<<i->second<<"]"<<endl;
	}
}