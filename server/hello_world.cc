#include <napi.h>
#include "lib/dummylib/dummylib.h"

using namespace Napi;

/*
 * String2String
 *
 * User inputs a string, we return a string.
 */
Napi::String String2String(const Napi::CallbackInfo& info) {
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

/*
 * String2Array
 *
 * User inputs a string, we return an array of float values. (eg to plot)
 */
Napi::Array String2Array(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
      Napi::TypeError::New(env, "Wrong number of arguments")
          .ThrowAsJavaScriptException();
      return Napi::Array::New(env, 0);
    }

    if (!info[0].IsString()) {
      Napi::TypeError::New(env, "Wrong argument, expected a string").ThrowAsJavaScriptException();
      return Napi::Array::New(env, 0);
    }

    // Retrieve command string
    std::string arg0 = info[0].As<Napi::String>().Utf8Value();

    // Do something with the command
    auto lib = new DummyLib();
    std::vector<float> array = lib->makeArray(arg0);

    Napi::Array output = Napi::Array::New(env, array.size());
    for (size_t idx = 0; idx < output.Length(); ++idx) {
        output[idx] = Napi::Number::New(env, array[idx]);
    }
    return output;
}

Napi::String File2String(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
      Napi::TypeError::New(env, "Wrong number of arguments")
          .ThrowAsJavaScriptException();
      return Napi::String::New(env, "");
    }

    if (!info[0].IsArrayBuffer()) {
      Napi::TypeError::New(env, "Wrong argument, expected an array buffer").ThrowAsJavaScriptException();
      return Napi::String::New(env, "");
    }

    // Retrieve command string
    Napi::ArrayBuffer arg0 = info[0].As<Napi::ArrayBuffer>();

    // Do something with the command
    auto lib = new DummyLib();
    std::string output = lib->processArray(reinterpret_cast<uint8_t*>(arg0.Data()), arg0.ByteLength() / sizeof(uint8_t));

    return Napi::String::New(env, output);
}

// This is where we register our functions to be exported by Node-addon-api
Napi::Object Init(Napi::Env env, Napi::Object exports) {
    // This export will be named "String2String"
    exports.Set(Napi::String::New(env, "String2String"),
                Napi::Function::New(env, String2String));
    // This export will be named "String2Array"
    exports.Set(Napi::String::New(env, "String2Array"),
                Napi::Function::New(env, String2Array));
    // This export will be named "File2String"
    exports.Set(Napi::String::New(env, "File2String"),
                Napi::Function::New(env, File2String));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
