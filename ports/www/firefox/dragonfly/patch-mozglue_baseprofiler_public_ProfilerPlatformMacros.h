--- mozglue/baseprofiler/public/ProfilerPlatformMacros.h.orig
+++ mozglue/baseprofiler/public/ProfilerPlatformMacros.h
@@ -103,7 +103,7 @@
 #  define GP_ARCH_amd64 1
 #  define GP_OS_darwin 1
 
-#elif defined(__FreeBSD__) && defined(__x86_64__)
+#elif (defined(__FreeBSD__) || defined(__DragonFly__)) && defined(__x86_64__)
 #  define GP_PLAT_amd64_freebsd 1
 #  define GP_ARCH_amd64 1
 #  define GP_OS_freebsd 1
