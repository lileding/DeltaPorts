--- tools/profiler/core/platform-linux-android.cpp.orig
+++ tools/profiler/core/platform-linux-android.cpp
@@ -32,7 +32,7 @@
 #include <math.h>
 
 #include <pthread.h>
-#if defined(GP_OS_freebsd)
+#if defined(GP_OS_freebsd) && !defined(__DragonFly__)
 #  include <sys/thr.h>
 #endif
 #include <semaphore.h>
@@ -128,7 +128,10 @@
 }
 #endif
 
-#if defined(GP_OS_freebsd)
+#if defined(__DragonFly__)
+#  include <sys/lwp.h>
+#  define tgkill(tgid, tid, sig) lwp_kill((tgid), (tid), (sig))
+#elif defined(GP_OS_freebsd)
 #  define tgkill thr_kill2
 #endif
 
