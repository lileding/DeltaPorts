--- third_party/rust/mtu/build.rs.orig
+++ third_party/rust/mtu/build.rs
@@ -8,6 +8,7 @@
     cfg_aliases::cfg_aliases! {
         bsd: {
             any(
+                target_os = "dragonfly",
                 target_os = "freebsd",
                 target_os = "openbsd",
                 target_os = "netbsd",
