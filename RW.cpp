#include "RW.h"

RW::RW()
{
}

RW::~RW()
{
}

void RW::fileWriting(PointGenerator& P)
{
	ofstream f;
	if(f.is_open()==false){f.open("example.txt",std::ios::app);}
	if(P.getPointID(0)==0)
	{
		f<<"KNN Points : "<<endl;
		f<< P;
	}
	else
	{
		f<<"Sample Points : "<<endl;
		f<< P;
	}
	f.close();
}
void RW::fileReading()
{
	string out;
	ifstream f;
	if(f.is_open()==false){f.open("example.txt");}
	
	while(!f.eof())
	{
		getline(f,out);
		cout<<out<<"\n";
	}

}

