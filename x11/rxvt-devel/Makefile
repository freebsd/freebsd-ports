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
PORTVERSION=	2.7.10
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/%SUBDIR%/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/mirrors/rxvt/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/unix/X11/terms/rxvt/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old devel
PKGNAMESUFFIX=	-devel
DISTNAME=	rxvt-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A low memory usage xterm replacement that supports color

USE_INC_LIBTOOL_VER=13

USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-utmp --enable-wtmp --enable-languages \
		--with-xpm --enable-xpm-background --enable-transparency \
		--enable-shared
INSTALLS_SHLIB=	yes
USE_BZIP2=	yes

MAN1=		rxvt.1

# disable backspace key
.if defined(WITHOUT_BACKSPACE_KEY)
CONFIGURE_ARGS+=	--disable-backspace-key
.endif # WITHOUT_BACKSPACE_KEY
#
# disable delete key
.if defined(WITHOUT_DELETE_KEY)
CONFIGURE_ARGS+=	--disable-delete-key
.endif # WITHOUT_DELETE_KEY
#
# set the default encoding for multi-char glyph languages
.if defined(WITH_ENCODING)
CONFIGURE_ARGS+=	--with-encoding=${WITH_ENCODING}
.endif # WITH_ENCODING
#
# enable graphics support
.if defined(WITH_GRAPHICS)
CONFIGURE_ARGS+=	--enable-graphics
.endif # WITH_GRAPHICS
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
# enable smart resize
.if defined(WITH_SMART_RESIZE)
CONFIGURE_ARGS+=	--enable-smart-resize
.endif # WITH_SMART_RESIZE
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
#
# enable line-spacing
.if defined(WITH_LINESPACE)
CONFIGURE_ARGS+=	--enable-linespace
.endif # WITH_LINESPACE

CONFIGURE_ENV+=		LIBS="-lutil"

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG}
	@${ECHO_MSG} "WITHOUT_BACKSPACE_KEY=yes	disable handling of the backspace key"
	@${ECHO_MSG} "WITHOUT_DELETE_KEY=yes		disable handling of the delete key"
	@${ECHO_MSG} "WITHOUT_XIM=yes			disable support for XIM (X Input Method) protocol"
	@${ECHO_MSG} "WITH_GRAPHICS=yes		enable rxvt own graphics mode"
	@${ECHO_MSG} "WITH_GREEK_KEYBOARD=yes		add support for greek keyboard"
	@${ECHO_MSG} "WITH_LINESPACE=yes	add support for line-spacing"
	@${ECHO_MSG} "WITH_MENUBAR=yes		add support for rxvt menu bar system"
	@${ECHO_MSG} "WITH_MOUSEWHEEL=yes		add support for scrolling via mouse wheel"
	@${ECHO_MSG} "				or buttons 4 & 5"
	@${ECHO_MSG} "WITH_SMART_RESIZE=yes		enable smart growth/shrink behaviour"
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

post-patch:
	@${PERL} -pi -e 's|(PTYCHAR2\s+"[^"]+)"|\1ghijklmnopqrstuv"|' \
		${WRKSRC}/src/ptytty.c

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/rxvt

.include <bsd.port.mk>
