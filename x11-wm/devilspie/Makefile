# New ports collection makefile for:	Devil's Pie
# Date created:			08 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	devilspie
PORTVERSION=	0.10
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.burtonini.com/computing/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A window manipulation tool

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_X_PREFIX=	yes
USE_GNOME=	libwnck libxml2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		devilspie.1

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/devilspie.dtd ${DATADIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-config.xml ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/NEWS \
		${WRKSRC}/README \
		${WRKSRC}/TODO \
		${WRKSRC}/devilspie-reference.html \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
