# ex:ts=8
# Ports collection makefile for:	wmDrawer
# Date created:			Apr 6, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wmdrawer
PORTVERSION=	0.10.4.1
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://people.easter-eggs.org/~valos/wmdrawer/:tarball \
		http://www.daemon.li/downloads/:pixmap
DISTNAME=	${PORTNAME}-${PORTVERSION}
DISTFILES=	${EXTRACT_ONLY}:tarball \
		daemon.png:pixmap
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	josef@FreeBSD.org
COMMENT=	A dockapp which provides a drawer to launch applications

USE_REINPLACE=	yes
USE_GETOPT_LONG=yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12 gdkpixbuf
USE_GMAKE=	yes
CONFIGURE_ENV+=	DOCSDIR=${DOCSDIR}
MAKE_ENV+=	${CONFIGURE_ENV}

MANCOMPRESSED=	yes
MAN1=	wmdrawer.1x

post-patch:
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR},g" ${WRKSRC}/wmdrawerrc.example
	@${REINPLACE_CMD} -e "s,CFLAGS = -O3,CFLAGS +=,g; \
		s,LDFLAGS =,LDFLAGS+=,g; s,PREFIX =,#PREFIX =,g; \
		s,$$[(]DESTDIR[)]/usr/local,${PREFIX},g; \
		s,CC =,#CC =,g; \
		s,/usr/X11R6,${X11BASE},g" ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/daemon.png ${DATADIR}

.include <bsd.port.mk>
