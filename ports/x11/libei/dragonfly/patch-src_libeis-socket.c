--- src/libeis-socket.c.orig
+++ src/libeis-socket.c
@@ -41,9 +41,17 @@
 #include "libeis.h"
 #include "libeis-private.h"
 
-#if defined(__DragonFly__) || defined(__FreeBSD__)
+#if defined(__DragonFly__)
+/* DragonFly has LOCAL_PEERCRED but no SOL_LOCAL define (the level is 0)
+ * and struct xucred carries no pid. */
 #include <sys/ucred.h>
 #define CRED_T   xucred
+#define CRED_LVL 0
+#define CRED_OPT LOCAL_PEERCRED
+#define CRED_NO_PID 1
+#elif defined(__FreeBSD__)
+#include <sys/ucred.h>
+#define CRED_T   xucred
 #define CRED_LVL SOL_LOCAL
 #define CRED_OPT LOCAL_PEERCRED
 #define CRED_PID cr_pid
@@ -217,5 +225,9 @@
 	if (rc < 0) {
 		return -errno;
 	}
+#ifdef CRED_NO_PID
+	return 0;
+#else
 	return ucred.CRED_PID;
+#endif
 }
