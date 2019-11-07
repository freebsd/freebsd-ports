# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	wmanager
PORTVERSION=	0.2.1
PORTREVISION=	14
CATEGORIES=	x11-wm
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 window manager selector

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gl gmake xorg
USE_XORG=	x11 xext
USE_GL=		gl

OPTIONS_DEFINE=	ADDONS DOCS EXAMPLES
OPTIONS_DEFAULT=ADDONS
OPTIONS_SUB=	yes

ADDONS_DESC=		Install the helper scripts and manpages
ADDONS_RUN_DEPENDS=	wmanager-loop:x11-wm/wmanager-addons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmanager ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in FAQ HISTORY INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/.wmanagerrc ${STAGEDIR}${EXAMPLESDIR}/wmanagerrc_sample
	${INSTALL_DATA} ${WRKSRC}/.xinitrc ${STAGEDIR}${EXAMPLESDIR}/xinitrc_sample

.include <bsd.port.mk>
