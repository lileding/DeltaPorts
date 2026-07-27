--- utils/dvb/dvbv5-daemon.c.orig
+++ utils/dvb/dvbv5-daemon.c
@@ -23,6 +23,9 @@
 #  if __FreeBSD_version < 1500505 || (__FreeBSD_version >= 1600000 && __FreeBSD_version < 1600008)
 #    define tdestroy(...) do {} while (0)
 #  endif
+#elif defined(__DragonFly__)
+/* DragonFly libc has no tdestroy() */
+#  define tdestroy(...) do {} while (0)
 #else
 #  define _XOPEN_SOURCE 600
 #endif
