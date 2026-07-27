--- src/gst/gstpipewiresrc.c.orig
+++ src/gst/gstpipewiresrc.c
@@ -198,7 +198,7 @@
       pwsrc->on_disconnect = g_value_get_enum (value);
       break;
 
-    case PROP_PROVIDE_CLOCK:
+    case PROP_PROVIDE_CLOCK:;
       gboolean provide = g_value_get_boolean (value);
       GST_OBJECT_LOCK (pwsrc);
       if (provide)
@@ -277,7 +277,7 @@
       g_value_set_enum (value, pwsrc->on_disconnect);
       break;
 
-    case PROP_PROVIDE_CLOCK:
+    case PROP_PROVIDE_CLOCK:;
       gboolean result;
       GST_OBJECT_LOCK (pwsrc);
       result = GST_OBJECT_FLAG_IS_SET (pwsrc, GST_ELEMENT_FLAG_PROVIDE_CLOCK);
