# New ports collection makefile for:   decurs
# Date created:		19 January 2002
# Whom:			Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	decurs
PORTVERSION=	0.50.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.hut.fi/~pvsavola/files/

MAINTAINER=	adamw@FreeBSD.org

PORTCOMMENT=	A GTK+ based program that lets you edit you XFree86 mouse cursors

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/decurs ${X11BASE}/bin/decurs-real
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/cursor.bdf ${DATADIR}
	${SED} -e "s|%%DECURS_DIR%%|${DATADIR}|; s|%%PREFIX%%|${PREFIX}|" \
		${FILESDIR}/decurs.exec > ${WRKSRC}/decurs.exec
	${INSTALL_SCRIPT} ${WRKSRC}/decurs.exec ${X11BASE}/bin/decurs

.include <bsd.port.mk>
