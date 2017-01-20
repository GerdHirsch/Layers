/*
 * layers.h
 *
 *  Created on: 30.06.2015
 *      Author: Gerd
 */

#ifndef LAYERS_H_
#define LAYERS_H_

#include <iostream>

template<class LowerLayer>
struct TopLayer : LowerLayer::template LayerImpl<TopLayer<LowerLayer>>{

	using this_type = TopLayer<LowerLayer>;
	using base_type = typename LowerLayer::template LayerImpl<this_type>;

	static std::string toString(){ return "TopLayer<LowerLayer>" ; }

	TopLayer(){
		std::cout << "TopLayer::TopLayer()" << std::endl
		<< " this_type: " << TopLayer::toString()
		<< " base_type: " << base_type::toString()
		<< std::endl;
	}
	~TopLayer(){
		std::cout << "TopLayer::~TopLayer()" << std::endl;
	}
	static void staticCallBack(){
		std::cout << "TopLayer::staticCallBack()" << std::endl;
	}
	static void staticCallBack5(){
		std::cout << "TopLayer::staticCallBack5()" << std::endl;
	}
	void useLayerStack(){
		std::cout << "TopLayer::useLayerStack() static" << std::endl;
		this->staticService();
		std::cout << "TopLayer::useLayerStack() non static" << std::endl;
		this->service();
	}
	void callBack(){
		std::cout << "TopLayer::callBack()" << std::endl;
	}
	void callBack5(){
		std::cout << "TopLayer::callBack5()" << std::endl;
	}
};


template<class LowerLayer>
struct Layer4{

	template<class Upper>
	struct LayerImpl :
			LowerLayer::template LayerImpl< Upper >
	{
		using this_type = LayerImpl<Upper>;
		using base_type = typename LowerLayer::template LayerImpl<Upper>;

		static std::string toString(){ return "Layer4::LayerImpl<Upper>"; }

		LayerImpl(){
			std::cout << "Layer4::LayerImpl::LayerImpl()" << std::endl
			<< " this_type: " << this_type::toString()
			<< " base_type: " << base_type::toString()
			<< std::endl;
		}		~LayerImpl(){
			std::cout << "Layer4::LayerImpl::~LayerImpl()" << std::endl;
		}

		static void staticService(){
			std::cout << "Layer4Impl::staticService()" << std::endl;
			base_type::staticService();
		}
		void service(){
			std::cout << "Layer4Impl::service()" << std::endl;
			this->base_type::service();
		}
		static void staticCallBack(){
			std::cout << "Layer4Impl::staticCallBack()" << std::endl;
		}
		static void staticCallBack4(){
			std::cout << "Layer4Impl::staticCallBack4()" << std::endl;
		}
		Upper* This(){ return static_cast<Upper*>(this);}

		void callBack(){
			std::cout << "Layer4Impl::callBack()" << std::endl;
			This()->callBack();
		}
		void callBack4(){
			std::cout << "Layer4Impl::callBack4()" << std::endl;
		}
	};
};
template<class LowerLayer>
struct Layer3{

	template<class TopLayer>
	struct LayerImpl :
			LowerLayer::template LayerImpl< TopLayer >
	{
		using this_type = LayerImpl<TopLayer>;
		using base_type = typename LowerLayer::template LayerImpl<TopLayer>;

		static std::string toString(){ return "Layer3::LayerImpl<TopLayer>"; }

		LayerImpl(){
			std::cout << "Layer3::LayerImpl::LayerImpl()" << std::endl
			<< " TopLayer: " << TopLayer::toString()
			<< " base_type: " << base_type::toString()
			<< std::endl;
		}
		~LayerImpl(){
			std::cout << "Layer3::LayerImpl::~LayerImpl()" << std::endl;
		}
		using base_type::This;

		static void staticService(){
			std::cout << "Layer3Impl::staticService()" << std::endl;
			base_type::staticService();
		}
		void service(){
			std::cout << "Layer3Impl::service()" << std::endl;
			this->base_type::service();
		}
		static void staticCallBack(){
			std::cout << "Layer3Impl::staticCallBack()" << std::endl;
		}
		static void staticCallBack3(){
			std::cout << "Layer3Impl::staticCallBack3()" << std::endl;
		}
		void callBack(){
			std::cout << "Layer3Impl::callBack()" << std::endl;
		}
		void callBack3(){
			std::cout << "Layer3Impl::callBack3()" << std::endl;
		}
	};
};
template<class LowerLayer>
struct Layer2{

