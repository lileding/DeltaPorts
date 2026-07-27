--- deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h.orig
+++ deps/v8/third_party/abseil-cpp/absl/debugging/internal/elf_mem_image.h
@@ -33,6 +33,7 @@
 #endif
 
 #if defined(__ELF__) && !defined(__OpenBSD__) && !defined(__QNX__) && \
+    !defined(__DragonFly__) &&                                        \
     !defined(__native_client__) && !defined(__asmjs__) &&             \
     !defined(__wasm__) && !defined(__HAIKU__) && !defined(__sun) &&   \
     !defined(__VXWORKS__) && !defined(__hexagon__) && !defined(__XTENSA__)
