#include "cPersonGenerator.h"
#include "cSong.h"
#include "cSnotify.h"

#define _CRT_SECURE_NO_WARNINGS

// Warning C26812 : Prefer 'enum class' over 'enum' (Enum.3)
#pragma warning( disable : 26812 )

#include <iostream>
#include <fstream>
#include <sstream>		// String Stream
#include <string>
#include <stdlib.h>

cPersonGenerator::cPersonGenerator() {

}

cPersonGenerator::~cPersonGenerator() {

}

FNNode* fnHead = new FNNode();
SNNode* snHead = new SNNode();
STNode* stHead = new STNode();
cSong* sngHead = new cSong();

bool cPersonGenerator::LoadCensusFiles(
	std::string babyNameFile,
	std::string surnameFile,
	std::string streetNameFile,
	std::string& errorString)
{
	errorString = "Could not load file";
	
	/*int capacity = 1;
	int current = 0;
	arrFirstName = new const char* [capacity];*/
	//arrFirstName = (const char**)calloc(arrSize, sizeof(char*));
	//arrFirstName = (const char**)malloc(arrSize * sizeof(const char*));

	/**********************************************************************
									FIRST NAMES
	***********************************************************************/
	std::ifstream ifBabyName(babyNameFile);
	if (!ifBabyName.is_open()) {
		std::cout << errorString << std::endl;
		return false;
	}

	std::string theFNLine;
	unsigned int fnLineCount = 0;

	//ifBabyName >> theFNLine;
	std::getline(ifBabyName, theFNLine);
	
	
	fnLineCount++;
	std::stringstream ssLine(theFNLine);

	std::string token;
	unsigned int fnTokenCount = 0;
	char* next_element;
	char* fnElement = strtok_s((char*)token.c_str(), ",", &next_element);
	std::getline(ssLine, token);
	while (std::getline(ssLine, token))
	{
		//arrFirstName[lineCount] = token.c_str();
		fnElement = strtok_s((char*)token.c_str(), ",", &next_element);
		fnHead->fname = fnElement;
		fnElement = strtok_s(NULL, ",",&next_element);
		fnHead->gender = *fnElement;
		fnElement = strtok_s(NULL, ",", &next_element);
		fnHead->popularity = (int) *fnElement;
		fnElement = strtok_s(NULL, ",", &next_element);
		fnHead->next = NULL;
		fnameNodeCount++;
		// Ignore the other parts of the line
		fnTokenCount++;
	}
	FNNode* fnCurrent = fnHead;
	while (ifBabyName >> theFNLine)
	{
		fnLineCount++;
		std::stringstream ssLine(theFNLine);

		//std::string token;
		//unsigned int tokenCount = 0;
		//std::cout << "entered parent" << std::endl;
		while (std::getline(ssLine, token))
		{
			//arrFirstName[lineCount] = token.c_str();
			//arrFirstName.push(token);
			FNNode* newNode = new FNNode();
			fnElement = strtok_s((char*)token.c_str(), ",", &next_element);
			newNode->fname = fnElement;
			fnElement = strtok_s(NULL, ",", &next_element);
			newNode->gender = *fnElement;
			fnElement = strtok_s(NULL, ",", &next_element);
			newNode->popularity = (int)*fnElement;
			newNode->next = NULL;
			fnCurrent->next = newNode;
			fnElement = strtok_s(NULL, ",", &next_element);
				
			fnCurrent = fnCurrent->next;
			fnameNodeCount++;
				

			
			// Ignore the other parts of the line
			fnTokenCount++;
		}
	}

	/*for (int i = 0; i < arrFirstName.size(); i++) {
		std::cout << arrFirstName.get(i) << std::endl;
	}*/
	fnCurrent = fnHead;
	/*while (fnCurrent != NULL) {
		std::cout << fnCurrent->fname << " " << fnCurrent->gender << " " << fnCurrent->popularity << std::endl;
		fnCurrent = fnCurrent->next;
	}*/
	std::cout << "First Name Lines read = " << fnLineCount << std::endl;
	ifBabyName.close();


	/**********************************************************************
									SECOND NAMES
	***********************************************************************/

	std::ifstream ifSecondName(surnameFile);
	if (!ifSecondName.is_open()) {
		std::cout << errorString << std::endl;
		return false;
	}

	std::string theSNLine;
	unsigned int snLineCount = 0;

	ifSecondName >> theSNLine;
	//SNNode* snHead = new SNNode();

	snLineCount++;
	std::stringstream snSSLine(theSNLine);

	unsigned int snTokenCount = 0;
	std::getline(snSSLine, token);
	char* snElement = strtok_s((char*)token.c_str(), ",", &next_element);
	while (std::getline(snSSLine, token))
	{
		//arrFirstName[lineCount] = token.c_str();
		SNNode* newNode = new SNNode();
		snElement = strtok_s((char*)token.c_str(), ",", &next_element);
		snHead->sname = snElement;
		snElement = strtok_s(NULL, ",", &next_element);
		snHead->next = NULL;
		snameNodeCount++;
		// Ignore the other parts of the line
		snTokenCount++;
	}

	SNNode* snCurrent = snHead;

	while (ifSecondName >> theSNLine)
	{
		snLineCount++;
		std::stringstream snSSLine(theSNLine);

		std::string token;

		while (std::getline(snSSLine, token))
		{
			//arrFirstName[lineCount] = token.c_str();
			//arrFirstName.push(token);
			SNNode* newNode = new SNNode();
			snElement = strtok_s((char*)token.c_str(), ",", &next_element);
			newNode->sname = snElement;
			newNode->next = NULL;
			snCurrent->next = newNode;
			snElement = strtok_s(NULL, ",", &next_element);

			snCurrent = snCurrent->next;
			snameNodeCount++;



			// Ignore the other parts of the line
			snTokenCount++;
		}
	}

	/*for (int i = 0; i < arrFirstName.size(); i++) {
		std::cout << arrFirstName.get(i) << std::endl;
	}*/
	snCurrent = snHead;
	/*while (snCurrent != NULL) {
		std::cout << snCurrent->sname << std::endl;
		snCurrent = snCurrent->next;
	}*/
	std::cout << "Second Name Lines read = " << snLineCount << std::endl;
	ifSecondName.close();


	/**********************************************************************
									STREET ADDRESSES
	***********************************************************************/
	std::ifstream ifStreetNames(streetNameFile);
	if (!ifStreetNames.is_open()) {
		std::cout << errorString << std::endl;
		return false;
	}

	std::string theSTLine;
	unsigned int stLineCount = 0;

	std::getline(ifStreetNames, theSTLine);
	//ifStreetNames >> theSTLine;

	//STNode* stHead = new STNode();

	stLineCount++;
	token = "";
	std::stringstream stSSLine(theSTLine);
	
	/*std::cout << "theSTLine: " << theSTLine << std::endl;
	std::cout << "stSSLine: " << stSSLine.str() << std::endl;*/
	unsigned int stTokenCount = 0;
	//std::cout << "Initial Token: " << token << std::endl;
	//char* stElement;
	//std::cout << "Next Token: " << token << std::endl;

	std::getline(stSSLine, token);
	while (std::getline(stSSLine, token))
	{
		//arrFirstName[lineCount] = token.c_str();

		STNode* newNode = new STNode();
		//stElement = strtok_s((char*)token.c_str(), "", &next_element);
		stHead->stname = token;
		//stElement = strtok_s(NULL, "", &next_element);
		stHead->next = NULL;
		stNodeCount++;
		// Ignore the other parts of the line
		stTokenCount++;
	}

	STNode* stCurrent = stHead;

	while (getline(ifStreetNames,theSTLine))
	{
		stLineCount++;
		std::stringstream stSSLine(theSTLine);

		std::string token;
		//unsigned int tokenCount = 0;

		while (std::getline(stSSLine, token))
		{
			//arrFirstName[lineCount] = token.c_str();
			//arrFirstName.push(token);
			//std::cout << "Token: " << token << std::endl;
			//std::cout << "stSSLine: " << stSSLine.str() << std::endl;
			STNode* newNode = new STNode();
			//stElement = strtok_s((char*)token.c_str(), "", &next_element);
			newNode->stname = token;
			newNode->next = NULL;
			stCurrent->next = newNode;
			//stElement = strtok_s(NULL, "", &next_element);

			stCurrent = stCurrent->next;
			stNodeCount++;

			// Ignore the other parts of the line
			stTokenCount++;
		}
	}

	/*for (int i = 0; i < arrFirstName.size(); i++) {
		std::cout << arrFirstName.get(i) << std::endl;
	}*/
	stCurrent = stHead;
	/*while (stCurrent != NULL) {
		std::cout << stCurrent->stname << std::endl;
		stCurrent = stCurrent->next;
	}*/
	std::cout << "Street Names Lines read = " << stLineCount << std::endl;
	ifStreetNames.close();

	/**********************************************************************
							RANDOM USER GENERATION
	***********************************************************************/
	
	LoadSongsFromCSV("./data/audiio.csv", generateRandomPerson(fnTokenCount, snTokenCount, stTokenCount, fnHead, snHead, stHead));
	return true;
}

