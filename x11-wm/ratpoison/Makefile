# Created by: Gergely Nagy <8@free.bsd.hu>
# $FreeBSD$

PORTNAME=	ratpoison
PORTVERSION=	1.4.9
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	SAVANNAH

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Simple window manager with no fat library dependencies

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig xorg
USE_XORG=	ice x11 xext xrandr xtst
GNU_CONFIGURE=	yes

SUB_FILES=	ratpoison.desktop

INFO=		ratpoison

OPTIONS_DEFINE=		DOCS GDM_SUPPORT READLINE XFT
OPTIONS_DEFAULT=	READLINE XFT
OPTIONS_SUB=		yes

GDM_SUPPORT_DESC=	Install session data files for GDM
READLINE_USES=		readline
READLINE_CONFIGURE_ENABLE=	history
XFT_USES=		xorg
XFT_USE=		xorg=xft
XFT_CONFIGURE_WITH=	xft

post-patch:
	@${REINPLACE_CMD} -e \
		'/^doc_DATA/s|COPYING||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|$$(lispdir)|$$(pkgdatadir)|' ${WRKSRC}/contrib/Makefile.in

post-install-GDM_SUPPORT-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dm/Sessions
	(cd ${WRKDIR} && ${INSTALL_DATA} ratpoison.desktop \
		${STAGEDIR}${PREFIX}/etc/dm/Sessions)

.include <bsd.port.mk>
