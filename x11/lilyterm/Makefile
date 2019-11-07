# $FreeBSD$

PORTNAME=	lilyterm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.9.4
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Lightweight, but functional terminal emulator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext gmake gnome pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 gtk20 vte
USE_XORG=	x11 xext
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Tetralet
GH_PROJECT=	LilyTerm

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-install:
	@${RM} -r ${STAGEDIR}${EXAMPLESDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lilyterm
	${MV} ${STAGEDIR}${PREFIX}/etc/xdg/lilyterm.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/lilyterm.conf.sample

.include <bsd.port.mk>
