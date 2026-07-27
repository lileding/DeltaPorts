--- tools/profiler/core/platform.cpp.orig
+++ tools/profiler/core/platform.cpp
@@ -217,8 +217,9 @@
 #if defined(GP_PLAT_amd64_linux) || defined(GP_PLAT_x86_linux) ||       \
     defined(GP_PLAT_amd64_android) || defined(GP_PLAT_x86_android) ||   \
     defined(GP_PLAT_mips64_linux) || defined(GP_PLAT_arm64_linux) ||    \
-    defined(GP_PLAT_arm64_android) || defined(GP_PLAT_amd64_freebsd) || \
-    defined(GP_PLAT_arm64_freebsd)
+    defined(GP_PLAT_arm64_android) ||                                  \
+    ((defined(GP_PLAT_amd64_freebsd) || defined(GP_PLAT_arm64_freebsd)) && \
+     !defined(__DragonFly__))
 #  define HAVE_NATIVE_UNWIND
 #  define USE_LUL_STACKWALK
 #  include "lul/LulMain.h"
