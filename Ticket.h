#ifndef TICKET_H_
#define TICKET_H_

class Ticket
{
friend class Trip;

public:
    Ticket();
	Ticket(int idTrip, int idCard);
	~Ticket();

	int getIdCard() {
	return idCard;}
	int getIdTrip() {
	return idTrip;}
private:
	int idTrip;
	int idCard;
};


#endif // TICKET_H_
