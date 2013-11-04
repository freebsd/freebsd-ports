# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	fbpanel
PORTVERSION=	6.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	SF
EXTRACT_SUFX=	.tbz2

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Lightweight, NEtWM compliant X11 desktop panel

LICENSE=	MIT

USE_BZIP2=	yes
USES=		gmake pkgconfig
USE_GNOME=	gtk20
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PORTDOCS=	CHANGELOG CREDITS NOTES README

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="${PORTNAME}" "${PORTNAME} NETWM compliant X11 desktop panel" \
		"${PORTNAME}" "${PORTNAME}" "System;" false

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/scripts/install.sh
	@${REINPLACE_CMD} -e 's|@DATADIR@|${DATADIR}|' \
		${WRKSRC}/data/man/${PORTNAME}.1.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/data/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${LN} -sf ${DATADIR}/images/logo.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
