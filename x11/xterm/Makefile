# New ports collection makefile for:	xterm
# Date created:				24.07.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	xterm
PORTVERSION=	269
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/ \
		http://voodoo.bawue.com/download/ \
		CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Terminal emulator for the X Window System

BUILD_DEPENDS=	luit:${PORTSDIR}/x11/luit

USE_XORG=	xaw xft
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--with-utempter --enable-narrowproto

OPTIONS=	WIDE_CHARS "enable wide-character support" on \
		256_COLOR "enable 256-color support" off \
		DEC_LOCATOR "enable DECterm Locator support" off

.include <bsd.port.options.mk>

.if !defined(WITHOUT_WIDE_CHARS)
CONFIGURE_ARGS+=	--enable-wide-chars --enable-luit
.endif

.if defined(WITH_256_COLOR)
CONFIGURE_ARGS+=	--enable-256-color
.endif

.if defined(WITH_DEC_LOCATOR)
CONFIGURE_ARGS+=	--enable-dec-locator
.endif

MAN1=		resize.1 koi8rxterm.1 uxterm.1 xterm.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900004
LIB_DEPENDS=	utempter.0:${PORTSDIR}/sysutils/libutempter
.endif

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/xterm
.if !defined(WITHOUT_WIDE_CHARS)
	@${ECHO_MSG}
	@${ECHO_MSG} '********************************************************'
	@${ECHO_MSG} '  NOTE: you installed xterm with wide chars support.'
	@${ECHO_MSG} '  This introduces some limitations comparing to the'
	@${ECHO_MSG} '  plain single chars version: this version of xterm'
	@${ECHO_MSG} '  will use UTF-8 charset for selection buffers,'
	@${ECHO_MSG} '  breaking 8-bit copy/paste support unless you are'
	@${ECHO_MSG} '  using UTF-8 or ISO8859-1 locale.  If you want'
	@${ECHO_MSG} '  8-bit charset selections to work as before, use'
	@${ECHO_MSG} '  "eightBitSelectTypes" XTerm resource setting.'
	@${ECHO_MSG}
	@${ECHO_MSG} '  For further information refer to the SELECT/PASTE'
	@${ECHO_MSG} '  section of xterm(1) manual page.'
	@${ECHO_MSG} '********************************************************'
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
