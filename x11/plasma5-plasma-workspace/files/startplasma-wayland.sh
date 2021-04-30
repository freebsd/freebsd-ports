#! /bin/sh
#
# Try to run a Plasma Wayland session; to be invoked from a text console

### TOOLKIT SETTINGS
#
# Tell toolkits to use wayland
export MOZ_ENABLE_WAYLAND=1
export GDK_BACKEND=wayland
export QT_QPA_PLATFORM=wayland-egl
export QT_WAYLAND_DISABLE_WINDOWDECORATION=1

# Possible settings for drivers
#
# Some (older) Intel HD iGPU need this:
#	export LIBVA_DRIVER_NAME=i965

### XDG SETTINGS
#
#
if test -z "$XDG_RUNTIME_DIR"; then
	export XDG_RUNTIME_DIR=/tmp/`id -u`-runtime-dir
	if ! test -d "$XDG_RUNTIME_DIR"; then
		mkdir "$XDG_RUNTIME_DIR"
		chmod 0700 "$XDG_RUNTIME_DIR"
	fi
fi
export XDG_SESSION_TYPE=wayland

### KDE / Plasma / Qt settings
#
#
# To switch on software rendering:
#	export KWIN_COMPOSE=Q
# To log debug things:
#	export QT_LOGGING_RULES="kwin_core.debug=true;kwin_libinput.debug=true"
# To log to a specific file (recommended if you're using the logging rules
# and want to debug startup problems):
#	LOGFILE=/tmp/plasma-wayland.log

# TODO: check if ck-launch-session is needed
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
