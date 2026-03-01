--- pkg/wavebase/wavebase.go.orig	2026-02-11 23:55:44 UTC
+++ pkg/wavebase/wavebase.go
@@ -81,6 +81,8 @@ var SupportedWshBinaries = map[string]bool{
 	"linux-arm64":   true,
 	"windows-x64":   true,
 	"windows-arm64": true,
+	"freebsd-x64":   true,
+	"freebsd-arm64": true,
 }
 
 type FDLock interface {
@@ -217,6 +219,7 @@ func resolveWaveCachesDir() string {
 		homeDir := GetHomeDir()
 		cacheDir = filepath.Join(homeDir, "Library", "Caches", appBundle)
 	case "linux":
+	case "freebsd":
 		xdgCache := os.Getenv("XDG_CACHE_HOME")
 		if xdgCache != "" {
 			cacheDir = filepath.Join(xdgCache, appBundle)
@@ -431,6 +434,25 @@ func getSystemSummary(ctx context.Context) string {
 			details = "Windows"
 		}
 		return fmt.Sprintf("%s (%s)", details, runtime.GOARCH)
+	case "freebsd":
+		// Read /var/run/os-release directly (standard location since 2012)
+		data, err := os.ReadFile("/var/run/os-release")
+		var prettyName string
+		if err == nil {
+			for _, line := range strings.Split(string(data), "\n") {
+				line = strings.TrimSpace(line)
+				if strings.HasPrefix(line, "PRETTY_NAME=") {
+					prettyName = strings.Trim(strings.TrimPrefix(line, "PRETTY_NAME="), "\"")
+					break
+				}
+			}
+		}
+		if prettyName == "" {
+			prettyName = "FreeBSD"
+		} else if !strings.Contains(strings.ToLower(prettyName), "freebsd") {
+			prettyName = "FreeBSD " + prettyName
+		}
+		return fmt.Sprintf("%s (%s)", prettyName, runtime.GOARCH)
 	default:
 		return fmt.Sprintf("%s (%s)", runtime.GOOS, runtime.GOARCH)
 	}
