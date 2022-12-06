#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Event {
private:
	char* name;
	char* startTime;
	int duration;

public:

	Event() {
		this->name = nullptr;
		this->startTime = nullptr;
		this->duration = -1;
	}

	Event(const char* name, const char* startTime, int duration){
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->startTime = new char[strlen(startTime) + 1];
		strcpy(this->startTime, startTime);

		this->duration = duration;
	}

	Event(const Event& event) {
		this->duration = event.duration;

		this->name = new char[strlen(event.name) + 1];
		strcpy(this->name, event.name);

		this->startTime = new char[strlen(event.startTime) + 1];
		strcpy(this->startTime, event.startTime);
	}

	bool operator==(const Event& anotherEvent) {
		if (this == &anotherEvent) {
			return true;
		}

		if (strcmp(this->name, anotherEvent.name) != 0) {
			return false;
		}

		if (strcmp(this->startTime, anotherEvent.startTime) != 0) {
			return false;
		}

		if (this->duration != anotherEvent.duration) {
			return false;
		}


		return true;
	}

	bool operator!=(const Event& anotherEvent) {
		if (*this == anotherEvent) {
			return false;
		}

		return true;
	}

	string toString() {
		string result = "";
		result += "Event ";
		result += name;
		result += " runs at ";
		result += startTime;


		char buffer[5];
		result += buffer;
		result += " and lasts ";
		result += duration;
		result += '\n';

		return result;
	}

	void print() {
		cout << "Event " << name << " runs at " << startTime << " in room "
			<< " and lasts " << duration << endl;
	}

	~Event() {
		delete[] this->name;
		delete[] this->startTime;
	}
	

};



int main() {

	Event event("event", "19:30", 2);
	event.print();

}