#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: login_app
# REQUIRE: LOGIN

# Add the following line to /etc/rc.conf to enable login.app:
#
# login_app_enable="YES"
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE

login_app_enable=${login_app_enable-"NO"}

. /etc/rc.subr

name="login_app"
rcvar=`set_rcvar`
command="%%X11BASE%%/GNUstep/Apps/Login.app/Login"
command_args="&"

load_rc_config $name
run_rc_command "$1"
