#ifndef BINARY_SERIALIZATION_H
#define BINARY_SERIALIZATION_H
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <fstream>
using namespace std;
namespace Binary_Serialization {
	template <typename T>
	void Serializer(const vector<T>& o, ostream &out);
	template <typename T>
	void Serializer(const list<T>& o, ostream& out);
	template <typename T>
	void Serializer(const set<T>& o, ostream& out);
	template <typename T1, typename T2>
	void Serializer(const map<T1, T2>& o, ostream& out);
	template <typename T1, typename T2>
	void Serializer(const pair<T1, T2>& o, ostream& out);
	template <typename T>
	typename enable_if<is_arithmetic<T>::value || is_same<T, string>::value >::type Serializer(const T& o, ostream& out);

	template <typename T>
	typename enable_if<is_arithmetic<T>::value || is_same<T, string>::value >::type Serializer(const T& o, ostream& out) {
		out << o << " "; // write directly to file
	}

	template <typename T>
	void Serializer(const vector<T>& o, ostream &out) {
		out << o.size() << " ";
		for (auto iter = o.begin(); iter != o.end(); iter++) {
			Serializer((*iter), out);
		}
	}
	template <typename T>
	void Serializer(const list<T>& o, ostream& out) {
		out << o.size() << " ";
		for (auto iter = o.begin(); iter != o.end(); iter++) {
			Serializer((*iter), out);
		}
	}
	template <typename T>
	void Serializer(const set<T>& o, ostream& out) {
		out << o.size() << " ";
		for (auto iter = o.begin(); iter != o.end(); iter++) {
			Serializer((*iter), out);
		}
	}
	template <typename T1, typename T2>
	void Serializer(const map<T1, T2>& o, ostream& out) {
		out << o.size() << " ";
		for (auto iter = o.begin(); iter != o.end(); iter++) {
			Serializer<T1, T2>(*iter, out);
		}
	}
	template <typename T1, typename T2>
	void Serializer(const pair<T1, T2>& o, ostream& out) {
		Serializer<T1>(o.first, out);
		Serializer<T2>(o.second, out);
	}
}
namespace Binary_Deserialization {
	template <typename T>
	void Deserializer(vector<T>& o, istream& in);
	template <typename T>
	void Deserializer(list<T>& o, istream& in);
	template <typename T>
	void Deserializer(set<T>& o, istream& in);
	template <typename T1, typename T2>
	void Deserializer(map<T1, T2>& o, istream& in);
	template <typename T1, typename T2>
	void Deserializer(pair<T1, T2>& o, istream& in);
	template <typename T>
	typename enable_if<is_arithmetic<T>::value || is_same<T, string>::value >::type Deserializer(T& o, istream& in);

	template <typename T>
	void Deserializer<T>(vector<T>& o, istream& in) {
		int length{};
		in >> length; // read the size of the vector
		o.clear();
		for (int i = 0; i < length; i++) {
			T tmp{};
			Deserializer(tmp, in);
			o.push_back(tmp);
		}
	}
	template <typename T>
	void Deserializer<T>(list<T>& o, istream& in) {
		int length{};
		in >> length; // read the size of the list
		o.clear();
		for (int i = 0; i < length; i++) {
			T tmp{};
			Deserializer(tmp, in);
			o.push_back(tmp);
		}
		
	}
	template <typename T>
	void Deserializer<T>(set<T>& o, istream& in) {
		int length{};
		in >> length; // read the size of the set
		for (int i = 0; i < length; i++) {
			T tmp{};
			Deserializer(tmp, in);
			o.insert(tmp);
		}
	}
	template <typename T1, typename T2>
	void Deserializer<T1, T2>(map<T1, T2>& o, istream& in) {
		int length{};
		in >> length; // read the size of the map
		for (int i = 0; i < length; i++) {
			T1 tmp1{};
			T2 tmp2{};
			Deserializer(tmp1, in);
			Deserializer(tmp2, in);
			o.insert(make_pair(tmp1, tmp2));
		}
	}
	template <typename T1, typename T2>
	void Deserializer(pair<T1, T2>& o, istream& in) {
		T1 tmp1{};
		T2 tmp2{};
		Deserializer(tmp1, in);
		Deserializer(tmp2, in);
		o = make_pair(tmp1, tmp2);
	}

	template <typename T>
	typename enable_if<is_arithmetic<T>::value || is_same<T, string>::value >::type Deserializer(T& o, istream& in) {
		in >> o;
	}
}

#endif
