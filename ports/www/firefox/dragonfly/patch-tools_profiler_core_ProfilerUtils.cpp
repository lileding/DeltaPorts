--- tools/profiler/core/ProfilerUtils.cpp.orig
+++ tools/profiler/core/ProfilerUtils.cpp
@@ -73,6 +73,15 @@
   return ProfilerThreadId::FromNativeId(tid);
 }
 
+// ------------------------------------------------------- DragonFly
+#  elif defined(__DragonFly__)
+
+#    include <sys/lwp.h>
+
+ProfilerThreadId profiler_current_thread_id() {
+  return ProfilerThreadId::FromNativeId(lwp_gettid());
+}
+
 // ------------------------------------------------------- FreeBSD
 #  elif defined(XP_FREEBSD)
 
