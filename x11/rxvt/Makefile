# New ports collection Makefile for: rxvt
# Date created:         5th December 1994
# Whom:                 gpalmer@FreeBSD.org
#
# $FreeBSD$
#
# If possible, please consider updating the simple ports/x11-clocks/rclock
# when you upgrade rxvt. These ports all use the same distfile.

PORTNAME=	rxvt
PORTVERSION=	2.6.4
PORTREVISION=	5
CATEGORIES+=	x11
MASTER_SITES=	SF

MAINTAINER=	akosela@andykosela.com
COMMENT=	A low memory usage xterm replacement that supports color

USE_XORG=	xpm
GNU_CONFIGURE=	yes

OPTIONS=	BIG5		"Build with BIG5 support" off \
		GB		"Build with GB support" off \
		GREEK 		"Build with greek keyboard support" off \
		HALF_SHADOW	"Build with half shadows support" off \
		KANJI		"Build with Kanji support" off \
		MENUBAR		"Build with menubar support" off \
		NEXT		"Build with NeXT scrollbar" off \
		TRANSPARENCY	"Build with transparency support" off \
		XGETDEFAULT	"Build with XGetDefault() support" off \
		XIM		"Build with XIM support" off \
		XTERM		"Build with Xterm scrollbar" off

CONFIGURE_ARGS=	--enable-utmp --enable-wtmp --enable-ttygid \
		--with-xpm --enable-xpm-background \
		--with-xpm-includes=${LOCALBASE}/include/X11 \
		--with-xpm-library=${LOCALBASE}/lib
MAN1=		rxvt.1
PLIST_FILES=	bin/rxvt

.include <bsd.port.pre.mk>

# enable big5 support
.if defined(WITH_BIG5)
CONFIGURE_ARGS+=	--enable-big5
.endif

# enable gb support
.if defined(WITH_GB)
CONFIGURE_ARGS+=	--enable-gb
.endif

# enable greek keyboard support
.if defined(WITH_GREEK)
CONFIGURE_ARGS+=	--enable-greek
.endif

# enable half width/height shadows scrollbar
.if defined(WITH_HALF_SHADOW)
CONFIGURE_ARGS+=	--enable-half-shadow
.endif

# enable kanji support
.if defined(WITH_KANJI)
CONFIGURE_ARGS+=	--enable-kanji
.endif

# enable menubar
.if defined(WITH_MENUBAR)
CONFIGURE_ARGS+=	--enable-menubar
.endif

# enable NeXT style scrollbar
.if defined(WITH_NEXT)
CONFIGURE_ARGS+=	--enable-next-scroll
.endif

# enable transparency support
.if defined(WITH_TRANSPARENCY)
CONFIGURE_ARGS+=	--enable-transparency
.endif

# make resources checking via XGetDefault()
.if defined(WITH_XGETDEFAULT)
CONFIGURE_ARGS+=	--enable-xgetdefault
.endif

# XIM (X Input Method) protocol support
.if defined(WITH_XIM)
CONFIGURE_ARGS+=	--enable-xim
.endif

# enable Xterm style scrollbar
.if defined(WITH_XTERM)
CONFIGURE_ARGS+=	--enable-xterm-scroll
.endif

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/rxvt

.include <bsd.port.post.mk>
