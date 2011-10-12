# New ports collection makefile for:	xterm
# Date created:				24.07.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	xterm
PORTVERSION=	276
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/ \
		CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Terminal emulator for the X Window System

USE_XORG=	xaw xft
WANT_GNOME=	desktopfileutils
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--with-utempter --enable-narrowproto

OPTIONS=	WIDE_CHARS "enable wide-character support" on \
		LUIT "use LUIT for locale convertion from/to UTF-8" on \
		256_COLOR "enable 256-color support" off \
		DEC_LOCATOR "enable DECterm Locator support" off \
		PCRE "use PCRE for regular-expressions" off \
		GNOME "include gnome support for .desktop file" off

CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.options.mk>

.if defined(WITH_LUIT)
CONFIGURE_ARGS+=	--enable-luit
BUILD_DEPENDS=	luit:${PORTSDIR}/x11/luit
.endif

.if defined(WITH_WIDE_CHARS)
CONFIGURE_ARGS+=	--enable-wide-chars
.endif

.if defined(WITH_256_COLOR)
CONFIGURE_ARGS+=	--enable-256-color
.endif

.if defined(WITH_DEC_LOCATOR)
CONFIGURE_ARGS+=	--enable-dec-locator
.endif

.if defined(WITH_PCRE)
CONFIGURE_ARGS+=	--with-pcre
LIB_DEPENDS=		pcre.0:${PORTSDIR}/devel/pcre
.endif

.if defined(WITH_GNOME)
USE_GNOME=		desktopfileutils
PLIST_SUB+=		GNOME=""
.else
PLIST_SUB+=		GNOME="@comment "
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
	@${MKDIR} ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/xterm.desktop ${PREFIX}/share/applications/
.if defined(WITH_GNOME)
	@-update-desktop-database
.endif

.if defined(WITH_WIDE_CHARS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
