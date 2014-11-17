/* Author: Annie Kelly
 * Takes image as input, spits out a dope glitched out masterpiece.
 * Will be adding functionality in the future
 */

using namespace std;
#include <fstream>
#include <cstdio>
#include <iostream>
#include <glitch.h>

int main(int argc, char* argv[]){
	string name = argv[1];
	string find = argv[2];
	string replace = argv[3];
	string contents = readFile(name);
	string new_contents = glitch(contents, find, replace);
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

string glitch(string data, string find, string replace){
     int length = data.length();
     for(int i = 0; i < length; i++){
     	//data[i] = (char)data[i];
     	if(data[i] == find){
     		data[i] = replace;
     	}
     }
     return data;
}

void writeFile(string file, string new_contents){
	ofstream new_image (file, std::ofstream::out);
	new_image << new_contents;
	new_image.close();
}