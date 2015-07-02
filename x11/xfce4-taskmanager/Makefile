# Created by: DaJoob
# $FreeBSD$

PORTNAME=	xfce4-taskmanager
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Task manager for the Xfce desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig tar:bzip2
USE_GNOME=	glib20 cairo intltool intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2

GTK2_USE=		GNOME=gtk20,libwnck
GTK2_CONFIGURE_ON=	--enable-wnck --disable-wnck3
GTK3_USE=		GNOME=gtk20,gtk30,libwnck3
GTK3_CONFIGURE_ON=	--enable-gtk3 --enable-wnck3 --disable-wnck

CONFIGURE_ARGS=	--disable-gksu

post-patch:
	@${REINPLACE_CMD} -e 's|prefix)/$$(DATADIRNAME)|datadir)|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
