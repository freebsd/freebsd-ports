# ex:ts=8
# Ports collection makefile for:	peeper
# Date created:			Aug 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	peeper
PORTVERSION=	0.1
CATEGORIES=	x11
MASTER_SITES=	http://peeper.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12 imlib
USE_GMAKE=	yes
ALL_TARGET=	peeper
MAKE_ENV=	LIBS="-L${LOCALBASE}/lib -lpng -ljpeg -lungif -ltiff"

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" -e "s|CFLAGS=|CFLAGS+=|g" \
		-e "s|gtk-config|${GTK_CONFIG}|g" -e "s|-ldl||g" \
		-e "s|LIBS=|LIBS+=|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/peeper ${PREFIX}/bin

.include <bsd.port.mk>
