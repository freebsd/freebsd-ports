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
COMMENT=	Task manager for the Xfce desktop

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
	libwnck-1.so:${PORTSDIR}/x11-toolkits/libwnck

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20 intltool intlhack

post-patch:
	@${REINPLACE_CMD} -e 's|prefix)/$$(DATADIRNAME)|datadir)|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
