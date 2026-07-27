--- src/lib/ini.c.orig
+++ src/lib/ini.c
@@ -90,7 +90,7 @@
 /* Version of strncpy that ensures dest (size bytes) is null-terminated. */
 static char* strncpy0(char* dest, const char* src, size_t size)
 {
-    strncpy(dest, src, size);
+    strncpy(dest, src, size - 1);
     dest[size - 1] = '\0';
     return dest;
 }
