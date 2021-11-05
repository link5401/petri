#define MAX_SIZE 5

class Place{
	int amt; //holding amt tokens
public:
	Place(int a) { amt = a; }
	Place() {}

	int getamt() { return amt; }
	void setamt(int a) { amt = a; }
};
//an arc, could be in or out.
class Arc {
protected:
	Place p;
	int amt_to_move;
public:
	Arc() {}
	Arc(Place place, int to_move) {
		p = place;
		amt_to_move = to_move;
	}	
	int getd() {
		return p.getamt();
	}
	int getMove() {
		return amt_to_move;
	}
	Arc operator=(Arc const obj) {
		Arc res;
		res.p = obj.p;
		res.amt_to_move = obj.amt_to_move;
		return res;
	}
};
class outArc : public Arc{
public:
	void fire();
	outArc() {}
	outArc(Place place, int to_move) {
		p = place;
		amt_to_move = to_move;
	}
	outArc operator=(outArc const &obj) {
		outArc res;
		res.p = obj.p;
		res.amt_to_move = obj.amt_to_move;
		return res;
	}

};
class inArc : public Arc {
	void fire();
public:
	inArc() {}
	inArc(Place place, int to_move) {
		p = place;
		amt_to_move = to_move;
	}
	inArc operator=(inArc const* obj) {
		inArc res;
		res.p = obj->p;
		res.amt_to_move = obj->amt_to_move;
		return res;
	}
};
//transition
class Transition {
	int number_of_out;
	int number_of_in;
	outArc oArcs[MAX_SIZE];
	inArc  iArcs[MAX_SIZE];
public:
	Transition(inArc* i, outArc* o) {

		number_of_out = sizeof(o) / sizeof(o[0]);
		number_of_in = sizeof(i) / sizeof(i[0]);

		for (int index = 0; index < number_of_out; index++)
			oArcs[index] = o[index];
		for (int index = 0; index < number_of_in; index++)
			iArcs[index] = &i[index];
	}
	void print() {
		std::cout << number_of_in;
		for (int i = 0; i < number_of_in; i++) 
			
			std::cout << iArcs[i].getMove();
		
	}
};