--- deps/v8/src/base/platform/platform-posix.cc.orig
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -58,6 +58,8 @@
 #include <malloc/malloc.h>
 #elif V8_OS_OPENBSD
 #include <sys/malloc.h>
+#elif V8_OS_DRAGONFLYBSD
+#include <stdlib.h>
 #elif !V8_OS_ZOS
 #include <malloc.h>
 #endif
@@ -155,9 +155,9 @@
   flags |= (page_type == PageType::kShared) ? MAP_SHARED : MAP_PRIVATE;
   if (access == OS::MemoryPermission::kNoAccess ||
       access == OS::MemoryPermission::kNoAccessWillJitLater) {
-#if !V8_OS_AIX && !V8_OS_FREEBSD && !V8_OS_QNX
+#if !V8_OS_AIX && !V8_OS_FREEBSD && !V8_OS_QNX && !V8_OS_DRAGONFLYBSD
     flags |= MAP_NORESERVE;
-#endif  // !V8_OS_AIX && !V8_OS_FREEBSD && !V8_OS_QNX
+#endif  // !V8_OS_AIX && !V8_OS_FREEBSD && !V8_OS_QNX && !V8_OS_DRAGONFLYBSD
 #if V8_OS_QNX
     flags |= MAP_LAZY;
 #endif  // V8_OS_QNX
@@ -1363,7 +1363,7 @@
 // keep this version in POSIX as most Linux-compatible derivatives will
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) && !defined(_AIX) && \
-    !defined(V8_OS_SOLARIS)
+    !defined(V8_OS_SOLARIS) && !defined(V8_OS_DRAGONFLYBSD)
 
 namespace {
 #if DEBUG
