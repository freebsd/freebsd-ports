# New ports collection makefile for:	bricons
# Date created:		31 Jul 1996
# Whom:			shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	bricons
PORTVERSION=	3.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	-athena-3.0.tar.Z

MAINTAINER=	shanee@augusta.de
COMMENT=	Quick start up utility for applications on an X display

USE_IMAKE=	yes
USE_PERL5_BUILD=yes
USE_XPM=	yes
MAN1=		bricons.1

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/Xbricons

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xbricons ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/bitmaps/* ${PREFIX}/include/X11/bitmaps
	${INSTALL_DATA} ${WRKSRC}/*.xpm ${PREFIX}/include/X11/pixmaps
	@${ECHO_MSG} ""
	@${ECHO_MSG} "     Use ./files/DOTbriconsrc as an example. This  file"
	@${ECHO_MSG} "     should  be  stored in the same directory as the"
	@${ECHO_MSG} "     program is executed from."
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
