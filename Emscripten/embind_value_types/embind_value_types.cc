#include <emscripten/bind.h>
#include <string>

using namespace emscripten;
// 定义两个结构体；
struct Point2f {
	int x;
	int y;
};

struct PersonRecord {
	std::string name;
	int age;
};

// 将会绑定到 JavaScript 环境的方法，该方法在内部用到了之前定义的两种结构体类型；
PersonRecord findPersonAtLocation(Point2f &p) {
	PersonRecord pr;
	if (p.x == 0 && p.y == 0) {
		pr = {"YHSPY", 25};
	} else {
		pr = {"anonymous", -1};
	}
	return pr;
}

// 绑定 C/C++ 内的结构体与 JavaScript 环境的对象与数组类型；
EMSCRIPTEN_BINDINGS(module) {
	// 绑定数组，定义结构体与数组的转换规则；
  value_array<Point2f>("Point2f")
    .element(&Point2f::x)
    .element(&Point2f::y);
  // 绑定对象，定义结构体与对象的转换规则；
  value_object<PersonRecord>("PersonRecord")
    .field("name", &PersonRecord::name)
    .field("age", &PersonRecord::age);
  // 绑定函数；
  function("findPersonAtLocation", &findPersonAtLocation);
}