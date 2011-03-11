# New ports collection makefile for:	buttonbox
# Date created:				2000-12-17
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	buttonbox
PORTVERSION=	0.03
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor
DISTNAME=	${PORTNAME:S/b/B/g}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xlib-based application launcher

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

DOCDIR=		share/doc/${PORTNAME}
DOCS=		COPYING ChangeLog DEDICATION README TODO
PLIST=		${WRKDIR}/pkg-plist

USE_XORG=	x11 xext

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o buttonbox -L${LOCALBASE}/lib \
		-I${LOCALBASE}/include -lX11 -lXext button.c configuration.c \
		colour.c dispatcher.c main.c

pre-install:
	${ECHO_CMD} bin/buttonbox > ${PLIST}
	${ECHO_CMD} lib/X11/app-defaults/ButtonBox.ad >> ${PLIST}

.if !defined(NOPORTDOCS)
	for i in ${DOCS}; \
		do ${ECHO_CMD} ${DOCDIR}/$${i} >> ${PLIST}; \
	done
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/ButtonBox.ad ${LOCALBASE}/lib/X11/app-defaults/
	${INSTALL_PROGRAM} ${WRKSRC}/buttonbox ${LOCALBASE}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	for i in ${DOCS}; \
		do ${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${DOCDIR}; \
	done
.endif

.include <bsd.port.mk>
