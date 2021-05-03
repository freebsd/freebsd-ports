#! /bin/sh
#
# Try to run a Plasma Wayland session; to be invoked from a text console.
# This script is far longer than it needs to be, because it documents
# all kinds of settings that you **might** want to set for specific
# use-cases or testing.

### TOOLKIT SETTINGS
#
# Force toolkits to use wayland.
#  - MOZ is for Firefox
#  - GDK is for GDK, will crash non-Wayland GDK-users like emacs
#  - QPA is for Qt, forces EGL, causes graphics glitches
# export MOZ_ENABLE_WAYLAND=1
# export GDK_BACKEND=wayland
# export QT_QPA_PLATFORM=wayland-egl

### DRIVER SETTINGS
#
# Some (older) Intel HD iGPU need this:
#	export LIBVA_DRIVER_NAME=i965

### XDG SETTINGS
#
#
# export XDG_SESSION_TYPE=wayland

### KDE / Plasma / Qt SETTINGS
#
#
# To switch on software rendering:
#	export KWIN_COMPOSE=Q
# Disable client-side-decorations:
#	export QT_WAYLAND_DISABLE_WINDOWDECORATION=1
# To log debug things:
#	export QT_LOGGING_RULES="kwin_core.debug=true;kwin_libinput.debug=true"
# To log to a specific file (recommended if you're using the logging rules
# and want to debug startup problems):
#	LOGFILE=/tmp/plasma-wayland.log

### STARTUP SEQUENCE
#
# Plasma needs a DBus session-bus, and it needs to have access to
# the DRM GPU (e.g. to /dev/dri/card0) which we arrange through
# ConsoleKit2.
#
scaffolding="ck-launch-session"
if [ -z "$DBUS_SESSION_BUS_ADDRESS" ] ; then
    scaffolding="$scaffolding dbus-run-session"
fi

startup_dir=`/usr/bin/dirname "$0"`
startup_exe=`/usr/bin/basename "$0" .sh`

if [ -z "$LOGFILE" ] ; then
	{
		echo "Starting KDE Plasma Wayland from PID $$"
		echo "XDG_RUNTIME_DIR=$XDG_RUNTIME_DIR"
		echo "scaffolding=$scaffolding"
		echo "startup=$startup_dir/$startup_exe"
	} > $LOGFILE

	exec $scaffolding $startup_dir/$startup_exe 2>&1 | tee -a $LOG
else
	exec $scaffolding $startup_dir/$startup_exe
fi
