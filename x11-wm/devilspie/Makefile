# New ports collection makefile for:	Devil's Pie
# Date created:			08 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	devilspie
PORTVERSION=	0.17.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.burtonini.com/computing/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A window manipulation tool

USE_X_PREFIX=	yes
USE_GNOME=	libwnck
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		devilspie.1
PORTDOCS=	AUTHORS NEWS README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||' \
		${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
