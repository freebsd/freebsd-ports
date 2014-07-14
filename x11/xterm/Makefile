# Created by: krion
# $FreeBSD$

PORTNAME=	xterm
PORTVERSION=	309
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/:src1 \
		CRITICAL:src1 CRITICAL:src2
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src1 \
		bsd-xterm-icons-${ICONVERSION}${EXTRACT_SUFX}:src2

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Terminal emulator for the X Window System

CONFLICTS=	x11iraf-[0-9]*

USE_XORG=	xaw xft
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-utempter --enable-narrowproto

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

ICONVERSION=	1

OPTIONS_DEFINE=	WCHAR LUIT DECTERM PCRE DABBREV 256COLOR SIXEL GNOME

DABBREV_DESC=	Enable support for dabbrev-expand
DECTERM_DESC=	Enable DECterm Locator support
LUIT_DESC=	Use LUIT for locale convertion from/to UTF-8
SIXEL_DESC=	Enable Sixel graphics support
WCHAR_DESC=	Enable wide-character support
256COLOR_DESC=	Enable 256-color support

OPTIONS_DEFAULT=WCHAR LUIT 256COLOR

256COLOR_CONFIGURE_ENABLE=	256-color
LUIT_BUILD_DEPENDS=		luit:${PORTSDIR}/x11/luit
LUIT_CONFIGURE_ENABLE=		luit
WCHAR_CONFIGURE_ENABLE=		wide-chars
DECTERM_CONFIGURE_ENABLE=	dec-locator
PCRE_CONFIGURE_WITH=		pcre
PCRE_LIB_DEPENDS=		libpcre.so:${PORTSDIR}/devel/pcre
DABBREV_CONFIGURE_ENABLE=	dabbrev
SIXEL_CONFIGURE_ENABLE=		sixel-graphics
GNOME_USES=			desktop-file-utils

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900004
LIB_DEPENDS+=	libutempter.so:${PORTSDIR}/sysutils/libutempter
.endif

post-extract:
	@${CP} ${WRKDIR}/bsd-xterm-icons-1/*.png \
		${WRKDIR}/bsd-xterm-icons-1/*.xpm \
			${WRKSRC}/icons/

post-install:
.for f in koi8rxterm resize uxterm xterm
	@${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/xterm.desktop \
		${STAGEDIR}${PREFIX}/share/applications/

.if ${PORT_OPTIONS:MWCHAR}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
