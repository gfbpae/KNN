#include "KNN.h"
#include "PointGenerator.h"


KNN::KNN()
{
}

KNN::~KNN()
{
}

double KNN::getDistances(int j)const{return Distances[j].first;}
int KNN::getCategory(int j)const{return category[j];}

void KNN::calculateDistances(PointGenerator& PG,PointGenerator& Pt)
{
	double calculatedDistance=0.0;

	for(int j=0;j<Pt.getLastIndex();j++)
	{
		for(int i=0;i<PG.getLastIndex();i++)
		{
			///
			calculatedDistance=(sqrt(pow(PG.getPointX(i)-Pt.getPointX(j),2)+pow(PG.getPointY(i)-Pt.getPointY(j),2)));
			Distances.push_back(make_pair(calculatedDistance,make_pair(PG.getPointIndex(i),Pt.getPointIndex(j))));
		}
		
		/// Sort distances by 10 
		sort(Distances.begin()+j*PG.getLastIndex(),Distances.begin()+j*PG.getLastIndex()+PG.getLastIndex());
	}
	//print(PG,Pt); /// When this line executed, graph class gives an error. So it is kept close.

}
void KNN::DetermineCategory(PointGenerator& PG,PointGenerator& Pt,int n)
{
	for(int j=0;j<Pt.getLastIndex();j++)
	{
		int c1=0,c2=0,c3=0;
		int x;
		for(int i=j*PG.getLastIndex();i<j*PG.getLastIndex()+n;i++)
		{ 
			switch (PG.getPointID(Distances[i].second.first))
			{
				case 1:
					c1+=1;
					break;
				case 2:
					c2+=1;
					break;
				case 3:
					c3+=1;
					break;
			}
		}
		if(c1> max(c2,c3))category.push_back(1); 
		else if(c2>max(c1,c3))category.push_back(2);
		else category.push_back(3);
	}
}
void KNN::print(PointGenerator& PG,PointGenerator& Pt)
{
	for(int j=1;j<=Pt.getLastIndex();j++)
	{
		for(int i=(j-1)*PG.getLastIndex();i<(j)*PG.getLastIndex();i++)
		{
			cout<<" Distance : "<<getDistances(i)<<"\t  Category ID : "<<PG.getPointID(i/(j));
			cout<<"\t  P(x,y)=> "<<"( "<<PG.getPointX(i/(j))<<" , "<<PG.getPointY(i/(j))<<" )";
			cout<<"\t  K(x,y) => "<<"( "<<Pt.getPointX(j-1)<<" , "<<Pt.getPointY(j-1)<<" )"<<endl;
		}
	}
	getch();
}

