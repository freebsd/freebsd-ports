# New ports collection makefile for:	9box
# Date created:		Fri Mar 21 10:10:48 EST 2003
# Whom:			Serge Gagnon <gagnon__s@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	9box
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://freesoftware.fsf.org/download/9box/ \
		http://savannah.nongnu.org/download/9box/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	9box can "pack" windows inside itself

PLIST_FILES=	bin/9box
USE_REINPLACE=	yes
USE_XLIB=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes

BUILD_WRKSRC=	${WRKSRC}/src

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/9box ${PREFIX}/bin

.include <bsd.port.mk>
