--- third_party/abseil-cpp/absl/base/config.h.orig
+++ third_party/abseil-cpp/absl/base/config.h
@@ -372,7 +372,7 @@
 // POSIX.1-2001.
 #ifdef ABSL_HAVE_MMAP
 #error ABSL_HAVE_MMAP cannot be directly set
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||    \
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) ||    \
     defined(_AIX) || defined(__ros__) || defined(__native_client__) ||       \
     defined(__asmjs__) || defined(__EMSCRIPTEN__) || defined(__Fuchsia__) || \
     defined(__sun) || defined(__myriad2__) || defined(__HAIKU__) ||          \
@@ -387,7 +387,7 @@
 // functions as defined in POSIX.1-2001.
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
-#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+#elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__) || \
     defined(_AIX) || defined(__ros__) || defined(__OpenBSD__) ||          \
     defined(__NetBSD__) || defined(__VXWORKS__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
