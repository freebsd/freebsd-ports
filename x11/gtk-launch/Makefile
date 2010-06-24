# New ports collection makefile for:	gtk-launch
# Date created:				22 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	gtk-launch
DISTVERSION=	1.1b
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://pierric.descamps.free.fr/pierric/downloads/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A fast GTK+ program launcher

USE_GNOME=	gtk12
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/gtk-launch
PORTDOCS=	INSTALL

PORTSCOUT=	skipv:1.1

post-patch:
	${ECHO_CMD} >> ${WRKSRC}/launch.c

do-build:
	${CC} ${CFLAGS} `${GTK_CONFIG} --cflags --libs` \
		-o ${WRKSRC}/${PORTNAME} ${WRKSRC}/launch.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
