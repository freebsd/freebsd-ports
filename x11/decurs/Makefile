# New ports collection makefile for:   decurs
# Date created:		19 January 2002
# Whom:			Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	decurs
PORTVERSION=	0.55.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://varg.dyndns.org/psi/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ based program that lets you edit you XFree86 mouse cursors

LIB_DEPENDS=	gtkmm-2.0.6:${PORTSDIR}/x11-toolkits/gtk--2

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget gtk20
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

post-patch:
	@${SED} -e 's:%%PREFIX%%:${PREFIX}:g' \
		${FILESDIR}/decurs.exec > ${WRKSRC}/decurs.exec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/decurs ${PREFIX}/bin/decurs.bin
	${INSTALL_SCRIPT} ${WRKSRC}/decurs.exec ${PREFIX}/bin/decurs
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/*.bdf ${DATADIR}

.include <bsd.port.post.mk>
