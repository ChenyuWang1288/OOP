#ifndef SERIALIZATION_H
#define SERIALIZATION_H
#include "Xml_Serialization.h"
namespace Serialization {
	template<typename T>
	void Serialization(const T& o, const string nodename, const char* path) {
		Xml_Serialization::xml_ser xmlMethod(path);
		xmlMethod.Serializer(o, nodename, xmlMethod.root);
	}
}
namespace Deserialization {
	template<typename T>
	void Deserialization(T& o, const string nodename, const char* path) {
		Xml_Serialization::xml_deser xmlMethod(path);
		xmlMethod.Deserializer(o, nodename, (xmlMethod.root)->FirstChildElement());
	}
}
#endif
