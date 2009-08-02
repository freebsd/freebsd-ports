# New ports collection makefile for:	neXtaw
# Date created:		16 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	neXtaw
PORTVERSION=	0.15.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://siag.nu/pub/neXtaw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Athena Widgets with N*XTSTEP appearance

USE_AUTOTOOLS=	libtool:22
USE_XORG=	xmu x11 xext
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|version-info.*$$|version-info ${XAWVER}:0:0|g' \
		${WRKSRC}/X11/neXtaw/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/CHANGES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DOCSDIR}
.endif

.include <bsd.port.mk>
