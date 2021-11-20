#include <iostream>
#include "field.h"
#include "draw.h"
using namespace std;

int main(int argv, char** argc)
{
	cout << "Game of Life" << endl;
	field *f = new field(200, 200);
	f->init();
	//f->setPosition(2,2,1);
	//f->setPosition(2,3,1);
	//f->setPosition(2,4,1);
	//f->setPosition(3,3,0);
	//f->randomize();
	cout << f->getFieldString() << endl << endl;
	draw* d = new draw(200, 200, 60, *f, 5);
	d->init();
	d->loop();
	return 0;
}