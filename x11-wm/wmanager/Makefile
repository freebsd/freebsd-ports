# New ports collection makefile for:	wmanager
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	wmanager
PORTVERSION=	0.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://kassandra.techfak.uni-bielefeld.de/mtessmer/wmanager/
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk/

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_QT_VER=	1
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmanager ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/.wmanagerrc \
		${PREFIX}/share/examples/${PORTNAME}/wmanagerrc_sample
	@${INSTALL_DATA} ${WRKSRC}/.xinitrc \
		${PREFIX}/share/examples/${PORTNAME}/xinitrc_sample
.for file in FAQ HISTORY INSTALL NEWS README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${ECHO} ""
	@${ECHO} "Examples of .xinitrc and .wmanagerrc have been installed"
	@${ECHO} "in ${PREFIX}/share/examples/${PORTNAME} and docs have"
	@${ECHO} "been installed to ${DOCSDIR}."
	@${ECHO} ""
.endif

.include <bsd.port.mk>
