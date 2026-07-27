--- toolkit/modules/Troubleshoot.sys.mjs.orig
+++ toolkit/modules/Troubleshoot.sys.mjs
@@ -188,7 +188,17 @@
       }
       for (let name in dataProviders) {
         try {
-          dataProviders[name](providerDone.bind(null, name));
+          let providerResult = dataProviders[name](providerDone.bind(null, name));
+          // Async providers may reject after their first await without ever
+          // invoking the done callback (e.g. ChromeUtils.requestProcInfo() is
+          // not implemented on DragonFly and rejects). Catch that so snapshot()
+          // still resolves instead of hanging forever and leaving about:support
+          // blank.
+          Promise.resolve(providerResult).catch(err => {
+            let msg = "Troubleshoot data provider failed: " + name + "\n" + err;
+            console.error(msg);
+            providerDone(name, msg);
+          });
         } catch (err) {
           let msg = "Troubleshoot data provider failed: " + name + "\n" + err;
           console.error(msg);
