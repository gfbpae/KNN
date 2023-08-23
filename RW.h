#ifndef RW_H
#define RW_H
#include <fstream>
#include <string>
#include <iostream>
#include "PointGenerator.h"

using namespace std;
/** RW Class => Used for writing to and reading from a file. */
class RW
{
	public:
		/** Empty Constructor*/
		RW();
		/** Destructor*/
		~RW();
		/** It receives the SampleGenerator object and prints this to the file. */
		void fileWriting(PointGenerator&);
		/** It is used to read from a file. */
		void fileReading();
		

	protected:
};

#endif
