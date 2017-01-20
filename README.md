# Layers
Example for implementing multi layers with C++ CRTP

To implement multiple exchangable layers you need two interfaces for each layer;
the service provided by the layer used from the upper layer and
the service required by the layer implemented by the upper layer.

With C++ templates and the CRTP all could be inlined. 
The examples shows how to implement the different layers.

There ara three differenct layers: 

the layer on the top, 
which is just a template, 

the layer on the bottom (Layer0),
a type with an inner template, Layer0 is provided by the framework and can be used as it is

and the layers between them which are templates with inner templates.
