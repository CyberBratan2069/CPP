//  file main_mp4_OO_b.cpp
#include <iostream>
#include <cassert>

//=======================================


struct ValueType {
  ValueType(int initialValue=0);
  ~ValueType();
private:
  int _someValue;
};

class BaseEntity {
  ValueType _value;
public:
  BaseEntity();
  BaseEntity(int initialValue);
  virtual ~BaseEntity();
};

class DerivedEntity : public BaseEntity {
public:
  DerivedEntity();
  ~DerivedEntity();
};

ValueType::ValueType(int initialValue)
: _someValue(initialValue)
{
  std::cout << "ValueType::ValueType(" << _someValue << ")" << std::endl;
}

ValueType::~ValueType(){
  std::cout << "ValueType::~ValueType()" << std::endl;
}

BaseEntity::BaseEntity()
: _value(0)
{
  std::cout << "BaseEntity::BaseEntity()" << std::endl;
}

BaseEntity::BaseEntity(int initialValue)
: _value(initialValue)
{
  std::cout << "BaseEntity::BaseEntity(int)" << std::endl;
}

BaseEntity::~BaseEntity(){
  std::cout << "BaseEntity::~BaseEntity(" << std::endl;
}

DerivedEntity::DerivedEntity()
: BaseEntity(17)
{
  std::cout << "DerivedEntity::DerivedEntity()" << std::endl;
}

DerivedEntity::~DerivedEntity(){
  std::cout << "DerivedEntity::~DerivedEntity()" << std::endl;
}


class Bar {
  BaseEntity *_helperObject;
public:
  Bar();
  ~Bar();
};

Bar::Bar(){
  _helperObject =  new DerivedEntity();
}

Bar::~Bar(){
  delete _helperObject;
}


int main(/*int argc, const char * argv[]*/) {
  Bar * bar = new Bar();
  // ...
  delete bar; // implies "delete _helperObject";

  BaseEntity *obj = new DerivedEntity();
  delete obj;


  return 0;
}



