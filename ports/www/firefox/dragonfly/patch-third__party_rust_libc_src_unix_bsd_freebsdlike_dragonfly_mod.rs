--- third_party/rust/libc/src/unix/bsd/freebsdlike/dragonfly/mod.rs.orig
+++ third_party/rust/libc/src/unix/bsd/freebsdlike/dragonfly/mod.rs
@@ -789,6 +789,8 @@
 pub const IFF_NPOLLING: c_int = 0x100000; // interface is in polling mode
 pub const IFF_IDIRECT: c_int = 0x200000; // direct input
 
+pub const IP_RECVTOS: c_int = 68;
+
 //
 // sys/netinet/in.h
 // Protocols (RFC 1700)
