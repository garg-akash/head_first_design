#include <iostream>
#include <set>
#include <memory>


using namespace std;

class Internet
{
public:
	Internet(){}
	~Internet(){}
	virtual void connectTo(string) = 0;
};

class RealInternet : public Internet
{
public:
	RealInternet(){}
	~RealInternet(){}
	void connectTo(string site)
	{
		cout << "Connecting to " << site << "\n";
	}
};

class ProxyInternet : public Internet
{
	unique_ptr<Internet> ri_;
	set<string> banned;
public:
	ProxyInternet(unique_ptr<Internet> ri) : ri_(std::move(ri))
	{
		banned.insert("abc.com");
		banned.insert("xyz.com");
		banned.insert("pqr.com");
		banned.insert("mno.com");
	}
	~ProxyInternet(){}
	void connectTo(string site)
	{
		if(banned.find(site) != banned.end())
			throw "this site is banned";
		ri_->connectTo(site); 
	}

};

int main(int argc, char const *argv[])
{
	unique_ptr<Internet> riptr(new RealInternet());

	unique_ptr<Internet> pi = make_unique<ProxyInternet>(std::move(riptr));

	try
	{
		string site = "google.com";
		pi->connectTo(site);
		site = "xyz.com";
		pi->connectTo(site);		
	}
	catch(const char* e)
	{
		cout << e << "\n";
	}

	return 0;
}