/*
 * main.cpp
 *
 *  Created on: 30.06.2015
 *      Author: Gerd
 */


#include "layers.h"
#include "CreateLayers.h"

#include <iostream>
using namespace std;



int main(){
	cout << "=== begin Layers" << endl;

	using L0 = Layer0;
	//...
	using L1 = Layer1<L0> ;
	using L2 = Layer2<L1> ;
	using L3 = Layer3<L2> ;
	using L4 = Layer2<L3> ;

//	using Application = TopLayer<L4>;
//	using Application = TopLayer<Layer4<Layer3<Layer2<Layer1>>>>;

//	using Application = createLayers<Layer0, Layer1, Layer2, Layer3, Layer4, TopLayer>;
	using Application = createLayers<Layer0, Layer1, TopLayer>;

	cout << endl << "App app;" << endl;
	Application app;

	cout << endl << "event from top down" << endl;
	app.useLayerStack();

	cout << endl << "event from bottom up" << endl;
	app.externalEvent();
	cout << "=== end Layers" << endl;
}
