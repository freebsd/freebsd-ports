# $FreeBSD$

PORTNAME=	xorg-apps
PORTVERSION=	7.5.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.org apps meta-port

COMPONENTS=	appres bitmap xf86dga:dga iceauth luit \
		x11-fonts/mkfontdir:mkfontdir \
		x11-fonts/mkfontscale:mkfontscale sessreg \
		setxkbmap smproxy x11perf xauth xbacklight xcalc \
		xcmsdb xconsole xcursorgen xdpyinfo xdriinfo xev xgamma xgc \
		xhost xinput xkbcomp xkbevd xkbutils:xkbvleds xkill \
		xlsatoms xlsclients xmodmap xpr xprop xrandr xrdb \
		xrefresh xset xsetmode xsetroot xvinfo xwd xwininfo \
		xwud xmessage

# These three are added for convenience purposes only.
COMPONENTS+=	x11-wm/twm:twm x11-clocks/xclock:xclock xinit xterm

NO_BUILD=	yes

do-install:
		${MKDIR} ${PREFIX}/libdata/xorg
		${TOUCH} ${PREFIX}/libdata/xorg/apps

.for comp in ${COMPONENTS}
OPTIONS_DEFINE+=	${comp:C/:.*//:C/.*\///:U}
OPTIONS_DEFAULT+=	${comp:C/:.*//:C/.*\///:U}
${comp:C/:.*//:C/.*\///:U}_DESC=	Install ${comp:C/:.*//:C/.*\///} application
.endfor

.include <bsd.port.options.mk>

.for comp in ${COMPONENTS}
. if ${PORT_OPTIONS:M${comp:C/:.*//:C/.*\///:U}}
.  if ${comp:M:}==""
port=${comp}
check=${comp:C/.*\///} # doesn't work
.  else
port=${comp:C/:.*//}
check=${comp:C/.*://}
.  endif
.  if ${port:M*/*}==""
port:=x11/${port}
.  endif
RUN_DEPENDS:=	${RUN_DEPENDS} ${check}:${PORTSDIR}/${port}
. endif
.endfor

.include <bsd.port.mk>
