#include "PointGenerator.h"


PointGenerator::PointGenerator(){last_index=0;}

PointGenerator::~PointGenerator(){}

/// Get functions to get requested information about desired points
double  PointGenerator::getPointX    (int n)const{return (SamplePoints[n].second.first);}
double  PointGenerator::getPointY    (int n)const{return (SamplePoints[n].second.second);}
int     PointGenerator::getPointID   (int n)const{return SamplePoints[n].first.second;}
int     PointGenerator::getPointIndex(int n)const{return SamplePoints[n].first.first;}
int     PointGenerator::getLastIndex (void) const{return last_index;}
void 	PointGenerator::setLastIndex (int n)	 {last_index+=n;}

/// With bool x, it is determined whether it will be knn data or sample data.
void PointGenerator::SampleGenerator(int a,int n,bool x)
{
	int category_id=0;
	srand(time(NULL));
		for (int i = a; i < a+n; ++i) 
		{
			double randX =(-(rand()%9)+4)+(rand()%100)*0.01;
			double randY =(-(rand()%9)+4)+(rand()%100)*0.01;
			
			if(x==true)
			{
				if((i+n)%10==0 && category_id<=3) category_id++; ///
				if(category_id>3) category_id=1;
			}
			else category_id=0;
			
			SamplePoints.push_back(make_pair(make_pair(i,category_id),make_pair(randX,randY)));
		}
	
	setLastIndex(n);
}
/// Adds from the last point of the data. Last index is used to do this
void PointGenerator::addSamplePoints(int n,bool x){SampleGenerator(getLastIndex(),n,x);}

ostream &operator<<(ostream &output,const PointGenerator& a)
{
    for(int i=0;i<a.getLastIndex();i++)
	{
        output<<"Point Index : "<<a.getPointIndex(i)<<"  Point ID : "<<a.getPointID(i)<<"  P( "<<a.getPointX(i)<<" , "<<a.getPointY(i)<<" )"<< endl;
    }
    return output;
}
