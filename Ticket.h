#ifndef TICKET_H_
#define TICKET_H_

class Ticket
{
public:
	Ticket();
	~Ticket();

	void print();

private:
	int seatId;
	int idTrip;
	int idCard;
};


#endif // TICKET_H_
