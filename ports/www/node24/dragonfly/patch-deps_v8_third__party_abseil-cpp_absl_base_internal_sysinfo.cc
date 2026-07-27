--- deps/v8/third_party/abseil-cpp/absl/base/internal/sysinfo.cc.orig
+++ deps/v8/third_party/abseil-cpp/absl/base/internal/sysinfo.cc
@@ -448,6 +448,10 @@
 
 pid_t GetTID() { return static_cast<pid_t>(pthread_getthreadid_np()); }
 
+#elif defined(__DragonFly__)
+
+pid_t GetTID() { return static_cast<pid_t>(lwp_gettid()); }
+
 #elif defined(__OpenBSD__)
 
 pid_t GetTID() { return getthrid(); }