// Here's a simple way to load the comma delimited files:
bool cPersonGenerator::readCSVFile(void)
{
	// Open the file
	std::ifstream namesFile("./data/yob2000.txt");
	if (!namesFile.is_open())
	{
		std::cout << "Didn't open file" << std::endl;
		return false;
	}

	// name,rank,count,prop100k,cum_prop100k,pctwhite,pctblack,pctapi,pctaian,pct2prace,pcthispanic
	// SMITH,1,2442977,828.19,828.19,70.9,23.11,0.5,0.89,2.19,2.4
	//
	// - rank is how popular the last name is, like 1st, 2nd, etc.
	// - count is how many people have that last name, so 2,442,977 people have last name "Smith"
	// - prop100k is the ratio per 100,000 people. Smith is 828.19, 
	//            meaning that there's a 828.19 out of 100,000 chance (0.82819% chance)
	//            that someone is named "Smith"

	std::string theFNLine;
	// std::string theComma;

	/* 
	   FNNode* headNode = new FNNode();
	   TODO: read fist line and make it the head FNNode
	   FNNode* currentNode = headNode;
	*/
	unsigned int fnLineCount = 0;
	while (namesFile >> theFNLine)
	{
		fnLineCount++;
		//std::stringstream ssLine(theLine);
		/*
			currentNode->next = AddNode(args);
			currentNode->next = currentNode;
		*/
		//std::cout << theFNLine << std::endl;

		/*std::string token;
		unsigned int tokenCount = 0;*/
		//while (std::getline(ssLine, token, ","))
		//{
		//	/*if (tokenCount == 0)
		//	{
		//		std::cout << token << std::endl;
		//	}*/
		//	std::cout << token;
		//	/*if (tokenCount == 1)
		//	{
		//		std::cout << token << std::endl;
		//	}*/
		//	// Ignore the other parts of the line
		//	tokenCount++;
		//}
	}

	std::cout << "Lines read = " << fnLineCount << std::endl;

	return true;
}

