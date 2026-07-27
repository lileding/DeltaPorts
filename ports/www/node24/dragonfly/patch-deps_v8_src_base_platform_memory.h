--- deps/v8/src/base/platform/memory.h.orig
+++ deps/v8/src/base/platform/memory.h
@@ -23,11 +23,13 @@
 #include <sys/malloc.h>
 #elif V8_OS_ZOS
 #include <stdlib.h>
+#elif V8_OS_DRAGONFLYBSD
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
 
-#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS && !V8_OS_OPENBSD) || V8_OS_WIN
+#if (V8_OS_POSIX && !V8_OS_AIX && !V8_OS_SOLARIS && !V8_OS_ZOS && !V8_OS_OPENBSD && !V8_OS_DRAGONFLYBSD) || V8_OS_WIN
 #define V8_HAS_MALLOC_USABLE_SIZE 1
 #endif
 
