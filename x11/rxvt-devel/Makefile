# New ports collection Makefile for: rxvt
# Date created:         5th December 1994
# Whom:                 gpalmer@FreeBSD.org
#
# $FreeBSD$
#
# If possible, please consider updating the simple ports/x11-clocks/rclock
# (and maybe ports/chinese/rxvt) when you upgrade rxvt.  These ports all use
# the same distfile.

PORTNAME=	rxvt-devel
PORTVERSION= 	2.7.5
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/ \
		ftp://mason.primenet.com.au/pub/rxvt/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/rxvt/ \
		ftp://ftp.fu-berlin.de/unix/X11/terms/rxvt/
DISTNAME=	rxvt-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--enable-utmp --enable-wtmp --enable-languages \
		--with-xpm --enable-xpm-background --enable-transparency \
		--enable-shared
USE_LIBTOOL=	yes
INSTALLS_SHLIB= yes
USE_BZIP2=	yes

MAN1=		rxvt.1

# enable greek keyboard support
.if defined(WITH_GREEK_KEYBOARD)
CONFIGURE_ARGS+=	--enable-greek
.endif # WITH_GREEK_KEYBOARD
#
# enable menubar
.if defined(WITH_MENUBAR)
CONFIGURE_ARGS+=	--enable-menubar
.endif # WITH_MENUBAR
#
# enable scrolling via mouse wheel or buttons 4 & 5
.if defined(WITH_MOUSEWHEEL)
CONFIGURE_ARGS+=	--enable-mousewheel
.endif # WITH_MOUSEWHEEL
#
# enable NeXT style scrollbar
.if defined(WITH_NEXT_SCROLLBAR)
CONFIGURE_ARGS+=	--enable-next-scroll
.endif
#
# enable rxvt style scrollbar
.if defined(WITH_RXVT_SCROLLBAR)
CONFIGURE_ARGS+=	--enable-rxvt-scroll	
.endif # WITH_RXVT_SCROLLBAR
#
# XIM (X Input Method) protocol support
.if defined(WITH_XIM)
CONFIGURE_ARGS+=	--enable-xim
.endif # WITH_XIM
#
# enable Xterm style scrollbar
.if defined(WITH_XTERM_SCROLLBAR)
CONFIGURE_ARGS+=	--enable-xterm-scroll	
.endif # WITH_XTERM_SCROLLBAR

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/rxvt

.include <bsd.port.mk>
