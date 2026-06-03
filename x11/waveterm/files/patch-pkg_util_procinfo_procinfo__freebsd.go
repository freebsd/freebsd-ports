--- pkg/util/procinfo/procinfo_freebsd.go.orig	2026-04-17 13:56:29 UTC
+++ pkg/util/procinfo/procinfo_freebsd.go
@@ -0,0 +1,40 @@
+package procinfo
+
+import (
+	"context"
+
+	"github.com/shirou/gopsutil/v4/process"
+)
+
+func MakeGlobalSnapshot() (any, error) {
+	return nil, nil
+}
+
+func GetProcInfo(ctx context.Context, _ any, pid int32) (*ProcInfo, error) {
+	p, err := process.NewProcessWithContext(ctx, pid)
+	if err != nil {
+		return nil, ErrNotFound
+	}
+
+	name, _ := p.NameWithContext(ctx)
+	ppid, _ := p.PpidWithContext(ctx)
+	status, _ := p.StatusWithContext(ctx)
+	uids, _ := p.UidsWithContext(ctx) // [real, effective, saved]
+	times, _ := p.TimesWithContext(ctx)
+	mem, _ := p.MemoryInfoWithContext(ctx)
+	numThreads, _ := p.NumThreadsWithContext(ctx)
+
+	info := &ProcInfo{
+		Pid:        pid,
+		Ppid:       ppid,
+		Command:    name,
+		Status:     status[0],
+		CpuUser:    times.User,
+		CpuSys:     times.System,
+		Uid:        uint32(uids[0]),
+		VmRSS:      int64(mem.RSS),
+		NumThreads: numThreads,
+	}
+
+	return info, nil
+}
