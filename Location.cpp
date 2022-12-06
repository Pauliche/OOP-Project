#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Location {
private:
	char* name;
	char* address;


public:
	Location(const char* name, const char* address) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->address = new char[strlen(address) + 1];
		strcpy(this->address, address);

	}

	bool operator==(const Location& otherLocation) {
		if (this == &otherLocation) {
			return true;
		}

		if (strcmp(this->name, otherLocation.name) != 0) {
			return false;
		}

		if (strcmp(this->address, otherLocation.address) != 0) {
			return false;
		}


		return true;
	}

	bool operator!=(const Location& anotherLocation) {
		return !(*this == anotherLocation);
	}



	~Location() {
		delete[] name;
		delete[] address;

	}



	operator string() {
		return this->toString();
	}

	string toString() const {
		string result = "";
		result += "Location ";
		result += name;
		result += " is";
		result += address;
		result += '\n';
		return result;

		
		
	}
};


int main() {

	Location location("location", "address");


	Location location2("", "");
	location2 = location;
	

	return 0;
}