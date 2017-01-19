/*
 * main.cpp
 *
 *  Created on: 30.06.2015
 *      Author: Gerd
 */


#include "layers.h"

#include <iostream>
using namespace std;

int main(){
	cout << "Layers" << endl;


	typedef Layer1 L1;
	//...
	typedef Layer2<L1> L2;
	typedef Layer3<L2> L3;
	typedef Layer4<L3> L4;

//	typedef ApplicationOuter<L1>::Application App;
	typedef ApplicationOuter<L4>::Application App;

	cout << endl << "App app;" << endl;
	App app;
	cout << endl << "event from top down" << endl;
	app.useLayerStack();

	// Only needed to simulate an external event
//	typedef App::Lower L_4;
//	typedef L_4::Lower L_3;
//	typedef L_3::Lower L_2;
//	typedef L_2::Lower L_1;

	cout << endl << "event from bottom up" << endl;
	app.externalEvent();
}
