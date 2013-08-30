# Created by: DaJoob
# $FreeBSD$

PORTNAME=	xfce4-taskmanager
PORTVERSION=	1.0.0
PORTREVISION=	3
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	A task manager for Xfce

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
	wnck-1.22:${PORTSDIR}/x11-toolkits/libwnck

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20 desktopfileutils intltool intlhack

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|prefix)/$$(DATADIRNAME)|datadir)|' \
		${WRKSRC}/po/Makefile.in.in

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
