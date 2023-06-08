#pragma once

class nodeB {
private:
	int* values;
	bool leaf;
	nodeB** childs;
	int number; 
	int grade;
public:
	nodeB(int _grado, bool _hoja);
	~nodeB();

	void divideChild(int _value, nodeB*& _node);
	bool insertValue(int _value);
	
	int getValue(int _index);
	void setValue(int _index, int _value);
	void setNumber(int _value);
	int getNumber();
	void setChild(int _index, nodeB*& _child);
	nodeB *&getChild(int _index);
	int getGrade();
	bool getLeaf();
};

