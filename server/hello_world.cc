#include <napi.h>

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
    if (arg0 == "hello") {
        return Napi::String::New(env, "world");
    } else {
        return Napi::String::New(env, "You said, I quote: " + arg0);
    }
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    // The export will be named HelloWorld
    exports.Set(Napi::String::New(env, "HelloWorld"),
                Napi::Function::New(env, Method));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