	template<class TopLayer>
	struct LayerImpl :
			LowerLayer::template LayerImpl< TopLayer > //
//			LowerLayer::template LayerImpl< LayerImpl<Upper> > // lost of type information
	{
		using this_type = LayerImpl<TopLayer>;
		using base_type = typename LowerLayer::template LayerImpl< TopLayer >;

		static std::string toString(){ return "Layer2::LayerImpl<TopLayer>"; }


		LayerImpl(){
			std::cout << "Layer2::LayerImpl::LayerImpl()" << std::endl
			<< " TopLayer: " << TopLayer::toString()
			<< " base_type: " << base_type::toString()
			<< std::endl;
		}
		~LayerImpl(){
			std::cout << "Layer2::LayerImpl::~LayerImpl()" << std::endl;
		}
		using base_type::This;

		static void staticService(){
			std::cout << "Layer2Impl::staticService()" << std::endl;
			base_type::staticService();
		}
		void service(){
			std::cout << "Layer2Impl::service()" << std::endl;
			this->base_type::service(); // delegates to base class
			This()->callBack3();
		}
		static void staticCallBack(){
			std::cout << "Layer2Impl::staticCallBack()" << std::endl;
		}
		static void staticCallBack2(){
			std::cout << "Layer2Impl::staticCallBack2()" << std::endl;
		}
		void callBack(){
			std::cout << "Layer2Impl::callBack()" << std::endl;
		}
		void callBack2(){
			std::cout << "Layer2Impl::callBack2()" << std::endl;
		}
	};
};

template<class LowerLayer>
struct Layer1{

	template<class TopLayer>
	struct LayerImpl :
			LowerLayer::template LayerImpl< TopLayer > //
	{
		using this_type = LayerImpl<TopLayer>;
		using base_type = typename LowerLayer::template LayerImpl<TopLayer>;

		using base_type::This; // access to this conversion

		static std::string toString(){ return "Layer1::LayerImpl<TopLayer>"; }

		LayerImpl(){
			std::cout << "Layer1::LayerImpl::LayerImpl()" << std::endl
			<< " TopLayer: " << TopLayer::toString()
			<< " base_type: " << base_type::toString()
			<< std::endl;
		}
		virtual ~LayerImpl(){
			std::cout << "Layer1::LayerImpl::~LayerImpl()" << std::endl;
		}


		static void staticService(){
			std::cout << "Layer1Impl::staticService()" << std::endl;
		}
		void service(){
			std::cout << "Layer1Impl::service()" << std::endl;
		}
		void externalEvent(){
			std::cout << "--- Layer1Impl::externalEvent() static" << std::endl;
			TopLayer::staticCallBack();
//			TopLayer::staticCallBack2();
//			TopLayer::staticCallBack3();
//			TopLayer::staticCallBack4();
			TopLayer::staticCallBack5();
			std::cout << "--- Layer1Impl::externalEvent() non static " << std::endl;
			This()->callBack(); // pure abstract
//			This()->callBack2(); // pure abstract
//			This()->callBack3(); // pure abstract
//			This()->callBack4(); // pure abstract
			This()->callBack5(); // pure abstract
		}
	};
};

struct Layer0{

	template<class TopLayer>
	struct LayerImpl
	{
		static std::string toString(){ return "Layer0::LayerImpl<TopLayer>"; }

		virtual ~LayerImpl(){}

		TopLayer* This(){ return static_cast<TopLayer*>(this);}
	};
};

#endif /* LAYERS_H_ */
