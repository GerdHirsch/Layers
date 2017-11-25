/*
 * UpSideDown.h
 *
 *  Created on: 29.01.2017
 *      Author: Gerd
 */

#ifndef UPSIDEDOWN_H_
#define UPSIDEDOWN_H_

#include <string>
#include <iostream>

namespace UpSideDown{

template<class LowerLayer>
struct TopLayerDown : LowerLayer::template LayerImpl<TopLayerDown<LowerLayer>>{

	using this_type = TopLayerDown<LowerLayer>;
	using base_type = typename LowerLayer::template LayerImpl<this_type>;

//	using base_type::Layer2Down;

	static std::string toString(){ return "TopLayerDown<LowerLayer>" ; }

	TopLayerDown(){
		std::cout << "TopLayerDown::TopLayerDown()" << std::endl
		<< " this_type: " << this_type::toString() << std::endl
		<< " base_type: " << base_type::toString()
		<< std::endl << std::endl;
	}
	~TopLayerDown(){
		std::cout << "TopLayerDown::~TopLayerDown()" << std::endl
		<< " base_type: " << base_type::toString() << std::endl
		<< "This->(): " << this->This()->toString() << std::endl
		<< std::endl;

	}
	static void staticCallBack(){
		std::cout << "TopLayerDown::staticCallBack()" << std::endl;
	}
	static void staticCallBack5(){
		std::cout << "TopLayerDown::staticCallBack5()" << std::endl;
	}
	void useLayerStack(){
		std::cout << "TopLayerDown::useLayerStack() static" << std::endl;
		this->staticService();
		std::cout << std::endl << "TopLayerDown::useLayerStack() non static" << std::endl;
		this->service();
	}
	void callBack(){
		std::cout << "TopLayerDown::callBack()" << std::endl;
	}
	void callBack5(){
		std::cout << "TopLayerDown::callBack5()" << std::endl;
	}
};


struct TopLayerUp{

	template<class TopLayerDown>
	struct LayerImpl
	{
		using this_type = LayerImpl<TopLayerDown>;
		using TopLayerUp = this_type;

//		using TopLayerDown::Layer2Down;

		static std::string toString(){ return "TopLayerUp::LayerImpl<TopLayerDown>"; }

		LayerImpl(){
			std::cout << "TopLayerUp::LayerImpl()" << std::endl
			<< " This()->toString(): " << This()->toString() << std::endl
			<< " this_type: " << this_type::toString() << std::endl
			<< " no base_type" << std::endl
			<< std::endl;
		}
		virtual ~LayerImpl(){
			std::cout << "TopLayerUp::~LayerImpl()" << std::endl << std::endl;
		}

		TopLayerDown* This(){
			static_assert(std::is_base_of< this_type, TopLayerDown>::value,
						"TopLayerUp must be derived from TopLayerUp::LayerImpl<TopLayerDown>"
						);
			return static_cast<TopLayerDown*>(this);
		}
		static void staticService(){
			std::cout << "TopLayerUp::staticService()" << std::endl;
		}
		void service(){
			std::cout << "TopLayerUp::service()" << std::endl;
//			this->base_type::service(); // delegates to base class
//			This()->callBack3();
		}
	};
};


//===========================
template<class LowerLayer>
struct Layer2Down{

	template<class TopLayer>
	struct LayerImpl :
			LowerLayer::template LayerImpl< TopLayer > //
//			LowerLayer::template LayerImpl< LayerImpl<Upper> > // lost of type information
	{
		using this_type = LayerImpl<TopLayer>;

		using Layer2Down = this_type;
		using base_type = typename LowerLayer::template LayerImpl< TopLayer >;
//		using Layer2Up = typename TopLayer::Layer2Up;
		using Layer2Up = typename base_type::Layer2Up;

		static std::string toString(){ return "Layer2Down::LayerImpl<TopLayer>"; }


		LayerImpl(){
			std::cout << "Layer2Down::LayerImpl()" << std::endl
			<< " TopLayer: " << TopLayer::toString() << std::endl
			<< " base_type: " << base_type::toString()
			<< std::endl << std::endl;
		}
		~LayerImpl(){
			std::cout << "Layer2Down::~LayerImpl()" << std::endl
			<< " base_type: " << base_type::toString() << std::endl;
		}
		using base_type::This;

		static void staticService(){
			std::cout << "Layer2Down::staticService()" << std::endl;
			base_type::staticService();
		}
		void service(){
			std::cout << "Layer2Down::service()" << std::endl;
			this->base_type::service(); // delegates to base class
//			This()->callBack3();
		}
		static void staticCallBack(){
			std::cout << "Layer2Down::staticCallBack()" << std::endl;
		}
		static void staticCallBack2(){
			std::cout << "Layer2Down::staticCallBack2()" << std::endl;
		}
		void callBack(){
			std::cout << "Layer2Down::callBack()" << std::endl;
		}
		void callBack2(){
			std::cout << "Layer2Down::callBack2()" << std::endl;
		}
	};
};
//===========================
template<class LowerLayer>
struct Layer2Up{

	template<class TopLayer>
	struct LayerImpl :
			LowerLayer::template LayerImpl< TopLayer > //
//			LowerLayer::template LayerImpl< LayerImpl<Upper> > // lost of type information
	{
		using this_type = LayerImpl<TopLayer>;
		using base_type = typename LowerLayer::template LayerImpl< TopLayer >;
		using base_type::This;

		using Layer2Up = this_type;
//		using Layer2Down = typename base_type::Layer2Down;
//		using Layer2Down = typename TopLayer::Layer2Down;
//		using Layer2Down = Layer2Down<Layer2Up<TopLayerUp>>::LayerImpl<TopLayer>;


		static std::string toString(){ return "Layer2Up::LayerImpl<TopLayer>"; }


		LayerImpl(){
			std::cout << "Layer2Up::LayerImpl::LayerImpl()" << std::endl
			<< " TopLayer: " << TopLayer::toString() << std::endl
			<< " base_type: " << base_type::toString()
			<< std::endl << std::endl;
		}
		~LayerImpl(){
			std::cout << "Layer2Up::~LayerImpl()" << std::endl
			<< " base_type: " << base_type::toString() << std::endl;
		}

		static void staticService(){
			std::cout << "Layer2Up::staticService()" << std::endl;
			base_type::staticService();
		}
		void service(){
			std::cout << "Layer2Up::service()" << std::endl;
			this->base_type::service(); // delegates to base class
//			This()->callBack3();
		}
		static void staticCallBack(){
			std::cout << "Layer2Up::staticCallBack()" << std::endl;
		}
		static void staticCallBack2(){
			std::cout << "Layer2Up::staticCallBack2()" << std::endl;
		}
		void callBack(){
			std::cout << "Layer2Up::callBack()" << std::endl;
		}
		void callBack2(){
			std::cout << "Layer2Up::callBack2()" << std::endl;
		}
	};
};

}



#endif /* UPSIDEDOWN_H_ */
