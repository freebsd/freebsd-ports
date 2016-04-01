# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	wmanager
PORTVERSION=	0.2.1
PORTREVISION=	13
CATEGORIES=	x11-wm
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 window manager selector

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PKGMESSAGE=	${WRKDIR}/pkg-message

USES=		gmake
USE_XORG=	x11 xext
USE_GL=		gl

OPTIONS_DEFINE=	ADDONS DOCS EXAMPLES
OPTIONS_DEFAULT=ADDONS
ADDONS_DESC=	Install the helper scripts and manpages
OPTIONS_SUB=	yes

ADDONS_RUNDEPENDS=	wmanager-loop:x11-wm/wmanager-addons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmanager ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in FAQ HISTORY INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/.wmanagerrc ${STAGEDIR}${EXAMPLESDIR}/wmanagerrc_sample
	${INSTALL_DATA} ${WRKSRC}/.xinitrc ${STAGEDIR}${EXAMPLESDIR}/xinitrc_sample

.include <bsd.port.mk>
