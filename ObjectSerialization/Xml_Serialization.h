#ifndef XML_SERIALIAZATION_H
#define XML_SERIALIAZATION_H
#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std;
namespace Xml_Serialization {
	class xml_ser {
	public:
		tinyxml2::XMLElement* root;
		xml_ser(const char* path_) :path(path_) {
			doc.LoadFile(path);
			root = doc.NewElement("Xml_Serialization");
			doc.InsertFirstChild(root);
		}
		~xml_ser() { doc.SaveFile(path); }
		template <typename T>
		typename enable_if<is_arithmetic<T>::value>::type Serializer(const T& o, string nodename, tinyxml2::XMLElement* r) {
			tinyxml2::XMLElement* currentnode = doc.NewElement(nodename.c_str());
			currentnode->SetAttribute("obj", o);
			r->InsertEndChild(currentnode);
		}
		template <typename T>
		typename enable_if<is_same<T, string>::value >::type Serializer(const T& o, string nodename, tinyxml2::XMLElement* r) {
			tinyxml2::XMLElement* currentnode = doc.NewElement(nodename.c_str());
			currentnode->SetAttribute("obj", o.c_str());
			r->InsertEndChild(currentnode);
		}
		template <typename T>
		void Serializer(const vector<T>& o, string nodename, tinyxml2::XMLElement* r) {
			tinyxml2::XMLElement* currentnode = doc.NewElement(nodename.c_str());
			currentnode->SetAttribute("size", o.size());
			r->InsertEndChild(currentnode);
			int i = 0;
			for (auto iter = o.begin(); iter != o.end(); iter++) {
				string newname = "vector" + to_string(i);
				Serializer((*iter), newname, currentnode);
				i++;
			}
		}
		template <typename T>
		void Serializer(const list<T>& o, string nodename, tinyxml2::XMLElement* r) {
			tinyxml2::XMLElement* currentnode = doc.NewElement(nodename.c_str());
			currentnode->SetAttribute("size", o.size());
			r->InsertEndChild(currentnode);
			int i = 0;
			for (auto iter = o.begin(); iter != o.end(); iter++) {
				string newname = "list" + to_string(i);
				Serializer((*iter), newname, currentnode);
				i++;
			}
		}
		template <typename T>
		void Serializer(const set<T>& o, string nodename, tinyxml2::XMLElement* r) {
			tinyxml2::XMLElement* currentnode = doc.NewElement(nodename.c_str());
			currentnode->SetAttribute("size", o.size());
			r->InsertEndChild(currentnode);
			int i = 0;
			for (auto iter = o.begin(); iter != o.end(); iter++) {
				string newname = "set" + to_string(i);
				Serializer((*iter), newname, currentnode);
				i++;
			}
		}
		template <typename T1, typename T2>
		void Serializer(const pair<T1, T2>& o, string nodename, tinyxml2::XMLElement* r) {
			tinyxml2::XMLElement* currentnode = doc.NewElement(nodename.c_str());
			// currentnode->SetAttribute("size", o.size());
			r->InsertEndChild(currentnode);
			Serializer(o.first, "pair_first", currentnode);
			Serializer(o.second, "pair_second", currentnode);
		}
		template <typename T1, typename T2>
		void Serializer(const map<T1, T2>& o, string nodename, tinyxml2::XMLElement* r) {
			tinyxml2::XMLElement* currentnode = doc.NewElement(nodename.c_str());
			currentnode->SetAttribute("size", o.size());
			r->InsertEndChild(currentnode);
			int i = 0;
			for (auto iter = o.begin(); iter != o.end(); iter++) {
				string newname = "map_" + to_string(i);
				Serializer((*iter), newname, currentnode);
				i++;
			}
		}

