#include "Binary_Serialization.h"
#include "Xml_Serialization.h"
#include "Serialization.h"
#include <fstream>
#include <iostream>
using namespace std;
// Xml_Serialization::xml_ser xml_serMethod();
class User_Defined_Object {
public:
	User_Defined_Object(int idx_ = 1, string name_ = "Jack", vector<double> data_ = { 0,1,3.5,4 }) {
		idx = idx_;
		name = name_;
		data = data_;
	}
	inline void print() {
		cout << idx << " " << name << " ";
		for (auto iter = data.begin(); iter != data.end(); iter++) {
			cout << (*iter) << " ";
		}
		cout << endl;
	}
	int idx;
	string name;
	vector<double> data;
}UserDef;
int main() {
	{
		// Test binary serialization
		cout << "------------------Test Binary Serialization and Deserialization-----------------" << endl;
		// test string
		cout << "------Test arithmetic type or string type---------" << endl;
		string objstring;
		string t = "abcdefg";
		ofstream outString("./out/String_Binary_Ser.data");
		if (outString.is_open()) {
			Binary_Serialization::Serializer(t, outString);
			outString.close();
		}
		ifstream inString("./out/String_Binary_Ser.data");
		if (inString.is_open()) {
			Binary_Deserialization::Deserializer(objstring, inString);
			inString.close();
			cout << objstring << endl;
		}
		// test vector
		cout << "----------------Test vector-----------------------" << endl;
		vector<int> IntV = { 1, 2, 3, 4, 5 };
		vector<int> Vobj;
		ofstream outVector("./out/Vector_Binary_Ser.data");
		if (outVector.is_open()) {
			Binary_Serialization::Serializer(IntV, outVector);
			outVector.close();
		}
		ifstream inVector("./out/Vector_Binary_Ser.data");
		if (inVector.is_open()) {
			Binary_Deserialization::Deserializer(Vobj, inVector);
			inVector.close();
			for (auto iter = Vobj.begin(); iter != Vobj.end(); iter++) {
				cout << (*iter) << " ";
			}
			cout << endl;
		}
		// test list
		cout << "----------------Test list-------------------------" << endl;
		list<double> DL = { 1.1, 2.2, 3.3 };
		list<double> Lobj;
		ofstream outList("./out/List_Binary_Ser.data");
		if (outList.is_open()) {
			Binary_Serialization::Serializer(DL, outList);
			outList.close();
		}
		ifstream inList("./out/List_Binary_Ser.data");
		if (inList.is_open()) {
			Binary_Deserialization::Deserializer(Lobj, inList);
			inList.close();
			for (auto iter = Lobj.begin(); iter != Lobj.end(); iter++) {
				cout << (*iter) << " ";
			}
			cout << endl;
		}
		// test set
		cout << "----------------Test set-------------------------" << endl;
		set<string> CharS = { "a", "b", "cc", "sd", "we" };
		set<string> Cobj;
		ofstream outChar("./out/Set_Binary_Ser.data");
		if (outChar.is_open()) {
			Binary_Serialization::Serializer(CharS, outChar);
			outChar.close();
		}
		ifstream inChar("./out/Set_Binary_Ser.data");
		if (inChar.is_open()) {
			Binary_Deserialization::Deserializer(Cobj, inChar);
			inChar.close();
			for (auto iter = Cobj.begin(); iter != Cobj.end(); iter++) {
				cout << (*iter) << " ";
			}
			cout << endl;
		}
		// test map
		cout << "----------------Test map--------------------------" << endl;
		map<int, string> M = { {1, "abc"}, {2, "bcs"} };
		map<int, string> Mobj;
		ofstream outMap("./out/Map_Binary_Ser.data");
		if (outMap.is_open()) {
			Binary_Serialization::Serializer(M, outMap);
			outMap.close();
		}
		ifstream inMap("./out/Map_Binary_Ser.data");
		if (inMap.is_open()) {
			Binary_Deserialization::Deserializer(Mobj, inMap);
			inMap.close();
			for (auto iter = Mobj.begin(); iter != Mobj.end(); iter++) {
				cout << (*iter).first << "," << (*iter).second << " ";
			}
			cout << endl;
		}
		// User_Defined_Object
		cout << "----------Test User_Defined_Object----------------" << endl;
		{
			ofstream outUser_Defined("./out/UserDefined_Binary_Ser.data");
			if (outUser_Defined.is_open()) {
				Binary_Serialization::Serializer(UserDef.idx, outUser_Defined);
				Binary_Serialization::Serializer(UserDef.name, outUser_Defined);
				Binary_Serialization::Serializer(UserDef.data, outUser_Defined);
				outUser_Defined.close();
			}
			ifstream inUser_Defined("./out/UserDefined_Binary_Ser.data");
			User_Defined_Object UserDefNew;
			if (inUser_Defined.is_open()) {
				Binary_Deserialization::Deserializer(UserDefNew.idx, inUser_Defined);
				Binary_Deserialization::Deserializer(UserDefNew.name, inUser_Defined);
				Binary_Deserialization::Deserializer(UserDefNew.data, inUser_Defined);
				inUser_Defined.close();
				UserDefNew.print();
			}
		}
	}
	{
		cout << "------------------Test XML Serialization and Deserialization-----------------" << endl;
		cout << "------Test arithmetic type or string type---------" << endl;
		string objstring;
		string t = "abcdefg";
		Serialization::Serialization(t, "string", "./out/String_Xml_Ser.txt");
		Deserialization::Deserialization(objstring, "string", "./out/String_Xml_Ser.txt");

		cout << objstring << endl;
		cout << "----------------Test vector-----------------------" << endl;
		vector<int> IntV = { 1, 2, 3, 4, 5 };
		vector<int> Vobj;
		Serialization::Serialization(IntV, "vector", "./out/Vector_Xml_Ser.txt");
		Deserialization::Deserialization(Vobj, "vector", "./out/Vector_Xml_Ser.txt");
		for (auto iter = Vobj.begin(); iter != Vobj.end(); iter++) {
			cout << (*iter) << " ";
		}
		cout << endl;
		cout << "----------------Test list-------------------------" << endl;
		list<double> DL = { 1.1, 2.2, 3.3 };
		list<double> Lobj;
		Serialization::Serialization(DL, "list", "./out/List_Xml_Ser.txt");
		Deserialization::Deserialization(Lobj, "list", "./out/List_Xml_Ser.txt");
		for (auto iter = Lobj.begin(); iter != Lobj.end(); iter++) {
			cout << (*iter) << " ";
		}
		cout << endl;
		cout << "----------------Test set-------------------------" << endl;
		set<string> CharS = { "a", "b", "cc", "sd", "we"};
		set<string> Cobj;
		Serialization::Serialization(CharS, "set", "./out/Set_Xml_Ser.txt");
		Deserialization::Deserialization(Cobj, "set", "./out/Set_Xml_Ser.txt");
		for (auto iter = Cobj.begin(); iter != Cobj.end(); iter++) {
			cout << (*iter) << " ";
		}
		cout << endl;
		cout << "----------------Test map--------------------------" << endl;
		map<int, string> M = { {1, "abc"}, {2, "bcs"} };
		map<int, string> Mobj;
		Serialization::Serialization(M, "map", "./out/Set_Xml_Ser.txt");
		Deserialization::Deserialization(Mobj, "map", "./out/Set_Xml_Ser.txt");
		for (auto iter = Mobj.begin(); iter != Mobj.end(); iter++) {
			cout << (*iter).first << "," << (*iter).second << " ";
		}
		cout << endl;
		cout << "----------Test User_Defined_Object----------------" << endl;
		{
			User_Defined_Object newObj;
			Serialization::Serialization(UserDef.idx, "int", "./out/UserDefined_Xml_Ser_idx.txt");
			Serialization::Serialization(UserDef.name, "string", "./out/UserDefined_Xml_Ser_name.txt");
			Serialization::Serialization(UserDef.data, "vector", "./out/UserDefined_Xml_Ser_data.txt");
			
			Deserialization::Deserialization(newObj.idx, "int", "./out/UserDefined_Xml_Ser_idx.txt");
			Deserialization::Deserialization(newObj.name, "string", "./out/UserDefined_Xml_Ser_name.txt");
			Deserialization::Deserialization(newObj.data, "vector", "./out/UserDefined_Xml_Ser_data.txt");
			newObj.print();
		}
	}
	return 0;
}