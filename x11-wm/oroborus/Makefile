PORTNAME=	oroborus
PORTVERSION=	2.0.20
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	DEBIAN/pool/main/o/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	matt@peterson.org
COMMENT=	Small and simple GNOME-compatible window manager
WWW=		https://www.oroborus.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg
USE_XORG=	ice sm x11 xext xpm

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	AUTHORS ChangeLog README TODO

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/example.oroborusrc \
		${STAGEDIR}${ETCDIR}rc.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
