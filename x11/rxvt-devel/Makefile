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
PORTVERSION=	2.7.5
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/ \
		ftp://mason.primenet.com.au/pub/rxvt/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/rxvt/ \
		ftp://ftp.fu-berlin.de/unix/X11/terms/rxvt/
DISTNAME=	rxvt-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-utmp --enable-wtmp --enable-languages \
		--with-xpm --enable-xpm-background --enable-transparency \
		--enable-shared
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_BZIP2=	yes

MAN1=		rxvt.1

# set the default encoding for multi-char glyph languages
.if defined(WITH_ENCODING)
CONFIGURE_ARGS+=	--with-encoding=${WITH_ENCODING}
.endif # WITH_ENCODING
#
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
.ifndef(WITHOUT_XIM)
CONFIGURE_ARGS+=	--enable-xim
.endif # WITHOUT_XIM
#
# enable Xterm style scrollbar
.if defined(WITH_XTERM_SCROLLBAR)
CONFIGURE_ARGS+=	--enable-xterm-scroll	
.endif # WITH_XTERM_SCROLLBAR

pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "WITHOUT_XIM=yes		disable support for XIM (X Input Method) protocol"
	@${ECHO_MSG} "WITH_GREEK_KEYBOARD=yes		add support for greek keyboard"
	@${ECHO_MSG} "WITH_MENUBAR=yes		add support for rxvt menu bar system"
	@${ECHO_MSG} "WITH_WITH_MOUSEWHEEL=yes	add support for scrolling via mouse wheel"
	@${ECHO_MSG} "				or buttons 4 & 5"
	@${ECHO_MSG} "WITH_NEXT_SCROLLBAR=yes		add support for a NeXT-like scrollbar"
	@${ECHO_MSG} "WITH_RXVT_SCROLLBAR=yes		add support for the original rxvt scrollbar"
	@${ECHO_MSG} "WITH_XTERM_SCROLLBAR=yes	add support for an Xterm-like scrollbar"
	@${ECHO_MSG}
.ifndef(WITH_ENCODING)
	@${ECHO_MSG} "==> You can specify an alternate encoding by setting the WITH_ENCODING variable"
	@${ECHO_MSG} '==> Options are: "eucj" EUC Japanese encoding; "sjis" Shift JIS encoding;'
	@${ECHO_MSG} '==> "big5" BIG5 encoding; "gb" GB encoding; "kr" EUC Korean encoding'
	@${ECHO_MSG} '==> "noenc" for no encoding (useful if you are experiencing encoding problems)'
	@${ECHO_MSG} '==> For example, "WITH_ENCODING=gb" for GB encoding'
	@${ECHO_MSG}
.endif

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/rxvt

.include <bsd.port.mk>
