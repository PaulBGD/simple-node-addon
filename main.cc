#include <node.h>

namespace Main {

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Hello World from c++!"));
}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "getHelloWorld", Method);
}

NODE_MODULE(addon, init)

}

