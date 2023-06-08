#include "nodoB.h";

nodeB::nodeB(int _grado, bool _hoja)
{
	this->grade = _grado;
	this->leaf = _hoja;

	this->values = new int[2 * grade - 1];
	this->childs = new nodeB* [2 * grade];

	this->number = 0;
}

int nodeB::getValue(int _index)
{
	return this->values[_index];
}

void nodeB::setValue(int _index, int _value)
{
	this->values[_index] = _value;
}

void nodeB::setNumber(int _value)
{
	this->number = _value;
}

int nodeB::getNumber()
{
	return this->number;
}

void nodeB::setChild(int _index, nodeB*& _child)
{
	this->childs[_index] = _child;
}

nodeB*& nodeB::getChild(int _index)
{
	return this->childs[_index];
}

int nodeB::getGrade()
{
	return this->grade;
}

bool nodeB::getLeaf()
{
	return this->leaf;
}

void nodeB::divideChild(int _index, nodeB*& _node)
{
	nodeB* aux = new nodeB(_node->getGrade(), _node->getLeaf());
	aux->setNumber(this->getGrade() - 1);

	for (int j = 0; j < this->getGrade() - 1; j++) {
		aux->setValue(j, _node->getValue(j + this->grade));
	}

	if (!_node->getLeaf()) {
		for (int j = 0; j < this->getGrade(); j++) {
			aux->setChild(j, _node->getChild(j + this->grade));
		}
	}

	_node->setNumber(this->getGrade() - 1);
	for (int j = this->number; j >= _index + 1; j--) {
		this->setChild(j + 1, this->getChild(j));
	}

	this->setChild(_index + 1, aux);

	for (int j = this->number - 1; j >= _index; j--) {
		this->setValue(j + 1, getValue(j));
	}

	this->setValue(_index, _node->getValue(this->getGrade() - 1));

	this->setNumber(this->getNumber() + 1);
}

bool nodeB::insertValue(int _value)
{
	int i = this->getNumber() - 1;
	if (this->getLeaf()) {
		while (i >= 0 && this->getValue(i) > _value) {
			this->setValue(i + 1, this->getValue(i));
			i--;
		}

		this->setValue(i + 1, _value);
		this->setNumber(this->getNumber() + 1);
		return true;
	}
	else {
		while (i >= 0 && this->getValue(i) > _value) {
			i--;
		}

		if (this->getChild(i + 1)->getNumber() == 2 * this->grade - 1) {
			this->divideChild(i + 1, this->getChild(i + 1));
			if (this->getValue(i + 1) < _value) {
				i++;
			}
		}
		this->getChild(i + 1)->insertValue(_value);
	}
}
