# New ports collection makefile for:	wmanager
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	wmanager
PORTVERSION=	0.2.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://kassandra.techfak.uni-bielefeld.de/mtessmer/wmanager/
EXTRACT_SUFX=	-src.tar.bz2

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmanager ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in FAQ HISTORY INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/.wmanagerrc ${EXAMPLESDIR}/wmanagerrc_sample
	${INSTALL_DATA} ${WRKSRC}/.xinitrc ${EXAMPLESDIR}/xinitrc_sample
.endif

.include <bsd.port.mk>
