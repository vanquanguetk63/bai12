#ifndef TICKET_H_
#define TICKET_H_

class Ticket
{
public:
    Ticket();
	Ticket(int idTrip, int idCard);
	~Ticket();

	int getIdCard() {
	return idCard;}
private:
	int idTrip;
	int idCard;
};


#endif // TICKET_H_
