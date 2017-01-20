# Layers
Example for implementing multi layers with C++ CRTP
This project is intended to be used as an area to experiment with the C++ template based (CRTP) implementation of 
multi layers.

To implement multiple exchangable layers you need two interfaces for each layer;
the service provided by the layer used from the upper layer and
the service required by the layer implemented by the upper layer.

With C++ templates and the CRTP all could be inlined. 
The examples shows how to implement the different layers.

See [wiki](https://github.com/GerdHirsch/Layers/wiki) of this repository.
