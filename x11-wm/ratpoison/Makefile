# New ports collection makefile for:	ratpoison
# Date created:		January 20, 2001
# Whom:			Gergely Nagy <8@free.bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	ratpoison
PORTVERSION=	1.4.5
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://mirror.4bit.ws/
MASTER_SITE_SUBDIR=	ratpoison

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Simple window manager with no fat library dependencies

USE_XORG=	xext xinerama xtst
GNU_CONFIGURE=	yes

OPTIONS=	GDM_SUPPORT "Install session data files for GDM" off

SUB_FILES=	ratpoison.desktop

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|bash|sh|g' ${WRKSRC}/contrib/allwindows.sh

.if defined (WITH_GDM_SUPPORT)
PLIST_SUB+=	WITH_GDM=""

post-install:
	${MKDIR} ${PREFIX}/etc/dm/Sessions
	${INSTALL_DATA} ${WRKDIR}/ratpoison.desktop ${PREFIX}/etc/dm/Sessions/
.else
PLIST_SUB+=	WITH_GDM="@comment "
.endif

.if defined(NOPORTDOCS)
INSTALL_TARGET=	SUBDIRS=src install-exec
.else
MAN1=		ratpoison.1
INFO=		ratpoison
.endif

.include <bsd.port.post.mk>
