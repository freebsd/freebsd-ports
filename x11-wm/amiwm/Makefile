# Created by: Douglas Carmichael <dcarmich@mcs.com>
# $FreeBSD$

PORTNAME=	amiwm
PORTVERSION=	0.21.pl2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/X11/wm/amiwm/
DISTNAME=	${PORTNAME}0.21pl2

MAINTAINER=	dcarmich@dcarmichael.net
COMMENT=	Window manager that makes your desktop look like an Amiga(TM)

MAKE_JOBS_UNSAFE=	yes
GNU_CONFIGURE=	yes
USE_XORG=	x11 ice sm xext xmu
MAN1=		amiwm.1

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Copying documents to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	@${INSTALL_DATA} ${WRKSRC}/README.modules ${DOCSDIR}/README.modules
.endif

.include <bsd.port.mk>
