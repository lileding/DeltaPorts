--- mozglue/baseprofiler/public/BaseProfilerUtils.h.orig
+++ mozglue/baseprofiler/public/BaseProfilerUtils.h
@@ -57,8 +57,8 @@
 using ThreadIdType = long;
 }  // namespace mozilla::baseprofiler::detail
 
-// ------------------------------------------------------- FreeBSD
-#  elif defined(XP_FREEBSD)
+// ------------------------------------------------------- FreeBSD / DragonFly
+#  elif defined(XP_FREEBSD) || defined(__DragonFly__)
 
 namespace mozilla::baseprofiler::detail {
 using ThreadIdType = long;
