# ex:ts=8
# Ports collection makefile for:	wmDrawer
# Date created:			Apr 6, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wmdrawer
PORTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://people.easter-eggs.org/~valos/wmdrawer/:tarball \
		http://www.daemon.li/downloads/:pixmap
DISTNAME=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${EXTRACT_ONLY}:tarball \
		daemon.xpm:pixmap
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	j.el-rayes@daemon.li
COMMENT=	A dockapp which provides a drawer to launch applications

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include `gdk-pixbuf-config --cflags`
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt `gdk-pixbuf-config --libs` -lgdk_pixbuf_xlib" DOCSDIR=${DOCSDIR}

MANCOMPRESSED=	yes
MAN1=	wmdrawer.1x

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/X11R6,${X11BASE},g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,$$[(]DESTDIR[)]/usr/local,${PREFIX},g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR},g" ${WRKSRC}/wmdrawerrc.example

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/daemon.xpm ${DATADIR}

.include <bsd.port.mk>