		tinyxml2::XMLDocument doc;
		const char* path;
	};
	class xml_deser {
	public:
		const char* path;
		tinyxml2::XMLDocument doc;
		tinyxml2::XMLElement* root;
		stringstream buffer;
		xml_deser(const char* path_) :path(path_) {
			doc.LoadFile(path);
			root = doc.RootElement();
		}
		~xml_deser() { doc.SaveFile(path); }
		/*template <typename T>
		typename enable_if<is_arithmetic<T>::value || is_same<T, string>::value>::type Deserializer(T& o, string nodename, tinyxml2::XMLElement* node) {
			buffer << node->FirstAttribute()->Value();
			buffer >> o;
			buffer.clear();
		}*/
		template <typename T>
		typename enable_if<is_arithmetic<T>::value || is_same<T, string>::value>::type Deserializer(T& o, string nodename, tinyxml2::XMLElement* node) {
			buffer << node->FirstAttribute()->Value();
			buffer >> o;
			buffer.clear();
		}
		/*template <typename T>
		typename enable_if<is_same<T, string>::value>::type Deserializer(T& o, string nodename, tinyxml2::XMLElement* node) {
			string tmp = node->FirstAttribute()->Value();
			buffer << tmp;
			buffer >> o;
			buffer.clear();
		}*/
		template <typename T>
		void Deserializer(vector<T>& o, string nodename, tinyxml2::XMLElement* node) {
			int length{};
			buffer << node->FirstAttribute()->Value();
			buffer >> length;
			buffer.clear();
			o.clear();
			// o.resize(length);
			tinyxml2::XMLElement* next = node->FirstChildElement();
			int i = 0;
			for (int m = 0; m < length; m++) {
				string tmp = "vector" + to_string(i);
				T ele{};
				Deserializer(ele, tmp, next);
				o.push_back(ele);
				next = next->NextSiblingElement();
				i++;
			}
		}
		template <typename T>
		void Deserializer(list<T>& o, string nodename, tinyxml2::XMLElement* node) {
			int length{};
			buffer << node->FirstAttribute()->Value();
			buffer >> length;
			buffer.clear();
			o.clear();
			tinyxml2::XMLElement* next = node->FirstChildElement();
			int i = 0;
			for (int m = 0; m < length; m++) {
				T ele{};
				string tmp = "list" + to_string(i);
				Deserializer(ele, tmp, next);
				o.push_back(ele);
				next = next->NextSiblingElement();
				i++;
			}
		}
		template <typename T>
		void Deserializer(set<T>& o, string nodename, tinyxml2::XMLElement* node) {
			int length{};
			buffer << node->FirstAttribute()->Value();
			buffer >> length;
			buffer.clear();
			// o.clear();
			tinyxml2::XMLElement* next = node->FirstChildElement();
			int i = 0;
			for (int m = 0; m < length; m++) {
				T ele{};
				string tmp = "set" + to_string(i);
				Deserializer(ele, tmp, next);
				o.insert(ele);
				next = next->NextSiblingElement();
				i++;
			}
		}
		template <typename T1, typename T2>
		void Deserializer(pair<T1, T2>& o, string nodename, tinyxml2::XMLElement* node) {
			T1 t1{};
			T2 t2{};
			Deserializer(t1, "pair_first", node->FirstChildElement());
			Deserializer(t2, "pair_second", node->FirstChildElement()->NextSiblingElement());
			o = make_pair(t1, t2);
		}
		template <typename T1, typename T2>
		void Deserializer(map<T1, T2>& o, string nodename, tinyxml2::XMLElement* node) {
			int length{};
			buffer << node->FirstAttribute()->Value();
			buffer >> length;
			buffer.clear();
			o.clear();
			tinyxml2::XMLElement* next = node->FirstChildElement();
			for (int m = 0; m < length; m++) {
				T1 t1{};
				T2 t2{};
				Deserializer(t1, "map_pair_first", next->FirstChildElement());
				Deserializer(t2, "map_pair_second", next->FirstChildElement()->NextSiblingElement());
				o.insert(make_pair(t1, t2));
				next = next->NextSiblingElement();
			}
		}
	};
}
#endif // !SER_H
