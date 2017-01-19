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
struct ApplicationOuter
{
	ApplicationOuter(){
		std::cout << "ApplicationOuter::ApplicationOuter()" << std::endl;
	}

	struct Application :
			LowerLayer::template LayerImpl<Application>
	{
		typedef Application this_type;
		typedef typename LowerLayer::template LayerImpl<this_type> Lower; //base_type

		Application(){
			std::cout << "Application::Application()" << std::endl;
		}
		~Application(){
			std::cout << "Application::~Application()" << std::endl;
		}
		static void staticCallBack(){
			std::cout << "Application::staticCallBack()" << std::endl;
		}
		void useLayerStack(){
			std::cout << "Application::useLayerStack()" << std::endl;
			Lower::staticService();
			this->Lower::service();
		}
		void callBack(){
			std::cout << "Application::callBack()" << std::endl;

		}
	};
};

template<class LowerLayer>
struct Layer4{

	template<class Upper>
	struct LayerImpl :
			LowerLayer::template LayerImpl< LayerImpl<Upper> >
	{
		typedef LayerImpl<Upper> this_type;
		typedef typename LowerLayer::template LayerImpl<this_type> Lower; //base_type

		LayerImpl(){
			std::cout << "Layer4::LayerImpl::LayerImpl()" << std::endl;
		}
		~LayerImpl(){
			std::cout << "Layer4::LayerImpl::~LayerImpl()" << std::endl;
		}

		static void staticService(){
			std::cout << "Layer4Impl::staticService()" << std::endl;
			Lower::staticService();
		}
		void service(){
			std::cout << "Layer4Impl::service()" << std::endl;
			this->Lower::service();
		}
		static void staticCallBack(){
			std::cout << "Layer4Impl::staticCallBack()" << std::endl;
			Upper::staticCallBack();
		}
		Upper* This(){ return static_cast<Upper*>(this);}

		void callBack(){
			std::cout << "Layer4Impl::callBack()" << std::endl;
			This()->callBack();
		}
	};
};
template<class LowerLayer>
struct Layer3{

	template<class Upper>
	struct LayerImpl :
			LowerLayer::template LayerImpl< LayerImpl<Upper> >
	{
		typedef LayerImpl<Upper> this_type;
		typedef typename LowerLayer::template LayerImpl<this_type> Lower;

		LayerImpl(){
			std::cout << "Layer3::LayerImpl::LayerImpl()" << std::endl;
		}
		~LayerImpl(){
			std::cout << "Layer3::LayerImpl::~LayerImpl()" << std::endl;
		}
		Upper* This(){ return static_cast<Upper*>(this);}

		static void staticService(){
			std::cout << "Layer3Impl::staticService()" << std::endl;
			Lower::staticService();
		}
		void service(){
			std::cout << "Layer3Impl::service()" << std::endl;
			this->Lower::service();
		}
		static void staticCallBack(){
			std::cout << "Layer3Impl::staticCallBack()" << std::endl;
			Upper::staticCallBack();
		}
		void callBack(){
			std::cout << "Layer3Impl::callBack()" << std::endl;
			This()->callBack();
		}
	};
};
template<class LowerLayer>
struct Layer2{

	template<class Upper>
	struct LayerImpl :
			LowerLayer::template LayerImpl< LayerImpl<Upper> >
	{
		typedef LayerImpl<Upper> this_type;
		typedef typename LowerLayer::template LayerImpl<this_type> Lower;

		LayerImpl(){
			std::cout << "Layer2::LayerImpl::LayerImpl()" << std::endl;
		}
		~LayerImpl(){
			std::cout << "Layer2::LayerImpl::~LayerImpl()" << std::endl;
		}

		Upper* This(){ return static_cast<Upper*>(this);}

		static void staticService(){
			std::cout << "Layer2Impl::staticService()" << std::endl;
			Lower::staticService();
		}
		void service(){
			std::cout << "Layer2Impl::service()" << std::endl;
			this->Lower::service(); // delegates to base class
		}
		static void staticCallBack(){
			std::cout << "Layer2Impl::staticCallBack()" << std::endl;
			Upper::staticCallBack();
		}
		void callBack(){
			std::cout << "Layer2Impl::callBack()" << std::endl;
			This()->Upper::callBack(); // delegates to derived class
		}
	};
};


struct Layer1{

	template<class Upper>
	struct LayerImpl
	{
		LayerImpl(){
			std::cout << "Layer1::LayerImpl::LayerImpl()" << std::endl;
		}
		virtual ~LayerImpl(){
			std::cout << "Layer1::LayerImpl::~LayerImpl()" << std::endl;
		}

		Upper* This(){ return static_cast<Upper*>(this);}

		static void staticService(){
			std::cout << "Layer1Impl::staticService()" << std::endl;
		}
		void service(){
			std::cout << "Layer1Impl::service()" << std::endl;
		}
		void externalEvent(){
			std::cout << "Layer1Impl::externalEvent()" << std::endl;
			Upper::staticCallBack();
			This()->callBack(); // pure abstract
		}
	};
};

#endif /* LAYERS_H_ */
