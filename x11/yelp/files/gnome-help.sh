#!/bin/sh

dist_bin=`dirname $0`

MOZILLA_HOME=%%X11BASE%%/lib/%%MOZILLA%%

if [ -n "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=$MOZILLA_HOME:$LD_LIBRARY_PATH
else
  LD_LIBRARY_PATH=$MOZILLA_HOME
fi
export LD_LIBRARY_PATH

MOZILLA_FIVE_HOME=$MOZILLA_HOME
export MOZILLA_FIVE_HOME

exec "%%PREFIX%%/bin/gnome-help-bin" "$@"
