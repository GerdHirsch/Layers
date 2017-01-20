/*
 * Layer0.h
 *
 *  Created on: 20.01.2017
 *      Author: Gerd
 */

#ifndef LAYER0_H_
#define LAYER0_H_

namespace GenericTools{

struct Layer0{

	template<class TopLayer>
	struct LayerImpl
	{
		static std::string toString(){ return "Layer0::LayerImpl<TopLayer>"; }

		virtual ~LayerImpl(){}

		TopLayer* This(){ return static_cast<TopLayer*>(this);}
	};
};

}

#endif /* LAYER0_H_ */
