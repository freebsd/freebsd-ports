# $FreeBSD$

PORTNAME=	xterm
PORTVERSION=	281
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/ \
		CRITICAL
EXTRACT_SUFX=	.tgz

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Terminal emulator for the X Window System

CONFLICTS=	x11iraf-[0-9]*

USE_XORG=	xaw xft
WANT_GNOME=	desktopfileutils
GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-utempter --enable-narrowproto --enable-256-color

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	WCHAR LUIT DECTERM PCRE GNOME DABBREV

DABBREV_DESC=	Enable support for dabbrev-expand
DECTERM_DESC=	Enable DECterm Locator support
LUIT_DESC=	Use LUIT for locale convertion from/to UTF-8
WCHAR_DESC=	Enable wide-character support

OPTIONS_DEFAULT=WCHAR LUIT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLUIT}
CONFIGURE_ARGS+=	--enable-luit
BUILD_DEPENDS=	luit:${PORTSDIR}/x11/luit
.endif

.if ${PORT_OPTIONS:MWCHAR}
CONFIGURE_ARGS+=	--enable-wide-chars
.endif

.if ${PORT_OPTIONS:MDECTERM}
CONFIGURE_ARGS+=	--enable-dec-locator
.endif

.if ${PORT_OPTIONS:MPCRE}
CONFIGURE_ARGS+=	--with-pcre
LIB_DEPENDS=		pcre:${PORTSDIR}/devel/pcre
.endif

.if ${PORT_OPTIONS:MDABBREV}
CONFIGURE_ARGS+=	--enable-dabbrev
.endif

.if ${PORT_OPTIONS:MGNOME}
USE_GNOME=	desktopfileutils
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

MAN1=		resize.1 koi8rxterm.1 uxterm.1 xterm.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900004
LIB_DEPENDS+=	utempter:${PORTSDIR}/sysutils/libutempter
.endif

post-install:
.for f in koi8rxterm resize uxterm xterm
	@${CHMOD} ${BINMODE} ${PREFIX}/bin/${f}
.endfor
	@${MKDIR} ${PREFIX}/share/applications/
	@${INSTALL_DATA} ${WRKSRC}/xterm.desktop ${PREFIX}/share/applications/
.if ${PORT_OPTIONS:MGNOME}
	@-update-desktop-database
.endif

.if ${PORT_OPTIONS:MWCHAR}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
