# New ports collection Makefile for: rxvt
# Date created:         5th December 1994
# Whom:                 gpalmer@FreeBSD.org
#
# $FreeBSD$
#
# If possible, please consider updating the simple ports/x11-clocks/rclock
# (and maybe ports/chinese/rxvt) when you upgrade rxvt.  These ports all use
# the same distfile.

PORTNAME=	rxvt
PORTVERSION=	2.6.4
PORTREVISION=	1
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/%SUBDIR%/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/rxvt/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/unix/X11/terms/rxvt/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old devel

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A low memory usage xterm replacement that supports color

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_SIZE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-utmp --enable-wtmp \
		--with-xpm --enable-xpm-background --enable-transparency
USE_BZIP2=	yes
MAN1=		rxvt.1
PLIST_FILES=	bin/rxvt

# enable big5 support
.if defined(WITH_BIG5)
CONFIGURE_ARGS+=	--enable-big5
.endif # WITH_BIG5
#
# enable gb support
.if defined(WITH_GB)
CONFIGURE_ARGS+=	--enable-gb
.endif # WITH_GB
#
# enable greek keyboard support
.if defined(WITH_GREEK_KEYBOARD)
CONFIGURE_ARGS+=	--enable-greek
.endif # WITH_GREEK_KEYBOARD
#
# enable half width/height shadows scrollbar
.if defined(WITH_HALF_SHADOW)
CONFIGURE_ARGS+=	--enable-half-shadow
.endif
#
# enable kanji support
.if defined(WITH_KANJI)
CONFIGURE_ARGS+=	--enable-kanji
.endif # WITH_KANJI
#
# enable menubar
.if defined(WITH_MENUBAR)
CONFIGURE_ARGS+=	--enable-menubar
.endif # WITH_MENUBAR
#
# enable NeXT style scrollbar
.if defined(WITH_NEXT_SCROLLBAR)
CONFIGURE_ARGS+=	--enable-next-scroll
.endif
#
# XIM (X Input Method) protocol support
.ifndef(WITHOUT_XIM)
CONFIGURE_ARGS+=	--enable-xim
.endif # WITH_XIM
#
# enable Xterm style scrollbar
.if defined(WITH_XTERM_SCROLLBAR)
CONFIGURE_ARGS+=	--enable-xterm-scroll
.endif # WITH_XTERM_SCROLLBAR
#

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITHOUT_XIM=yes		disable support for XIM (X Input Method) protocol"
	@${ECHO_MSG} "WITH_BIG5=yes		add support for Chinese characters (BIG5)"
	@${ECHO_MSG} "WITH_GB=yes		add support for Chinese characters (GB)"
	@${ECHO_MSG} "WITH_GREEK_KEYBOARD=yes	add support for greek keyboard"
	@${ECHO_MSG} "WITH_HALF_SHADOW=yes	use half width/height shadows on non-Xterm scrollbar"
	@${ECHO_MSG} "WITH_KANJI=yes		add support for Kanji characters"
	@${ECHO_MSG} "WITH_MENUBAR=yes	add support for rxvt menu bar system"
	@${ECHO_MSG} "WITH_NEXT_SCROLLBAR=yes	add support for a NeXT-like scrollbar"
	@${ECHO_MSG} "WITH_XTERM_SCROLLBAR=yes	make the scrollbar look like an Xterm scrollbar"
	@${ECHO_MSG} "WITH_CLEARTEXTPASSWD=yes 	use cleartext passwords"

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/rxvt

.include <bsd.port.mk>
