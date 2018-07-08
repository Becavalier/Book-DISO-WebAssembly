// 引入PPAPI库头文件；
#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/var.h"
#include "ppapi/cpp/var_dictionary.h"

namespace {
  // 定义将要从 PNaCl 发送到浏览器端到字符串常量；
  const char* kReplyString = "Hello, this is PNaCl!";
}

class HelloTutorialInstance : public pp::Instance {
 public:
  explicit HelloTutorialInstance(PP_Instance instance) : pp::Instance(instance)
  {}
  virtual ~HelloTutorialInstance() {}

  // 从浏览器端发送过来的数据会首先经过 HandleMessage 函数的处理；
  virtual void HandleMessage(const pp::Var& var_message) {
    // 处理从浏览器传送过来的数据；
    if (!var_message.is_number())
      return;
           // 通过 Pepper API 处理从JavaScript环境传递过来的消息；
    int message = var_message.AsInt();
    pp::VarDictionary var_dict;
    // 构造一个字典对象；
    var_dict.Set(pp::Var("echo"), pp::Var(kReplyString));
    var_dict.Set(pp::Var("result"), pp::Var(this->fib(message)));
    // 通过 PostMessaage 方法将数据返回给浏览器；
    PostMessage(var_dict);
  }
 private:
  // 计算斐波那契数列的前几项和；
  int fib (int x) {
    if (x < 2) {
      return 1;
    } else {
      return fib(x - 1) + fib(x - 2);
    }
  }
};

// 浏览器会检查 HTML 页面中所有用于声明PNaCl应用的“ <embed>” 标签；
// 每一个有效的标签都会生成一个与之对应的“pp::Module”对象；
class HelloTutorialModule : public pp::Module {
 public:
  HelloTutorialModule() : pp::Module() {}
  virtual ~HelloTutorialModule() {}
  // 模块初始化后会调用该类的 CreateInstance 方法来创建一个模块实例；
  virtual pp::Instance* CreateInstance(PP_Instance instance) {
    return new HelloTutorialInstance(instance);
  }
};

namespace pp {
  // PNaCl 模块第一次加载时调用的工厂方法；
  Module* CreateModule() {
    return new HelloTutorialModule();
  }
}
