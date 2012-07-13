#include "resolver.hh"
#include "statbag.hh"
#include "arguments.hh"

StatBag S;

ArgvMap& arg()
{
  static ArgvMap theArg;
  return theArg;
}

/* usage: generate a server->client flow dump using a tool like tcpflow.
   Then: flow2zone < 192.168.001.001.00053-192.168.001.002.12345
   Output will be a list of records (akin to a zonefile) terminated by
   a TCP exception (this means end of file).
   For most AXFR pcaps, you will get 3 SOAs total. This is normal.
 */
int main(int argc, char **argv)
try
{
	AXFRRetriever r(0);
    Resolver::res_t recs;
    reportAllTypes();

    while(r.getChunk(recs, true)) {
		for(Resolver::res_t::iterator i=recs.begin();i!=recs.end();++i) {
			cout<<(i->qname)<<".\t";
			cout<<(i->ttl)<<"\t";
			cout<<"IN"<<"\t";
			cout<<(i->qtype.getName())<<"\t";
			cout<<(i->content)<<endl;
		}
	}
}
catch (std::exception &e)
{
	cerr<<"Fatal: "<<e.what()<<endl;
}
catch (ResolverException &e)
{
	cerr<<"Fatal: "<<e.reason<<endl;
}