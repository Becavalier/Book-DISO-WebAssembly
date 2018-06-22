enum xEnum {
  enum_val1,
  enum_val2
};

namespace WebAssembly {
  enum yEnum {
    ns_enum_val1 = 10,
  	ns_enum_val2
  };
};

class xClass {
public:
	xClass(int x) : x(x) {}
  enum zEnum {
  	c_enum_val1 = 20,
  	c_enum_val2
  };
private:
	int x;
};

typedef WebAssembly::yEnum WebAssembly_yEnum;
typedef xClass::zEnum xClass_zEnum;
