#include "petri.h"



void outArc::fire() {
	p.setamt(p.getamt() - amt_to_move);
}
void inArc::fire() {
	p.setamt(p.getamt() + amt_to_move);
}
