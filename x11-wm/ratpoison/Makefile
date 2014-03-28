# Created by: Gergely Nagy <8@free.bsd.hu>
# $FreeBSD$

PORTNAME=	ratpoison
PORTVERSION=	1.4.6
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://mirror.4bit.ws/
MASTER_SITE_SUBDIR=	ratpoison

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Simple window manager with no fat library dependencies

USE_XORG=	xext xinerama xtst
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	GDM_SUPPORT DOCS
GDM_SUPPORT_DESC=	Install session data files for GDM

INFO=		ratpoison
SUB_FILES=	ratpoison.desktop

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|bash|sh|g' ${WRKSRC}/contrib/allwindows.sh

.if ${PORT_OPTIONS:MGDM_SUPPORT}
PLIST_SUB+=	WITH_GDM=""

post-install:
	@${MKDIR} ${PREFIX}/etc/dm/Sessions
	${INSTALL_DATA} ${WRKDIR}/ratpoison.desktop ${STAGEDIR}${PREFIX}/etc/dm/Sessions
.else
PLIST_SUB+=	WITH_GDM="@comment "
.endif

.include <bsd.port.mk>
