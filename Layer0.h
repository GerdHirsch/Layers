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
		using this_type = LayerImpl<TopLayer>;

		static std::string toString(){ return "Layer0::LayerImpl<TopLayer>"; }

		virtual ~LayerImpl(){}

		TopLayer* This(){
			static_assert(std::is_base_of< this_type, TopLayer>::value,
						"TopLayer must be derived from Layer0::LayerImpl<TopLayer>"
						);
			return static_cast<TopLayer*>(this);}
	};
};

}

#endif /* LAYER0_H_ */
