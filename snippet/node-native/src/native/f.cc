#include <node_api.h>
// 实际暴露的方法，这里只是简单返回一个字符串
napi_value f(napi_env env, napi_callback_info info) {
    napi_value str;
    napi_create_string_utf8(env, "world", 5, &str);
    return str;
}

napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, nullptr, 0, f, nullptr, &fn);
  if (status != napi_ok) return nullptr;

  status = napi_set_named_property(env, exports, "f", fn);
  if (status != napi_ok) return nullptr;
  return exports;
}

NAPI_MODULE(f, init);  