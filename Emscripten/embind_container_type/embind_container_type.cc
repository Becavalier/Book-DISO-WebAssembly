#include <emscripten/bind.h>
#include <string>
#include <vector>

using namespace std;
using namespace emscripten;

class xClass {
public:
	// 构造方法；
	xClass (int x, string y): x(x), y(y) {}

	// 使用 Vector 向量容器；
	vector<int> returnVectorData () {
		vector<int> v(10, x);
		return v;
	}

	// 使用 Map 字典容器；
	map<int, string> returnMapData () {
		map<int, string> m;
    m.insert(pair<int, string>(x, y));
    return m;
	}

private:
	int x;
	string y;
};

EMSCRIPTEN_BINDINGS(module) {
	class_<xClass>("xClass")
		.constructor<int, string>()
		.function("returnVectorData", &xClass::returnVectorData)
		.function("returnMapData", &xClass::returnMapData);
  // 注册在代码中使用到的容器类型；
	register_vector<int>("vector<int>");
	register_map<int, string>("map<int, string>");
}