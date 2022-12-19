#include "cSnotify.h"
#include "cPersonGenerator.h"

int main(int argc, char** argv) {

	std::string babyNameFile = "./data/yob2000.txt";
	std::string surnameFile = "./data/Names_2010Census.csv";
	std::string streetNameFile = "./data/Street_Names.csv";
	std::string audioNameFile = "./data/audiio.csv";
	std::string error;
	
	char temp = 'n';
	while (temp != '!') {
		
		cPersonGenerator dude;
		if (!dude.LoadCensusFiles(babyNameFile, surnameFile, streetNameFile, error)) {
			return 1;
		}
		std::cin >> temp;
	}
	


	/*if (dude.LoadSongsFromCSV("./data/audiio.csv")) {
		std::cout << "audio method called" << std::endl;
		return 1;
	}*/

	/*cSnotify snot;
	if (snot.LoadSongsFromCSV("./data/audiio.csv")) {
		return 1;
	}*/

	//dude.readCSVFile();

	return 0;
}