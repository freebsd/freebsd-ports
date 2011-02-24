# New ports collection makefile for:	xterm
# Date created:				24.07.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	xterm
PORTVERSION=	269
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/ \
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

.if defined(WITH_WIDE_CHARS)
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
.for f in koi8rxterm resize uxterm xterm
	@${CHMOD} ${BINMODE} ${PREFIX}/bin/${f}
.endfor

.if defined(WITH_WIDE_CHARS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
