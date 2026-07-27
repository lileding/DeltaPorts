--- mozglue/misc/Now.cpp.orig
+++ mozglue/misc/Now.cpp
@@ -89,12 +89,20 @@
 }
 
 Maybe<uint64_t> NowIncludingSuspendMs() {
-#  ifndef CLOCK_BOOTTIME
-  return Nothing();
-#  else
+#  ifdef CLOCK_BOOTTIME
   struct timespec ts = {0};
 
   if (clock_gettime(CLOCK_BOOTTIME, &ts)) {
+    return Nothing();
+  }
+  return Some(TimespecToMilliseconds(ts));
+#  else
+  // DragonFly (and other platforms without CLOCK_BOOTTIME) have no clock that
+  // counts suspend time; approximate with CLOCK_MONOTONIC. Desktops rarely
+  // suspend, and returning a value keeps Telemetry / about:support working.
+  struct timespec ts = {0};
+
+  if (clock_gettime(CLOCK_MONOTONIC, &ts)) {
     return Nothing();
   }
   return Some(TimespecToMilliseconds(ts));
