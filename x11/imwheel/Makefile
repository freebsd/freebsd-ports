# New ports collection makefile for: imwheel-0.9.7
# Date created:		18 Feb 2000
# Whom:			jhb
#
# $FreeBSD$
#

PORTNAME=	imwheel
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://jcatki.no-ip.org/pub/imwheel/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

DEPRECATED=	http://vuxml.freebsd.org/e31d44a2-21e3-11d9-9289-000c41e2cdad.html (vulnerabilty)
EXPIRATION_DATE= November 20, 2004

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to translate mouse wheel actions into X keyboard events

USE_REINPLACE=	yes
USE_GMAKE=	YES
USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-gpm

MAN1=		imwheel.1

post-patch:
.for i in imwheel.1 util.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${i}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/imwheel
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/EMACS \
		 ${PREFIX}/share/doc/imwheel
.endif

.include <bsd.port.mk>
