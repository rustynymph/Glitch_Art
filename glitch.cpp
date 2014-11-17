/* Author: Annie Kelly
 * Takes image as input, spits out a dope glitched out masterpiece.
 * Will be adding functionality in the future
 */

using namespace std;
#include <fstream>
#include <cstdio>
#include <iostream>
#include "glitch.h"

int main(int argc, char* argv[]){
	string name = argv[1];
	//char find = argv[2][0];
	//char replace = argv[3][0];
	string contents = readFile(name);
	string new_contents = glitch(contents);
	writeFile(name, new_contents);
	return 0;
}

string readFile(string file){
	string data;
	ifstream image;
	image.open(file);
	if (image.is_open()){
		getline(image, data, '\n');	
		image.close();
	}
	return data; 
}

string glitch(string data){
     int length = data.length();
     int first_quarter = length/4;
     int piece = length/9;
     //int offset = first_quarter + piece;
     /*for(int i = first_quarter; i < length; i++){
     	data[i] = (char)data[i];
     	if(data[i] == find){
     		data[i] = replace;
     	}
     }*/

     data.erase(first_quarter, piece);
     return data;
}

void writeFile(string file, string new_contents){
	ofstream new_image (file, std::ofstream::out);
	new_image << new_contents;
	new_image.close();
}