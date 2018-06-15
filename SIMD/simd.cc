#include <iostream>

using namespace std;
// 定义向量类型，“v4sf”为包含4个单精度浮点数的数据向量；
typedef float v4sf __attribute__ ((vector_size (16)));
// 定义“Matrix”类；	
class Matrix {
    public:
        // 利用友元函数重载运算符“<<”；
        friend ostream& operator<<(ostream& os, const Matrix& dt);
        void setData (v4sf v) {
            this->data = v;
        }
        v4sf getData () const {
            return this->data;
        }
    private:
        v4sf data;
};

ostream& operator<<(ostream& os, const Matrix& dt) {
    v4sf _t = dt.getData();
    os << _t[0] << " "
       << _t[1] << " "
       << _t[2] << " "
       << _t[3];
    return os;
}

int main () {
    // 声明并初始化一些“v4sf”类型的向量数据；
    v4sf a = {1.0, 2.0, 3.0, 4.0};
    v4sf b = {2.0, 3.0, 4.0, 5.0};
    v4sf c = a + b;
    // 调用编译器内置的向量数据处理方法，这些方法会直接调用对应CPU的底层SSE／MMX指令；

    v4sf d = __builtin_ia32_sqrtps(c);

    Matrix m1, m2;
    m1.setData(c);
    m2.setData(d);
    // 打印“Matrix”类中的向量数据；
    cout << endl 
            << m1 << endl 
            << m2 << endl
            << endl;
}
