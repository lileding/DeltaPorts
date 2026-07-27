--- mozglue/baseprofiler/core/ProfilerUtils.cpp.orig
+++ mozglue/baseprofiler/core/ProfilerUtils.cpp
@@ -110,6 +110,19 @@
 
 }  // namespace mozilla::baseprofiler
 
+// ------------------------------------------------------- DragonFly
+#  elif defined(__DragonFly__)
+
+#    include <sys/lwp.h>
+
+namespace mozilla::baseprofiler {
+
+BaseProfilerThreadId profiler_current_thread_id() {
+  return BaseProfilerThreadId::FromNativeId(lwp_gettid());
+}
+
+}  // namespace mozilla::baseprofiler
+
 // ------------------------------------------------------- FreeBSD
 #  elif defined(XP_FREEBSD)
 
