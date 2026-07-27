--- third_party/rust/mtu/src/lib.rs.orig
+++ third_party/rust/mtu/src/lib.rs
@@ -147,7 +147,7 @@
     }
 
     const LOOPBACK: [NameMtu; 2] = // [IPv4, IPv6]
-        if cfg!(any(target_os = "macos", target_os = "freebsd")) {
+        if cfg!(any(target_os = "macos", target_os = "dragonfly", target_os = "freebsd")) {
             [NameMtu(Some("lo0"), 16_384), NameMtu(Some("lo0"), 16_384)]
         } else if cfg!(any(target_os = "linux", target_os = "android")) {
             [NameMtu(Some("lo"), 65_536), NameMtu(Some("lo"), 65_536)]
