#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


enum class TicketAvailability {

		AVAILABLE,
		SOLD_OUT
};

class Ticket {
public:

	int ticketId;
	TicketAvailability availability;

	Ticket (int ticketId) : ticketId(ticketId) {
		this->availability = TicketAvailability::AVAILABLE;
	}

	Ticket(const Ticket& ticket) :ticketId(ticket.ticketId) {
		this->availability = ticket.availability;
	}

	bool operator==(const Ticket& anotherTicket) {
		if (this == &anotherTicket) {
			return true;
		}

		if (this->ticketId != anotherTicket.ticketId) {
			return false;
		}

		if (this->availability != anotherTicket.availability) {
			return false;
		}

		return true;
	}

	bool operator!=(const Ticket& anotherTicket) {
		return !(*this == anotherTicket);
	}

	void setAvailability(TicketAvailability availability) {
		this->availability = availability;
	}

	int getTicketId() {
		return this->ticketId;
	}

	TicketAvailability getAvailability() {
		return this->availability;
	}

	void print() {
		cout << "Ticket " << this->ticketId << " is " << enumToString(this->availability) << endl;
	}

private:

	string enumToString(TicketAvailability availability) {
		switch (availability) {
		case TicketAvailability::AVAILABLE:
			return "available";
		case TicketAvailability::SOLD_OUT:
			return "sold out";
		default:
			return "unknown";
		}
	}

	;
	
};


int main() {

	Ticket ticket1(1);
	Ticket ticket2(2);

	ticket1.print();
	ticket2.print();

}
