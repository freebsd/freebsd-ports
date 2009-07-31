# New ports collection makefile for:	wmanager
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	wmanager
PORTVERSION=	0.2.1
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	roam@FreeBSD.org
COMMENT=	X11 window manager selector

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PKGMESSAGE=	${WRKDIR}/pkg-message

USE_XORG=	x11 xext
USE_GL=		gl
USE_GMAKE=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

OPTIONS=	ADDONS "Install the helper scripts and manpages" on

.include <bsd.port.pre.mk>

.if defined(WITH_ADDONS)
RUN_DEPENDS+=	wmanager-loop:${PORTSDIR}/x11-wm/wmanager-addons
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmanager ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${SED} -e "s@%%DOCSDIR%%@${DOCSDIR}@; s@%%EXAMPLESDIR%%@${EXAMPLESDIR}@" ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${MKDIR} ${DOCSDIR}
.for file in FAQ HISTORY INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/.wmanagerrc ${EXAMPLESDIR}/wmanagerrc_sample
	${INSTALL_DATA} ${WRKSRC}/.xinitrc ${EXAMPLESDIR}/xinitrc_sample
.else
	${RM} -f ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
