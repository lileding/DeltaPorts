--- ipc/glue/SharedMemoryPlatform_posix.cpp.orig
+++ ipc/glue/SharedMemoryPlatform_posix.cpp
@@ -446,7 +446,7 @@
 }
 
 void* Platform::FindFreeAddressSpace(size_t aSize) {
-#ifndef __FreeBSD__
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
   constexpr int flags = MAP_ANONYMOUS | MAP_NORESERVE | MAP_PRIVATE;
 #else
   constexpr int flags = MAP_ANONYMOUS | MAP_PRIVATE;
