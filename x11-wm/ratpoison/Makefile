# New ports collection makefile for:	ratpoison
# Date created:		January 20, 2001
# Whom:			Gergely Nagy <8@free.bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	ratpoison
PORTVERSION=	1.3.0
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Simple window manager with no fat library dependencies

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

OPTIONS=	GDM_SUPPORT "Install session data files for GDM" off

.include <bsd.port.pre.mk>

.if defined (WITH_GDM_SUPPORT)
PLIST_SUB+=	WITH_GDM=""
post-configure:
	${SED} -e 's,%%PREFIX%%,${PREFIX},' ${FILESDIR}/ratpoison.desktop \
	  > ${WRKSRC}/ratpoison.desktop

post-install:
	${MKDIR} ${PREFIX}/etc/gdm/Sessions
	${INSTALL_DATA} ${WRKSRC}/ratpoison.desktop ${PREFIX}/etc/dm/Sessions/
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
