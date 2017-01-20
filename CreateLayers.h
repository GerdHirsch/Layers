/*
 * CreateLayers.h
 *
 *  Created on: 19.01.2017
 *      Author: Gerd
 */

#ifndef CREATELAYERS_H_
#define CREATELAYERS_H_

template<class Layer1, template<typename>class LayerN, template<typename> class ...Layers>
struct createImpl
{
	using type = typename createImpl<LayerN<Layer1>, Layers...>::type;
};

template<class LayerN, template<typename> class TopLayer>
struct createImpl<LayerN, TopLayer>{
	using type = TopLayer<LayerN>;
};

template<class Layer0, template<typename>class ...LayerN>
using createLayers = typename createImpl<Layer0, LayerN...>::type;


#endif /* CREATELAYERS_H_ */
