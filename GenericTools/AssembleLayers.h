/*
 * CreateLayers.h
 *
 *  Created on: 19.01.2017
 *      Author: Gerd
 */

#ifndef GENERIC_TOOLS_ASSEMBLELAYERS_H_
#define GENERIC_TOOLS_ASSEMBLELAYERS_H_

namespace GenericTools{

template<template<typename> class ...G>
struct TemplatePack;


//template<class Layer0, template<typename> class ...Layers>
//struct assembleLayersImpl;

template<class Layer0, template<typename>class Layer1, template<typename> class ...Layers>
struct assembleLayersImpl
{
	using type = typename assembleLayersImpl<Layer1<Layer0>, Layers...>::type;
};

//template<class Layer0, template<typename>class ...Layers>
//struct assembleLayersImpl<Layer0, TemplatePack<Layers...> : assembleLayersImpl<Layer0, Layers...>{};

template<class LayerN, template<typename> class TopLayer>
struct assembleLayersImpl<LayerN, TopLayer>{
	using type = TopLayer<LayerN>;
};

//template<class Layer0, class Layer1>
//struct createImpl<Layer0, Layer1>{};// : createImpl<Layer0, Layers...>{};

template<class Layer0, template<typename>class ...LayerN>
using assembleLayers = typename assembleLayersImpl<Layer0, LayerN...>::type;

}

#endif /* GENERIC_TOOLS_ASSEMBLELAYERS_H_ */
