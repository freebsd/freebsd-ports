#include <napi.h>

#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/user.h>

#include <cerrno>
#include <cstring>
#include <vector>

Napi::Value getWorkingDirectoryFromPID(const Napi::CallbackInfo& info) {
  auto env = info.Env();
  auto pid = static_cast<int>(info[0].ToNumber().Int64Value());

  int mib[4] = { CTL_KERN, KERN_PROC, KERN_PROC_CWD, pid };
  size_t len = 0;

  if (sysctl(mib, 4, nullptr, &len, nullptr, 0) < 0) {
    auto err = errno;
    auto error = Napi::Error::New(env, strerror(err));
    error.Set("errno", Napi::Number::New(env, err));
    error.ThrowAsJavaScriptException();
    return env.Null();
  }

  if (len == 0) {
    return env.Null();
  }

  std::vector<char> buf(len + sizeof(struct kinfo_file));
  len = buf.size();

  if (sysctl(mib, 4, buf.data(), &len, nullptr, 0) < 0) {
    auto err = errno;
    auto error = Napi::Error::New(env, strerror(err));
    error.Set("errno", Napi::Number::New(env, err));
    error.ThrowAsJavaScriptException();
    return env.Null();
  }

  if (len < sizeof(struct kinfo_file)) {
    return env.Null();
  }

  auto* kf = reinterpret_cast<struct kinfo_file*>(buf.data());
  if (kf->kf_structsize == 0 || kf->kf_path[0] == '\0') {
    return env.Null();
  }

  return Napi::String::New(env, kf->kf_path);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("getWorkingDirectoryFromPID", Napi::Function::New(env, getWorkingDirectoryFromPID));
  return exports;
}

NODE_API_MODULE(addon, Init)
