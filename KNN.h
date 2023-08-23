#ifndef KNN_H
#define KNN_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <cmath>
#include <algorithm>
#include "PointGenerator.h"

using namespace std;
/** KNN Class => Distances are calculated and stored and indexes are stored at this class*/
class KNN 
{
	public:
		/** Empty Constructor */
		KNN();
		/** Destructor*/
		~KNN();
		/** Used to print points and their distances. First input takes sample points and second input takes KNN points*/
		void 	print				(PointGenerator& ,PointGenerator& );
		/** Used to calculate points and their distances. First input takes sample points and second input takes KNN points*/
		void 	calculateDistances	(PointGenerator&,PointGenerator&);
		/** Used to calculate points and their distances. First input takes sample points and second input takes KNN points.
		Also it gets the desired number of nearest neighbors */
		void 	DetermineCategory	(PointGenerator&,PointGenerator&,int);
		/** Used to obtain the desired distances. It takes the input as an index, and returns the distance value at this index.*/
		double 	getDistances		(int)const;
		/** Used to obtain the desired Category ID of distance. It takes the input as an index, and returns the distance value at this index. */
		int 	getCategory			(int)const;
	private:
		/** After the distances are calculated and the sort operation is applied, the decided Category IDs are kept in this vector.*/
		vector<int>category;
		/** Calculated distances are stored. It stores indices which belongs to sample data and knn data.
		Stores indices as :
		second.first => sample points indices
		second.second => knn points indices*/
		vector<pair<double,pair<int,int> > > Distances;
};

#endif

