--- deps/v8/src/base/platform/platform-freebsd.cc.orig
+++ deps/v8/src/base/platform/platform-freebsd.cc
@@ -49,6 +49,7 @@
 
 std::vector<OS::SharedLibraryAddress> OS::GetSharedLibraryAddresses() {
   std::vector<SharedLibraryAddress> result;
+#if !defined(__DragonFly__)
   int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_VMMAP, getpid()};
   size_t miblen = sizeof(mib) / sizeof(mib[0]);
   size_t buffer_size;
@@ -90,6 +91,7 @@
       }
     }
   }
+#endif  // !__DragonFly__
   return result;
 }
 
