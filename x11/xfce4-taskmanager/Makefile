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
USE_GNOME=	gtk20 glib20 cairo intltool intlhack
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	GTK3
GTK3_USE=	gnome=gtk30,libwnck3
GTK3_CONFIGURE_ON=	--enable-gtk3 --enable-wnck3 --disable-wnck
GTK3_USE_OFF=	gnome=libwnck
GTK3_CONFIGURE_OFF=	--enable-wnck --disable-wnck3

CONFIGURE_ARGS+=	--disable-gksu

post-patch:
	@${REINPLACE_CMD} -e 's|prefix)/$$(DATADIRNAME)|datadir)|' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
