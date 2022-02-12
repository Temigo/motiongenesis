#include <napi.h>
#include "lib/dummylib/dummylib.h"

using namespace Napi;

Napi::String Method(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
      Napi::TypeError::New(env, "Wrong number of arguments")
          .ThrowAsJavaScriptException();
      return Napi::String::New(env, "");
    }

    if (!info[0].IsString()) {
      Napi::TypeError::New(env, "Wrong argument, expected a string").ThrowAsJavaScriptException();
      return Napi::String::New(env, "");
    }

    // Retrieve command string
    std::string arg0 = info[0].As<Napi::String>().Utf8Value();

    // Do something with the command
    auto lib = new DummyLib();
    std::string output = lib->process(arg0);

    return Napi::String::New(env, output);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    // The export will be named HelloWorld
    exports.Set(Napi::String::New(env, "HelloWorld"),
                Napi::Function::New(env, Method));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
