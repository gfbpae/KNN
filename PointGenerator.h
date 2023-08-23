#ifndef POINTGENERATOR_H
#define POINTGENERATOR_H
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;
/** Point Generator Class => Used to create points */
class PointGenerator
{
	/** It is used to directly print SamplePoints by overloading the "<<" operation. It prevents rewrites. */
	friend ostream &operator<<(ostream& ,const PointGenerator& );
	public:
		/** Empty Constructor */
		PointGenerator();
		/** Destructor */
		~PointGenerator();
		/** Creates points => first input(int) for beginning index, second input (int) for number of points, 
		third input (bool) to specify being knn or sample points (true for sample points, false for knn points)*/
		void 		SampleGenerator	(int,int,bool);
		/** To set last_index with integer */
		void  		setLastIndex	(int);
		/** Returns last_index */
		int  		getLastIndex	()const;
		/** Take an integer as index and returns point's x at that index */
		double 		getPointX		(int)const;
		/** Take an integer as index and returns point's y at that index */
		double 		getPointY		(int)const;
		/** Take an integer as index and returns point's Category ID at that index */
		int 		getPointID		(int)const;
		/** Take an integer as index and returns point's Index at that index (for using after sorting operation) */
		int 		getPointIndex	(int)const;
		/** Adds new points to the data of the invoked object => first input (int)  */
		void 		addSamplePoints(int,bool);		
		
	private:
		/** Points are kept in this vector. The points are kept in this vector. 
		In first pair, 2 pairs of information about the point are matched.
		Stores data as :
		first.first => Point index
		first.second => Point Category ID 
		second.first => Point's x value
		second.second => Point's y value*/
		vector<pair<pair<int,int>,pair<double,double> > > SamplePoints;
		/** Used to append new points to old points */
		int last_index;
};

#endif

