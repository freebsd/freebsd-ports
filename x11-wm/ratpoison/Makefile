# Created by: Gergely Nagy <8@free.bsd.hu>
# $FreeBSD$

PORTNAME=	ratpoison
PORTVERSION=	1.4.8
CATEGORIES=	x11-wm
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple window manager with no fat library dependencies

LICENSE=	GPLv2+

USES=		pkgconfig
USE_XORG=	ice x11 xext xinerama xtst
GNU_CONFIGURE=	yes

SUB_FILES=	ratpoison.desktop

INFO=		ratpoison

OPTIONS_DEFINE=		DOCS GDM_SUPPORT READLINE XFT
OPTIONS_DEFAULT=	READLINE XFT
OPTIONS_SUB=		yes

GDM_SUPPORT_DESC=	Install session data files for GDM
READLINE_USES=		readline
READLINE_CONFIGURE_ENABLE=	history
XFT_USE=		xorg=xft
XFT_CONFIGURE_WITH=	xft

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^doc_DATA/s|COPYING||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|$$(lispdir)|$$(pkgdatadir)|' ${WRKSRC}/contrib/Makefile.in

post-install:
.if ${PORT_OPTIONS:MGDM_SUPPORT}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/dm/Sessions
	(cd ${WRKDIR} && ${INSTALL_DATA} ratpoison.desktop \
		${STAGEDIR}${PREFIX}/etc/dm/Sessions)
.endif

.include <bsd.port.mk>
