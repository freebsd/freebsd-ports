--- src/Resource.hh.orig	Thu Jul 29 21:04:30 2004
+++ src/Resource.hh	Thu Jul 29 21:22:14 2004
@@ -66,16 +66,9 @@
 {
 public:	
 	Resource(ResourceManager &rm, T val, 
-	const std::string &name, const std::string &altname):
-	Resource_base(name, altname),
-	m_value(val), m_defaultval(val),
-	m_rm(rm)
-	{
-		m_rm.addResource(*this); // add this to resource handler
-	}
-	virtual ~Resource() {
-		m_rm.removeResource(*this); // remove this from resource handler
-	}
+	const std::string &name, const std::string &altname);
+
+	virtual ~Resource();
 
 	inline void setDefaultValue() {  m_value = m_defaultval; }
 	void setFromString(const char *strval);
@@ -128,5 +121,18 @@
 	static bool m_init;
 	ResourceList m_resourcelist;
 };
+
+template <typename T>
+Resource<T>::Resource(ResourceManager &rm, T val, const std::string &name, 
+			const std::string &altname):
+	Resource_base(name, altname), m_value(val), m_defaultval(val), 
+	m_rm(rm) {
+                m_rm.addResource(*this); // add this to resource handler
+}
+
+template <typename T>
+Resource<T>::~Resource() {
+                m_rm.removeResource(*this); // remove this from resource handler
+}
 
 #endif //_RESOURCE_HH_
