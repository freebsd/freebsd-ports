--- kdesu/su.cpp	Sun Jan  6 20:22:55 2002
+++ kdesu/su.cpp.new	Sun Jan  6 20:22:48 2002
@@ -74,6 +74,7 @@
 	setTerminal(true);
 
     QCStringList args;
+    args+="-";
     if ((m_Scheduler != SchedNormal) || (m_Priority > 50))
 	args += "root";
     else
@@ -185,12 +186,12 @@
 	    break;
 
 	case 1:
-	    if (line.stripWhiteSpace().isEmpty()) 
+	    QCString s=line.stripWhiteSpace();
+	    if (s.isEmpty()) 
 	    {
 		state++;
 		break;
 	    }
-	    QCString s=line.stripWhiteSpace();
 	    for (i=0; i<s.length(); i++)
             {
 		if (s[i] != '*')
