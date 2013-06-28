# Created by: shanee@augusta.de
# $FreeBSD$

PORTNAME=	bricons
PORTVERSION=	3.0
DISTVERSIONPREFIX=	athena-
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB/../R5contrib
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quick start up utility for applications on an X display

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		imake
USE_PERL5_BUILD=yes
USE_XORG=	xaw
MAKE_JOBS_SAFE=	yes

MAN1=		bricons.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/Xbricons
	@${REINPLACE_CMD} -e \
		's|^unsigned int argc|int argc|' ${WRKSRC}/main.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xbricons ${PREFIX}/lib/X11/app-defaults
	${MKDIR} ${PREFIX}/include/X11/bitmaps
	${INSTALL_DATA} ${WRKSRC}/bitmaps/* ${PREFIX}/include/X11/bitmaps
	${MKDIR} ${PREFIX}/include/X11/pixmaps
	${INSTALL_DATA} ${WRKSRC}/*.xpm ${PREFIX}/include/X11/pixmaps
	@${ECHO_MSG} ""
	@${ECHO_MSG} "     Use ./files/DOTbriconsrc as an example. This  file"
	@${ECHO_MSG} "     should  be  stored in the same directory as the"
	@${ECHO_MSG} "     program is executed from."
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
