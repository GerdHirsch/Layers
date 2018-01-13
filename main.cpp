/*
 * main.cpp
 *
 *  Created on: 30.06.2015
 *      Author: Gerd
 */


#include "upsidedown/UpSideDown.h"

#include "layers.h"
#include "layer0.h"
#include <iostream>

#include "GenericTools/AssembleLayers.h"
using namespace std;
using namespace GenericTools;

void demoUpSideDown();
void demoLayers();

int main(){
	cout << "=== Layers" << endl;
	demoLayers();
//	demoUpSideDown();
	cout << "=== end Layers" << endl;
}
void demoUpSideDown(){
	using namespace UpSideDown;

	using Application1 = TopLayerDown<Layer2Down<Layer2Up<TopLayerUp>>>;

	using L0 = TopLayerUp;
	using L1 = Layer2Up<L0>;
	using L2 = Layer2Down<L1>;
//	using Application2 = TopLayerDown<L2>;
//	using App = TopLayerDown<TopLayerUp>;

	cout << "=== App app;" << endl;
	using App = Application1;
	App app;
	cout << "=== useLayerStack();" << endl;
	app.useLayerStack();
	cout  << endl << " === end demoUpSideDown"<< endl;
}

void demoLayers(){
	cout << "demoLayers" << endl;
	cout << "L0, L1, ... Application0 app0.useLayerStack()" << endl;
	using L0 = Layer0;
	//...
	using L1 = Layer1<L0> ;
	using L2 = Layer2<L1> ;
	using L3 = Layer3<L2> ;
	using L4 = Layer4<L3> ;
	using Application0 = TopLayer<L4>;
	Application0 app0;
	// Alternative definitions
//	using Application0 = TopLayer<Layer4<Layer3<Layer2<Layer1<Layer0>>>>>;
//	app0.useLayerStack();

//	using templatePack = TemplatePack<Layer1, Layer2, TopLayer>;
//	using App = assembleLayersImpl<Layer0, templatePack>;

	cout << "Application = assembleLayers<L0, L1 ...>" << endl;
	using Application = assembleLayers<Layer0, Layer1, Layer2, Layer3, Layer4, TopLayer>;

//	using Application = assembleLayers<Layer0, Layer1, TopLayer>;

	cout << endl << "App app;" << endl;
	Application app;

	cout << endl << "event from top down" << endl;
	app.useLayerStack();

	cout << endl << "event from bottom up" << endl;
	app.externalEvent();
	cout << "=== end Layers" << endl;
}
