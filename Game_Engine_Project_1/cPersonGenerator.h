#ifndef _cPersonGenerator_HG_
#define _cPersonGenerator_HG_

#include <string>
#include "cPerson.h"
#include "cFNLinkList.h"
#include "cSNLinkList.h"
#include "cSTLinkList.h"
#include "cDynamicArray.h"

class cPersonGenerator
{

public:
	cPersonGenerator();
	~cPersonGenerator();
	dynamicArray <std::string> songs;

	// This takes three files:
	// - One of the "Popular Baby Names" found here: https://www.ssa.gov/oact/babynames/limits.html
	//   (example: "yob2001.txt" which are babies born in the year 2001
	// - The "Names_2010Census.csv" file, from:
	//   "Frequently Occurring Surnames from the 2010 Census" from here:
	//   https://www.census.gov/topics/population/genealogy/data/2010_surnames.html
	// - The "Street_Names.csv" file, from:
	//   "Street Names (San Francisco)" from here: 
	//   https://catalog.data.gov/dataset/street-names-37fec/resource/d655cc82-c98f-450a-b9bb-63521c870503
	// Returns:
	// - true if successful
	// - false if there's any issue (can't find file, or whatever)
	//   If false, then the "errorString" (passed by reference) should be loaded with some sort of 
	//   description of what went wrong (file didn't open, parse issue, Skynet became self aware, etc.)
	//   Use your discretion (and creativity) for this. 
	bool LoadCensusFiles(
		std::string babyNameFile,
		std::string surnameFile,
		std::string streetNameFile,
		std::string& errorString);

	unsigned int getNumberOfNamesLoaded(void);
	unsigned int getNumberOfSurnamesLoaded(void);
	unsigned int getNumberOfStreetsLoaded(void);

	bool readCSVFile(void);
	bool LoadSongsFromCSV(std::string fileName, cPerson* user);

	int RandGen(int min, int max);

	// Randomly generates a person from the data
	// Returns 0, NULL, or nullptr if it can't do this. 
	cPerson* generateRandomPerson(int fnTokenCount, int snTokenCount, int stTokenCount, FNNode* fnCurrent, SNNode* snCurrent, STNode* stCurrent);

	/*const char** arrFirstName;
	const char** arrLastName;
	const char** arrStreetName;*/

	/*dynamicArray<std::string> arrFirstName;
	dynamicArray<std::string> arrLastName;
	dynamicArray<std::string> arrStreetName;*/

	unsigned int fnameNodeCount = 0;
	unsigned int snameNodeCount = 0;
	unsigned int stNodeCount = 0;
};
#endif 