cPerson* cPersonGenerator::generateRandomPerson(int fnTokenCount, int snTokenCount, int stTokenCount, FNNode* fnCurrent, SNNode* snCurrent, STNode* stCurrent) {
	cPerson* user = new cPerson();
	int i;

	for (i = 0; i < RandGen(1, fnTokenCount); i++) {
		fnCurrent = fnCurrent->next;
	}

	user->first = fnCurrent->fname;

	for (i = 0; i < RandGen(1, snTokenCount); i++) {
		snCurrent = snCurrent->next;
	}

	user->last = snCurrent->sname;

	for (i = 0; i < RandGen(1, stTokenCount); i++) {
		stCurrent = stCurrent->next;
	}

	user->streetName = stCurrent->stname;
	return user;
}

int cPersonGenerator::RandGen(int min, int max) {
	if (min - max == 0) return 0;
	int difference = (max - min);
	srand(time(0));
	int result = min + (rand() % max);
	return result;
}
bool cPersonGenerator::LoadSongsFromCSV(std::string fileName, cPerson* user)
{
	std::ifstream namesFile(fileName);
	if (!namesFile.is_open())
	{
		std::cout << "Didn't open file" << std::endl;
		return false;
	}

	std::string theSNGLine;
	unsigned int sngLineCount = 0;

	//ifBabyName >> theFNLine;
	std::getline(namesFile, theSNGLine);
	//cSong* sngHead = new cSong();

	sngLineCount++;
	std::stringstream sngLine(theSNGLine);

	std::string token;
	unsigned int sngTokenCount = 0;
	unsigned int sngNodeCount = 0;
	char* next_element;
	char* sngElement = strtok_s((char*)token.c_str(), ",", &next_element);
	std::getline(sngLine, token);
	while (std::getline(sngLine, token))
	{
		//arrFirstName[lineCount] = token.c_str();
		sngElement = strtok_s((char*)token.c_str(), ",", &next_element);
		sngHead->name = sngElement;
		sngElement = strtok_s(NULL, ",", &next_element);
		sngHead->artist = *sngElement;
		sngElement = strtok_s(NULL, ",", &next_element);
		sngHead->next = NULL;
		sngNodeCount++;
		// Ignore the other parts of the line
		sngTokenCount++;
	}
	cSong* sngCurrent = sngHead;
	while (std::getline(namesFile, theSNGLine))
	{
		sngLineCount++;
		std::stringstream sngLine(theSNGLine);

		//std::string token;
		//unsigned int tokenCount = 0;
		//std::cout << "entered parent" << std::endl;
		while (std::getline(sngLine, token))
		{
			//arrFirstName[lineCount] = token.c_str();
			//arrFirstName.push(token);
			cSong* newNode = new cSong();
			if (!token.find('"')) {
				sngElement = strtok_s((char*)token.c_str(), "\"", &next_element);
			}
			else sngElement = strtok_s((char*)token.c_str(), ",", &next_element);
			newNode->name = sngElement;
			if (!token.find('"')) {
				sngElement = strtok_s((char*)token.c_str(), "\"", &next_element);
			}
			else sngElement = strtok_s((char*)token.c_str(), ",", &next_element);
			newNode->artist = *sngElement;
			newNode->next = NULL;
			sngCurrent->next = newNode;
			if (!token.find('"')) {
				sngElement = strtok_s((char*)token.c_str(), "\"", &next_element);
			}
			else sngElement = strtok_s((char*)token.c_str(), ",", &next_element);

			sngCurrent = sngCurrent->next;
			sngNodeCount++;
			// Ignore the other parts of the line
			sngTokenCount++;
		}
	}

	/*for (int i = 0; i < arrFirstName.size(); i++) {
		std::cout << arrFirstName.get(i) << std::endl;
	}*/
	sngCurrent = sngHead;
	/*while (sngCurrent != NULL) {
		std::cout << "Name: " << sngCurrent->name << "--Artist " << sngCurrent->artist << " " << std::endl;
		sngCurrent = sngCurrent->next;
	}*/
	std::cout << "Song Name Lines read = " << sngLineCount << std::endl;
	namesFile.close();

	/*std::cout << "Lines read = " << lineCount << std::endl;*/
	input:
	std::cout << "Enter a number between 1 to " << sngNodeCount<< std::endl;
	unsigned int song_num;
	std::cin >> song_num;
	if (song_num > sngNodeCount || song_num==0) {
		std::cout << "Invalid Value" << std::endl;
		goto input;
	}

	for (int i = 0; i < song_num; i++) {
		sngCurrent = sngCurrent->next;
	}

	user->song = sngCurrent->name;

	std::cout << "User Details:\nFirst Name: " << user->first << "\nSecond Name: " << user->last << "\nStreet Address: " << user->streetName << "\nSong: "<<user->song<< std::endl;
	
	return true;
}
